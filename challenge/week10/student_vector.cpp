#include<vector>
#include<iostream>

using namespace std;

int main() {
    vector<int> vec;
    int input;
    int sum;

    while (true) {
        cout << "성적을 입력하시오(종료는 -1) : ";
        cin >> input;
        
        if (input == -1)
            break;
        
        vec.push_back(input);
    }
    
    for (int e : vec) {
        sum += e;
    }

    cout << "성적 평균 = " <<  sum / (vec.end()-vec.begin()) << endl;
}