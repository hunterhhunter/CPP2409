#include <iostream>

using namespace std;

int main() {
    int money, priceOfCandy;
    cout << "가지고 있는 돈 = ";
    cin >> money;               // 가진 돈 입력
    cout << "캔디의 가격 = ";
    cin >> priceOfCandy;        // 사탕가격 입력
    
    cout << "최대로 살 수 있는 캔디 = " << money/priceOfCandy << endl; // 나누기 연산은 실수 반환이 아닌 정수연산
    cout << "캔디 구입 후 남은 돈 = " << money%priceOfCandy << endl; // 남은 돈은 나머지 연산
}