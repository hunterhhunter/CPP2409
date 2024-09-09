#include <iostream>
using namespace std;

auto add (int x, int y) {
    return x + y;               // 리턴 type: int
}

int main() {
    auto sum = add(5, 6);       // sum은 add의 return type인 int 할당
    cout << sum;
    return 0;
}