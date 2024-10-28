#include <iostream>
using namespace std;
const int numCell = 4;

bool isValid(int x, int y, char arr[numCell][numCell]) {
    // 보드를 입력받아 좌표의 유효성을 체크
    if (x >= numCell || y >= numCell) {// 좌표 범위를 벗어날때
        cout << x << "," << y << ": x와 y둘중 하나가 칸을 벗어납니다. " << endl;
        return false;
    }
    if (arr[x][y] != ' ') {// 좌표범위의 입력값이 중복될때
        cout << x << "," << y << ": 이미 돌이 차있습니다. " << endl;
        return false;
    }
    return true;
}

bool checkWin(char board[numCell][numCell], char currentPlayerStone) {
    // 빙고 체크
    int check, check2=0;
    // 1. 가로 체크
    for (int i=0; i<numCell;i++) {
        check = 0;
        for (int j=0; j<numCell; j++) {
            if (board[i][j] == currentPlayerStone)
                check++;
        }
        // 가로로 빙고인 경우
        if (check == numCell) {
            cout << "가로에 돌이 모두 놓였습니다!" << endl;
            return true;
        }
    }
    // 2. 세로 체크
    for (int i=0; i<numCell; i++) {
        check = 0;
        for (int j=0; j<numCell; j++) {
            if (board[j][i] == currentPlayerStone)
                check++;
        }
        // 세로로 빙고인 경우
        if (check == numCell) {
            cout << "세로로 돌이 모두 놓였습니다!" << endl;
            return true;
        }
    }
    check = 0;
    // 3. 대각선 체크
    for (int i=0; i<numCell; i++) {
        // check는 좌상단 -> 우하단 빙고, check2는 우상단 -> 좌하단 빙고
        if (board[i][i] == currentPlayerStone)
            check++;
        if (board[i][numCell-1-i] == currentPlayerStone)
            check2++;
    }
    if (check == numCell) {
        cout << "왼쪽 위에서 오른쪽 아래 대각선으로 모두 돌이 놓였습니다!" << endl;
        return true;
    }
    if (check2 == numCell) {
        cout << "오른쪽 위에서 왼쪽  아래 대각선으로 모두 돌이 놓였습니다!" << endl;
        return true;
    }

    return false;
}

int main() {
	// 게임을 진행하는 데 필요한 변수 선언

	int k = 0; // 누구 차례인지 체크하기 위한 변수
	char currentUser = 'X'; // 현재 유저의 돌을 저장하기 위한 변수
	char board[numCell][numCell]{}; // 보드판을 나타내는 2차원 배열
	int x, y = 0; // 사용자에게 xy좌표값을 입력받기 위한 변수

	// 보드판 초기화
	for (int i = 0; i < numCell; i++) {
		for (int j = 0; j < numCell; j++) {
			board[i][j] = ' ';
		}
	}

	// 게임을 무한 반복
	while (true) {
		// 1. 누구 차례인지 출력
		// TODO 1.1: 3인용 게임으로 변경
		switch (k % 3) {
		case 0:
			currentUser = 'X';
			break;
		case 1:			
			currentUser = 'O';
			break;
        case 2:
            currentUser = 'H';
            break;
		}
		cout << k % 3 + 1 << "번 유저("<< currentUser <<")의 차례입니다. -> ";

		// 2. 좌표 입력 받기
		cout << "(x, y) 좌표를 입력하세요: ";
		int x, y;
		cin >> x >> y;

		// 3. 입력받은 좌표의 유효성 체크
		// TODO FUNC 1: isValid 함수 생성 후 호출
		bool valid = isValid(x, y, board);

        if (!valid) {
            continue;
        }


		// 4. 입력받은 좌표에 현재 유저의 돌 놓기
		board[x][y] = currentUser;

		// 5. 현재 보드 판 출력
		// TODO 1.2: numCell 숫자에 맞춘 보드판 출력
		for (int i=0; i < numCell; i++) {
            for (int f=0;f<numCell;f++) {
                if (f == numCell-1) {
                    cout << "---" << endl;
                    break;
                }
                cout << "---|";
            }
            for (int j=0; j<numCell; j++) {
				if (j == numCell-1) {
					cout << " " << board[i][j];
					break;
				}
                cout << " " << board[i][j] << " |";
				
            }
            cout << endl;
        }
        for (int f=0;f<numCell;f++) {
            if (f == numCell -1) {
                cout << "---" << endl;
                break;
            }
            cout << "---|";
        }




		bool isWin = false; // 승리 여부
		// TODO FUNC2: 6.1부터 6.2까지 checkWin 함수 생성 후 호출
		// 6.1. 가로/세로 돌 체크하기
		// for (int i = 0; i < numCell; i++) {
		// 	if (board[i][0] == currentUser && board[i][1] == currentUser && board[i][2] == currentUser) {
		// 		cout << "가로에 모두 돌이 놓였습니다!!";
		// 		isWin = true;
		// 		break;
		// 	}
		// 	if (board[0][i] == currentUser && board[1][i] == currentUser && board[2][i] == currentUser) {
		// 		cout << "세로에 모두 돌이 놓였습니다!!";
		// 		isWin = true;
		// 		break;
		// 	}
		// }


		// // 6.2. 대각선을 체크하기
		// // TODO 1.3: numCell에 맞춘 대각선 빙고 체크 코드로 확장
		// // HINT: for 문
		// if (board[0][0] == currentUser && board[1][1] == currentUser && board[2][2] == currentUser) {
		// 	cout << "왼쪽 위에서 오른쪽 아래 대각선으로 모두 돌이 놓였습니다!" << endl;
		// 	isWin = true;			
		// }
		// if (board[0][2] == currentUser && board[1][1] == currentUser && board[2][0] == currentUser) {
		// 	cout << "오른쪽 위에서 왼쪽 아래 대각선으로 모두 돌이 놓였습니다!" << endl;
		// 	isWin = true;			
		// }

        isWin = checkWin(board, currentUser);

		// 승리자가 결정되었으면 해당 플레이어를 출력하고 게임을 종료한다.
		if (isWin == true) {
			cout << k % 3 + 1<< "번 유저(" << currentUser << ")의 승리입니다!" << endl;
			break;
		}

		// 7. 모든 칸 다 찼는지 체크하기
		int checked = 0;
		for (int i = 0; i < numCell; i++) {
			for (int j = 0; j < numCell; j++) {
				if (board[i][j] == ' ') {
					checked++;
				}
			}
		}
		if (checked == 0) {
			cout << "모든 칸이 다 찼습니다.  종료합니다. " << endl;
			break;
		}

		k++;
	}

	return 0;
}