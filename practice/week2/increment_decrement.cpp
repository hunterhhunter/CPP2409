#include <iostream>

using namespace std;

int main() {
    int x = 1;

    cout << "x = " << x++ << endl; // 1이 출력되고 2로 변경
    cout << "x = " << x++ << endl; // 2가 출력되고 3으로 변경
    cout << "x = " << ++x << endl; // 3->4로 변경되고 출력 
    cout << "x = " << x-- << endl; // 4가 출력되고 3으로 변경
    cout << "x = " << x-- << endl; // 3이 출력되고 2로 변경
    cout << "x = " << --x << endl; // 2->1로 변경되고 출력

    return 0;
}