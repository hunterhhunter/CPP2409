#include <iostream>
#include <string>
using namespace std;

string toLowerStr(string str) {
    string tmp = str; // 문자열 변경을 위한 새로운 string 선언
    for (char &i: tmp) {
        i = tolower(i);
    }
    return tmp;
}

string toUpperStr(string str) {
    string tmp = str;
    for (char &i: tmp) {
        i = toupper(i);
    }
    return tmp;
}

int calcHammingDist(string s1, string s2) {
    int count = 0;
    string lower_s1 = toLowerStr(s1); // 소문자로 비교
    string lower_s2 = toLowerStr(s2);

    // 해밍거리 계산
    for (int i=0; i < s1.length();i++) {
        if (lower_s1[i] != lower_s2[i])
            count++;
    }
    return count;
}

int main() {
    string s1, s2;

    while (true)
    {
        cout << "DNA1: ";
        cin >> s1;
        cout << "DNA2: ";
        cin >> s2;
        
        if (s1.length() != s2.length()) {
            cout << "입력된 문자열의 길이가 다릅니다. 재입력 요망" << endl;
            continue; // 재입력을 위한 continue
        }
        int count = calcHammingDist(s1, s2);
        cout << "해밍 거리는 " << count << endl;
        break;
    }
    return 0;
}