#include <iostream>
using namespace std;

int main() {
    int floor;
    cout << "몇 층을 쌓겠습니까?: ";
    cin >> floor;

    for (int i=0;i<floor;i++) {
        for(int s=0;s<i;s++){
            cout << "S";
        }
        for (int s=floor*2-2*(i+1)+1;s>0;s--) {
            cout << "*";
        }
        cout << endl;
    }
}