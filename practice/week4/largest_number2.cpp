#include <iostream>
using namespace std;

int main() {
    int a, b, c, largest;

    cout << "3개의 정수를 space를 기준 분리하여 입력하시오: "; // 입력 포맷 지정
    cin >> a >> b >> c;

    largest = a;

    if (largest >= b) {
        if (largest <= c)
            largest = c;
    } else {
        if (b <= c)
            largest = c;
        else
            largest = b;
    }
    cout << "가장 큰 정수는 " << largest << " 입니다." << endl;
    return 0;
}