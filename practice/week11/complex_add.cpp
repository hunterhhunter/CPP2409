#include <iostream>
using namespace std;

class Complex {
public:
    double real, imag;
    Complex(double r = 0.0, double i = 0.0) {
        real = r;
        imag = i;
        cout << "생성자 호출";
        Print();
    }
    ~Complex() {
        cout << "소멸자 호출";
        Print();
    }
    void Print() {
        cout << real << " + " << imag << "i" << endl;
    }
};

Complex Add(const Complex &c1, const Complex &c2) {
    // 변경 위험 변경을 위해 const 키워드 사용
    Complex q = Complex{};
    q.real = c1.real + c2.real;
    q.imag = c1.imag + c2.imag;
    return q;
}

int main() {
    Complex c1{1, 2}, c2{3, 4};
    Complex t;
    t = Add(c1, c2);
    t.Print();
    return 0;
}

