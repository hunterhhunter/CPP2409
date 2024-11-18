#include <iostream>
using namespace std;

class Box
{
    double length, width, height;
public:
    Box(double l, double, w, double h)
        : length{l}
        , width{w}
        , height{h}
    {

    }

    friend void PrintBox(Box box);
};

void Box::PrintBox(Box box)
{
    cout << "Box(" << box.length << ", " << box.width << ", " << box.height << ") " << endl;
}

int main() {
    Box box(10, 20, 30);
    PrintBox(box);

    return 0;
}


// #include <iostream>
// using namespace std;

// class Box
// {
//     double length, width, height;
// public:
//     Box(double l, double w, double h)
//         : length{l}
//         , width{w}
//         , height{h}
//     {

//     }

//     void PrintBox(Box box);
// };

// void Box::PrintBox(Box box)
// {
//     cout << "Box(" << box.length << ", " << box.width << ", " << box.height << ") " << endl;
// }

// int main() {
//     Box box(10, 20, 30);
//     box.PrintBox(box);

//     return 0;
// }