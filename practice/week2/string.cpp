#include <iostream>
#include <string>
using namespace std;

int main() {
    string s1 = "Good";     // 문자열 선언
    string s2 = "bad";
    bool b = (s1 == s2);    // 포인터 비교, false, 0
    cout << b << endl;      // bool은 cout시 0, 1로 2진화

    s2 = "Good";            // 기존 Good가 존재하기 때문에 s2에
    b = (s1 == s2);         // "Good"의 포인터 저장 so. true, 1
    cout << b << endl;
}