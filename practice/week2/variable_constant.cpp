#include <iostream>
#define PI 3.14159265359                    // PI가 기호상수
using namespace std;

int main() {
    int income = 1000;                      // 1000이 리터럴 상수
    const double TAX_RATE = 0.25;           // TAX_RATE가 상수 변수
    income = income - TAX_RATE * income;

    double x = 100;                         // 리터럴 상수
    x = x * PI;

    cout << x << endl;                      // x 출력
    return 0;
}
