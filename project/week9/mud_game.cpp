#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

const int mapX = 5;
const int mapY = 5;

// 사용자 정의 함수
bool checkXY(int *user_x, int *user_y);
void displayMap(int map[][mapX], int *user_x, int *user_y);
bool checkState(int map[][mapX], int *user_x, int *user_y, int *userHP);
bool move(int dx, int dy, int *user_x, int *user_y, int *userHP, int map[][mapX]);
bool action(string action, int map[mapY][mapX], int *user_x, int *user_y, int *userHP);

// 메인  함수
int main() {
	// 0은 빈 공간, 1은 아이템, 2는 적, 3은 포션, 4는 목적지
	int map[mapY][mapX] = { {0, 1, 2, 0, 4},
					{1, 0, 0, 2, 0},
					{0, 0, 0, 0, 0},
					{0, 2, 3, 0, 0},
					{3, 0, 0, 0, 2} };


	// 유저의 위치를 저장할 변수
	int user_x = 0; // 가로 번호
	int user_y = 0; // 세로 번호
    // 유저의 체력 선언
    int userHP = 20;

	// 게임 시작 
	while (1) { // 사용자에게 계속 입력받기 위해 무한 루프

		// 사용자의 입력을 저장할 변수
		string user_input = "";

		cout << "현재 HP: " << userHP <<"  명령어를 입력하세요 (상,하,좌,우,지도,종료): ";
		cin >> user_input;

		if (user_input == "종료") {
            // 프로그램 종료
			cout << "종료합니다.";
			break;
		} else {
			bool isAction = action(user_input, map, &user_x, &user_y, &userHP);
            if (!isAction)
                continue;
		}

		// checkGoal함수에서 checkState로 변경함으로써
		// 상호작용과 도착을 따로 확인하지 않고 한 번에 호출
		bool finish = checkState(map, &user_x, &user_y, &userHP);
		if (finish == true) {
			cout << "목적지에 도착했습니다! 축하합니다!" << endl;
			cout << "게임을 종료합니다." << endl;
			break;
		}

		// 체력의 하락으로 종료
		if (userHP <= 0) {
			cout << "체력이 다 떨어졌습니다. 실패...." << endl;
			break;
		}
	}
	system("pause");
	return 0;
}


// 지도와 사용자 위치 출력하는 함수
void displayMap(int map[][mapX], int *user_x, int *user_y) {
	for (int i = 0; i < mapY; i++) {
		for (int j = 0; j < mapX; j++) {
			if (i == *user_y && j == *user_x) {
				cout << " USER |"; // 양 옆 1칸 공백
			}
			else {
				int posState = map[i][j];
				switch (posState) {
				case 0:
					cout << "      |"; // 6칸 공백
					break;
				case 1:
					cout << "아이템|";
					break;
				case 2:
					cout << "  적  |"; // 양 옆 2칸 공백
					break;
				case 3:
					cout << " 포션 |"; // 양 옆 1칸 공백
					break;
				case 4:
					cout << "목적지|";
					break;
				}
			}
		}
		cout << endl;
		cout << " -------------------------------- " << endl;
	}
}

// 이동하려는 곳이 유효한 좌표인지 체크하는 함수
bool checkXY(int *user_x, int *user_y) {
	bool checkFlag = false;
	if (*user_x >= 0 && *user_x < mapX && *user_y >= 0 && *user_y < mapY) {
		checkFlag = true;
	}
	return checkFlag;
}

// 유저 위치의 타일이 특수한 타일인지 확인하고 상호작용하는 함수
bool checkState(int map[][mapX], int *user_x, int *user_y, int *userHP) {
	switch (map[*user_y][*user_x])
	{
	case 1:
		// 무기/갑옷을 발견
		cout << "아이템을 발견했다! 의외의 행운이 따르는군?" << endl;
		return false;
	case 2:
		// 적을 조우
		cout << "적을 맞닥뜨렸다..! 무찌르자!" << endl;
		cout << "적을 쓰려뜨렸지만 HP를 2 잃었다.: " << *userHP << " -> " << *userHP-2 << endl;
		*userHP -= 2;
		return false;
	case 3:
		// 포션을 발견
		cout << "포션! 의외로 맛있는걸??" << endl;
		cout << "HP가 2 회복되었다.: " << *userHP << " -> " << *userHP+2 << endl;
		*userHP += 2;
		return false;
	case 4:
		// 타일의 값이 4인 경우 도착한 것이므로 true를 return해서 게임을 종료
		return true;
	default:
		return false;
	}
}

bool move(int dx, int dy, int *user_x, int *user_y, int *userHP, int map[][mapX]) {
	// 이동만을 담당하는 함수 dx, dy만큼 검증하여 이동하는 함수
	*user_x += dx;
	*user_y += dy;
	if (!checkXY(user_x, user_y)) {
		cout << "맵을 벗어났습니다. 다시 돌아갑니다." << endl;
		*user_x -= dx;
		*user_y -= dy;
		return false;
	}
	*userHP -= 1;
	return true;
}

bool action(string action, int map[][mapX], int *user_x, int *user_y, int *userHP) {
	// 상, 하, 좌, 우 이동과 지도 출력, 입력값 검증을 하는 함수
	// 포인터들로 실질적 값의 변경이 가능
    if (action == "상") {
		// 위로 한 칸 올라가기
		bool isMoved = move(0, -1, user_x, user_y, userHP, map);
		if (isMoved) {
			cout << "위로 한 칸 올라갑니다." << endl;
			displayMap(map, user_x, user_y);
			cout << "너무 어두워서 이동하기가 어렵다. HP: " << *userHP+1 << " -> " << *userHP << endl;
			return true;
		} else {
			return false;
		}
	}
	else if (action == "하") {
		// TODO: 아래로 한 칸 내려가기
		bool isMoved = move(0, 1, user_x, user_y, userHP, map);
		if (isMoved) {
			cout << "아래로 한 칸 내려갑니다." << endl;
			displayMap(map, user_x, user_y);
			cout << "너무 어두워서 이동하기가 어렵다. HP: " << *userHP+1 << " -> " << *userHP << endl;
			return true;
		} else {
			return false;
		}
	}
	else if (action == "좌") {
		// TODO: 왼쪽으로 이동하기
		bool isMoved = move(-1, 0, user_x, user_y, userHP, map);
		if (isMoved) {
			cout << "왼쪽으로 한 칸 이동합니다." << endl;
			displayMap(map, user_x, user_y);
			cout << "너무 어두워서 이동하기가 어렵다. HP: " << *userHP+1 << " -> " << *userHP << endl;
			return true;
		} else {
			return false;
		}
	}
	else if (action == "우") {
		// TODO: 오른쪽으로 이동하기
		bool isMoved = move(1, 0, user_x, user_y, userHP, map);
		if (isMoved) {
			cout << "오른쪽으로 한 칸 이동합니다." << endl;
			displayMap(map, user_x, user_y);
			cout << "너무 어두워서 이동하기가 어렵다. HP: " << *userHP+1 << " -> " << *userHP << endl;
			return true;
		} else {
			return false;
		}
	}
	else if (action == "지도") {
		// TODO: 지도 보여주기 함수 호출
		displayMap(map, user_x, user_y);
	}
	else {
		cout << "잘못된 입력입니다." << endl;
		return false;
	}
    return true;
}
