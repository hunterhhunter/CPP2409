#include <iostream>
using namespace std;

int main() {
    int userInput;

    cout << "정수를 10번 입력하세요 (0을 입력하면 종료)";
    int i = 0;

    for(int i=0;i<10;i++) { // for구문으로 10번 반복하도록
        cin >> userInput;
        if (userInput == 0) // 0이 입력되면 탈출하도록
            break;

        cout << "입력값: " << userInput << " 횟수: " << i+1 << endl;
    }
    
    cout << "종료 되었습니다.";

    return 0;
}