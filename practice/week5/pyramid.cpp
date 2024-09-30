#include <iostream>
using namespace std;

int main() {
    int floor;
    cout <<  "몇 층으로 쌓을까요?";
    cin >> floor;

    for (int i=0; i < floor; i++) {
        for (int s=floor-i; s>1; s--) {
            cout << "S";
        }

        for (int s=0; s<2*i+1; s++) {
            cout << "*";
        }
        cout << endl;
    }
}