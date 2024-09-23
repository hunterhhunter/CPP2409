#include <iostream>
using namespace std;

int main() {
    int a, b, c, largest;

    cout << "3개의 정수를 space를 기준 분리하여 입력하시오: "; // 입력 포맷 지정
    cin >> a >> b >> c;

    if (a == b && b == c) {
        cout << "세 개의 정수가 모두 " << a << "로 같습니다."; // 모두 같은 경우
    } else if (a == b && a>c) {
        cout << "a와 b는 " << a << "로 가장 큰 정수입니다." << endl;  // a, b가 같고 가장 큰 경우
    } else if (a == c && a > b) {
        cout << "a와 c는 " << a << "로 가장 큰 정수입니다." << endl;  // a, c가 같고 가장 큰 경우
    } else if (b == c && b > a) {
        cout << "b와 c는 " << b << "로 가장 큰 정수입니다." << endl;  // b, c가 같고 가장 큰 경우
    } else {                                                        // 그 외의 경우
        int largest = a; // 기본값으로 a를 가장 큰 값으로 가정
        if (b > largest) {
            largest = b;
        }
        if (c > largest) {
            largest = c;
        }
        cout << "가장 큰 정수는 " << largest << "입니다." << endl;
    }
}