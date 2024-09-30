#include <iostream>
#include <string>

using namespace std;

int main() {
    const int MAXPEOPLE = 5;
    string people[MAXPEOPLE];
    int age[MAXPEOPLE];
    
    cout << MAXPEOPLE << "명의 회원 정보를 입력해주세요." << endl;

    for (int i = 0; i < MAXPEOPLE;i++) {
        cout << "사람 " << i+1 << "의 이름: ";
        cin >> people[i];
        cout << "사람 " << i+1 << "의 나이: ";
        cin >> age[i];
    }

    int inp;

    while (true)
    {
        cout << "메뉴 중에서 골라 선택해주세요: \n1. 가장 나이가 많은 사람 찾기\n2. 가장 나이가 적은 사람 찾기\n3. 종료\n 입력: ";
        cin >> inp;
        if (inp == 3)
            break;
        int lst[MAXPEOPLE] = {0, 0, 0, 0, 0}; // 같은 값 참조를 위한 배열
        int tmp;
        if (inp == 1) {
            tmp = age[0];
            for (int i=0; i<MAXPEOPLE;i++) {
                if (tmp < age[i]){
                    for (int i=0;i<MAXPEOPLE;i++) // 배열 참조 문제로 반복문으로 초기화
                        lst[i] = 0;
                    lst[i] = 1;
                    tmp = age[i];
                } else if (tmp == age[i]) {
                    lst[i] = 1;
                }
            }
            cout << "나이가 가장 많은 사람은 ";
            for (int i=0;i<MAXPEOPLE;i++) {
                if (lst[i] == 1)
                    cout << people[i] << " (" << age[i] << "세) "; 
            }
            cout << endl;
        } else if (inp == 2) {
            tmp = age[0];
            for (int i=0; i<MAXPEOPLE;i++) {
                if (tmp > age[i]){
                    for (int i=0;i<MAXPEOPLE;i++)
                        lst[i] = 0;
                    lst[i] = 1;
                    tmp = age[i];
                } else if (tmp == age[i]) {
                    lst[i] = 1;
                }
            }
            cout << "나이가 가장 적은 사람은 ";
            for (int i=0;i<MAXPEOPLE;i++) {
                if (lst[i] == 1)
                    cout << people[i] << " (" << age[i] << "세) "; 
            }
            cout << endl;
        } else {
            break;
        }
    }
    return 0;
}