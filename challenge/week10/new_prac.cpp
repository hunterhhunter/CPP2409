#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main(void) {
    vector<vector<int>> vec;

    vec = { {0, 1, 2, 0, 4},
            {1, 0, 0, 2, 0},
            {0, 0, 0, 0, 0},
            {0, 2, 3, 0, 0},
            {3, 0, 0, 0, 2} };

    for (auto e1 : vec) {
        for (auto e2 : e1) {
            cout << e2 << " ";
        }
        cout << "\n";
    }
    
    return 0;
}