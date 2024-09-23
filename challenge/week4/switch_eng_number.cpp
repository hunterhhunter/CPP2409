#include <iostream>
using namespace std;

int main() {
    int number;
    cout << "숫자를 입력하시오: ";
    cin >> number;

    switch (number)                 // 음수에 대한 처리가 필요함
    {
    case 0:
        cout << "zero" << endl;
        break;
    case 1:
        cout << "one" << endl;
    default:
        cout << "many" << endl;
        break;
    }
    
    return 0;
}