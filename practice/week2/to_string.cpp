#include <iostream>
#include <string>
using namespace std;

int main() {
    string s1 = "사과";
    string s2;
    // s2 = s1 + " " + 10 + "개"; -> int -> String은 캐스팅이 불가
    s2 = s1 + " " + to_string(10) + "개";
    cout << s2 << endl;
    
}