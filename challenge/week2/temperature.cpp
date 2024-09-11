#include <iostream>

using namespace std;

int main() {
    int tmp;                // 화씨 온도 선언
    cout << "화씨 온도: ";
    cin >> tmp;             // 화씨 온도 입력
    // 연산 결과를 바로 출력
    cout << "섭씨온도 = " << (5.0 / 9.0) * (tmp - 32) << endl;
}