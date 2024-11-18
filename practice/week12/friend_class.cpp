#include <iostream>
#include <string>
using namespace std;

class A
{
public:
    friend class B; // B는 A의 친구
    A(string s="") : secret{s} {}
private:
    string secret; // B가 접근 가능
};

class B
{
public:
    B() { }
    void print(A obj)
    {
        cout << obj.secret << endl;
    }
};

int main() 
{
    A a("이것은 기밀 정보입니다.");
    B b;

    b.print(a);
    return 0;
}