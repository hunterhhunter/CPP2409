#include<time.h>
#include<iostream>
using namespace std;

int main() {
    int i; // 유저의 입력값
    int ans; // 정답
    cout << "산수 문제를 자동으로 출제합니다. " << endl;

    while (true)
    {
        srand(time(NULL)); // 랜덤이 매번 다르도록 설정
        int firstNum = rand()%100;
        int secondNum = rand()%100;
        ans = firstNum + secondNum;

        cout << firstNum << " + " << secondNum << " = "; // 문제 출력
        cin >> i;

        if (i == ans) {
            cout << "맞았습니다." << endl;
            break;
        } else {
            cout << "틀렸습니다." << endl;
        }
    }
    
    return 0;
}