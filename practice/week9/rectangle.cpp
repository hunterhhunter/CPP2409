#include<iostream>
using namespace std;

class Rectangle {
public:
    int width, height;
    int CalcArea() {
            return width * height;
    }
};

int main() {
    Rectangle obj, obj2;
    obj.width = 3;
    obj.height = 4;
    int area = obj.CalcArea();
    cout << "사각형1의 넓이: " << area << endl;

    obj2.width = 5;
    obj2.height = 5;
    int area2 = obj2.CalcArea();
    cout << "사각형2의 넓이: " << area2 << endl;
    return 0;
}