#include <iostream>
using namespace std;

#define SIZEOFBOARD 3

int main() {
    char board[SIZEOFBOARD][SIZEOFBOARD]{}; // 보드 선언
    int x, y; // 사용자 좌표 입력을 위한 변수 선언
    // 턴 개념 정의: int%2 -> bool 2명의 플레이어의 턴 상태를 나타내기 위해서 int를 선언하는 것은
    // 메모리상 비효율적이다. 그렇기에 bool 변수를 선언하여 턴 상태를 표현한다.
    bool turn = false; // 턴 개념 정의를 위한 변수 선언 (false시 1번 플레이어)
    char currentPlayerStone; // 현재 유저의 돌 상태 변수
    short check, check2 = 0; // 빙고 체크를 위한 short 변수

    // 게임 시작 전 보드 초기화
    for (int i=0; i < SIZEOFBOARD; i++)
        for (int j=0; j < SIZEOFBOARD; j++)
            board[i][j] = ' ';

    while (true) {
        // 턴 시작 전 초기화
        check, check2 = 0;

        // 턴 개념 구현
        if (!turn) {
            cout << "첫번째 플레이어(X)의 차례입니다 -> ";
            currentPlayerStone = 'X';
        } else {
            cout << "두번째 플레이어(O)의 차례입니다 -> ";
            currentPlayerStone = 'O';
        }

        // 좌표 입력 받기
        cout << "(x, y) 좌표를 space를 기준으로 분할하여 입력하세요(시작: 0, 0) : ";
        cin >> x >> y;

        // 좌표 유효성 체크
        // 1. board의 범위 체크
        if (x >= SIZEOFBOARD || y >= SIZEOFBOARD || x < 0 || y < 0) {
            cout << x << " " << y << ": ";
            cout << "x와 y중 보드의 범위를 벗어났습니다." << endl;
            continue;
        }
        // 2. 중복 검사
        if (board[x][y] != ' ') {
            cout << x << ", " << y <<" 좌표는 이미 돌이 차있습니다." << endl;
            continue;
        }

        // 유저의 돌 놓기
        board[x][y] = currentPlayerStone;

        // 보드판 출력
        for (int i=0; i < SIZEOFBOARD; i++) {
            cout << "|---|---|---|" << endl;
            cout << "|";
            for (int j=0; j<SIZEOFBOARD; j++) {
                cout << " " << board[i][j] << " |";
            }
            cout << endl;
        }
        cout << "|---|---|---|" << endl;

        // 빙고 체크
        // 1. 가로 체크
        for (int i=0; i<SIZEOFBOARD;i++) {
            check = 0;
            for (char stone : board[i]) {
                if (stone == currentPlayerStone)
                    check++;
            }
            // 가로로 빙고인 경우
            if (check == 3) {
                if (currentPlayerStone == 'X') {
                    cout << "첫번째 플레이어(X)가 " << i+1 << "번째 가로 선에 모두 돌을 놓았습니다. 승리했습니다.";
                    return 0;
                } else { 
                    cout << "두번째 플레이어(O)가 " << i+1 << "번째 가로 선에 모두 돌을 놓았습니다. 승리했습니다.";
                    return 0;
                }
            }
        }
        // 2. 세로 체크
        for (int i=0; i<SIZEOFBOARD; i++) {
            check = 0;
            for (int j=0; j<SIZEOFBOARD; j++) {
                if (board[j][i] == currentPlayerStone)
                    check++;
            }
            // 세로로 빙고인 경우
            if (check == 3) {
                if (currentPlayerStone == 'X') {
                    cout << "첫번째 플레이어(X)가 " << i+1 << "번째 세로 선에 모두 돌을 놓았습니다. 승리했습니다.";
                    return 0;
                } else { 
                    cout << "두번째 플레이어(O)가 " << i+1 << "번째 세로 선에 모두 돌을 놓았습니다. 승리했습니다.";
                    return 0;
                }
            }
        }
        check = 0;
        // 3. 대각선 체크
        for (int i=0; i<SIZEOFBOARD; i++) {
            // check는 좌상단 -> 우하단 빙고, check2는 우상단 -> 좌하단 빙고
            if (board[i][i] == currentPlayerStone)
                check++;
            if (board[i][SIZEOFBOARD-1-i] == currentPlayerStone)
                check2++;
        }
        if (check == 3) {
            if (currentPlayerStone == 'X') {
                cout << "첫번째 플레이어(X)가 좌상단 -> 우하단 선에 모두 돌을 놓았습니다. 승리했습니다.";
                return 0;
            } else {
                cout << "두번째 플레이어(O)가 좌상단 -> 우하단 선에 모두 돌을 놓았습니다. 승리했습니다.";
                return 0;
            }
        }
        if (check2 == 3) {
            if (currentPlayerStone == 'X') {
                cout << "첫번째 플레이어(X)가 우상단 -> 좌하단 선에 모두 돌을 놓았습니다. 승리했습니다.";
                return 0;
            } else {
                cout << "두번째 플레이어(O)가 우상단 -> 좌하단 선에 모두 돌을 놓았습니다. 승리했습니다.";
                return 0;
            }
        }
        // 모든 칸이 찼는지 확인
        check = 0;
        for (int i=0; i<SIZEOFBOARD;i++)
            for (int j=0;j<SIZEOFBOARD;j++)
                if (board[i][j] != ' ')
                    check++;
        if (check == 9) {
            cout << "모든 칸이 다 찼습니다. 무승부로 게임을 종료합니다.";
            return 0;
        } else {
            // 턴 넘기기: bool을 보수화하면서 턴을 변경
            turn = !turn;
        }
    }
    return 0;
}