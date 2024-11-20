#include <iostream>
#include <string>
#include <cstdlib>
#include "user.h"
#include <vector>
#include "Magician.h"
#include "Warrior.h"

using namespace std;

const int mapX = 5;
const int mapY = 5;

// 사용자 정의 함수
void displayMap(vector<vector<int>> map, vector<pair<int, int>> user_positions);
bool checkState(vector<vector<int>> map, User *user);
bool action(string action, vector<vector<int>> map, User *user, vector<pair<int, int>> user_positions, bool turn);

// 메인  함수
int main()
{
	// 0은 빈 공간, 1은 아이템, 2는 적, 3은 포션, 4는 목적지
	vector<vector<int>> map;
	map = {{0, 1, 2, 0, 4},
		   {1, 0, 0, 2, 0},
		   {0, 0, 0, 0, 0},
		   {0, 2, 3, 0, 0},
		   {3, 0, 0, 0, 2}};

	// 턴개념 구현
	bool turn = false;

	// 유저의 위치를 저장할 변수
	int user_x = 0; // 가로 번호
	int user_y = 0; // 세로 번호

	// 플레이어 선언
	Magician magician_user = Magician{};
	Warrior warrior_user = Warrior{};

	// 게임 시작
	while (1)
	{ // 사용자에게 계속 입력받기 위해 무한 루프
		User *user;

		// 텀개념 구현
		if (turn)
		{
			user = &magician_user;
			cout << "현재 턴: 마법사" << endl;
		}	
		else
		{
			user = &warrior_user;
			cout << "현재 턴: 전사" << endl;
		}


		// 사용자의 입력을 저장할 변수
		string user_input = "";

		cout << "  명령어를 입력하세요 (상,하,좌,우,지도,정보,종료): ";
		cin >> user_input;

		if (user_input == "종료")
		{
			// 프로그램 종료
			cout << "종료합니다.";
			break;
		}
		else
		{
			vector<pair<int, int>> user_position;
			user_position.push_back(magician_user.GetXY());
			user_position.push_back(warrior_user.GetXY());

			bool isAction = action(user_input, map, user, user_position, turn);
			if (!isAction)
				continue;
		}

		// checkGoal함수에서 checkState로 변경함으로써
		// 상호작용과 도착을 따로 확인하지 않고 한 번에 호출
		bool finish = checkState(map, user);
		if (finish == true)
		{
			cout << "목적지에 도착했습니다! 축하합니다!" << endl;
			cout << "게임을 종료합니다." << endl;
			break;
		}

		// 체력의 하락으로 종료
		if (user->GetHP() <= 0)
		{
			cout << "체력이 다 떨어졌습니다. 실패...." << endl;
			break;
		}
		turn = !turn;
	}
	system("pause");
	return 0;
}

// 지도와 사용자 위치 출력하는 함수
void displayMap(vector<vector<int>> map, vector<pair<int, int>> user_positions) {
    for (int i = 0; i < mapY; i++) {
        for (int j = 0; j < mapX; j++) {
            bool user_here = false; // 유저가 있는지 확인

            // 유저 위치 체크
            if (user_positions[0] == make_pair(j, i) && user_positions[1] == make_pair(j, i)) {
                // 마법사와 전사가 같은 위치
                cout << "마+전 |";
                user_here = true;
            } else if (user_positions[0] == make_pair(j, i)) {
                // 마법사 위치
                cout << "마법사|";
                user_here = true;
            } else if (user_positions[1] == make_pair(j, i)) {
                // 전사 위치
                cout << " 전사 |";
                user_here = true;
            }

            // 유저가 없는 경우 지도 출력
            if (!user_here) {
                switch (map[i][j]) {
                    case 0:
                        cout << "      |"; // 6칸 공백
                        break;
                    case 1:
                        cout << "아이템|";
                        break;
                    case 2:
                        cout << "  적  |";
                        break;
                    case 3:
                        cout << " 포션 |";
                        break;
                    case 4:
                        cout << "목적지|";
                        break;
                }
            }
        }
        cout << "\n";
        cout << " -------------------------------- " << endl;
    }
}

// 유저 위치의 타일이 특수한 타일인지 확인하고 상호작용하는 함수
bool checkState(vector<vector<int>> map, User *user)
{
	pair<int, int> uxy = user->GetXY();
	switch (map[uxy.second][uxy.first])
	{
	case 1:
		// 무기/갑옷을 발견
		cout << "아이템을 발견했다! 의외의 행운이 따르는군?" << endl;
		user->IncreaseItemCnt();
		return false;
	case 2:
		// 적을 조우
		cout << "적을 맞닥뜨렸다..! 무찌르자!" << endl;
		cout << "적을 쓰려뜨렸지만 HP를 2 잃었다.: " << user->GetHP() << " -> " << user->GetHP() - 2 << endl;
		user->DoAttack();
		user->DecreaseHP(2);
		return false;
	case 3:
		// 포션을 발견
		cout << "포션! 의외로 맛있는걸??" << endl;
		cout << "HP가 2 회복되었다.: " << user->GetHP() << " -> " << user->GetHP() + 2 << endl;
		user->IncreaseHP(2);
		return false;
	case 4:
		// 타일의 값이 4인 경우 도착한 것이므로 true를 return해서 게임을 종료
		return true;
	default:
		return false;
	}
}

bool action(string action, vector<vector<int>> map, User *user, vector<pair<int, int>> user_positions, bool turn)
{
	// 상, 하, 좌, 우 이동과 지도 출력, 입력값 검증을 하는 함수
	// 포인터들로 실질적 값의 변경이 가능
	if (action == "상")
	{
		// 위로 한 칸 올라가기
		bool isMoved = user->Move(0, -1, mapX, mapY);
		if (isMoved)
		{
			if (turn)
				user_positions[0] = user->GetXY();
			else
				user_positions[1] = user->GetXY();

			cout << "위로 한 칸 올라갑니다." << endl;
			displayMap(map, user_positions);
			cout << "너무 어두워서 이동하기가 어렵다. HP: " << user->GetHP() + 1 << " -> " << user->GetHP() << endl;
			return true;
		}
		else
		{
			return false;
		}
	}
	else if (action == "하")
	{
		// TODO: 아래로 한 칸 내려가기
		bool isMoved = user->Move(0, 1, mapX, mapY);
		if (isMoved)
		{
			if (turn)
				user_positions[0] = user->GetXY();
			else
				user_positions[1] = user->GetXY();

			cout << "아래로 한 칸 내려갑니다." << endl;
			displayMap(map, user_positions);
			cout << "너무 어두워서 이동하기가 어렵다. HP: " << user->GetHP() + 1 << " -> " << user->GetHP() << endl;
			return true;
		}
		else
		{
			return false;
		}
	}
	else if (action == "좌")
	{
		// TODO: 왼쪽으로 이동하기
		bool isMoved = user->Move(-1, 0, mapX, mapY);
		if (isMoved)
		{
			if (turn)
				user_positions[0] = user->GetXY();
			else
				user_positions[1] = user->GetXY();

			cout << "왼쪽으로 한 칸 이동합니다." << endl;
			displayMap(map, user_positions);
			cout << "너무 어두워서 이동하기가 어렵다. HP: " << user->GetHP() + 1 << " -> " << user->GetHP() << endl;
			return true;
		}
		else
		{
			return false;
		}
	}
	else if (action == "우")
	{
		// TODO: 오른쪽으로 이동하기
		bool isMoved = user->Move(1, 0, mapX, mapY);
		if (isMoved)
		{
			if (turn)
				user_positions[0] = user->GetXY();
			else
				user_positions[1] = user->GetXY();

			cout << "오른쪽으로 한 칸 이동합니다." << endl;
			displayMap(map, user_positions);
			cout << "너무 어두워서 이동하기가 어렵다. HP: " << user->GetHP() + 1 << " -> " << user->GetHP() << endl;
			return true;
		}
		else
		{
			return false;
		}
	}
	else if (action == "지도")
	{
		// TODO: 지도 보여주기 함수 호출
		displayMap(map, user_positions);
	}
	else if (action == "정보")
	{
		cout << *user << endl;
	}
	else
	{
		cout << "잘못된 입력입니다." << endl;
		return false;
	}
	return true;
}
