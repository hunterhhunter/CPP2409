#include <iostream>
using namespace std;

class Animal
{
public:
    void Speak() {cout << "Animal speak()" << endl; }
};

class Dog : public Animal
{
public:
    int age;
    void Speak() { cout << "멍멍" << endl; }
};

class Cat : public Animal
{
public:
    void Speak() { cout << "야옹" << endl; }
};

int main()
{
    // new를 통한 동적객체 생성 -> 포인터
    Animal* a1 = new Dog();
    a1->Speak();

    // a1은 animal객체로 변환 -> age접근 불가

    Animal a2 = Cat();
    a2.Speak();

    delete a1;
    return 0;
}