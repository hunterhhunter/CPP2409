#include <iostream>
using namespace std;

int main() {
    int vowel = 0;
    int consonant = 0;
    cout << "영문자를 입력하고 ctrl+z를 입력하세요" << endl;

    char ch;

    while (true)
    {
        cin >> ch;
        if (cin.eof())  // Ctrl+Z = EOF를 터미널에서 처리하기 위한 cin.eof() 사용
            break;
        if (ch < 96 || ch > 122)
            cout << "영어 소문자 이외의 문자가 입력되었습니다. 다시 입력해주세요." << endl;
        else {
            switch (ch)     // 모음인 경우 vowel++, 그 외의 경우 consonant++
            {
            case 'a':
                vowel++;
                break;
            case 'e':
                vowel++;
                break;
            case 'i':
                vowel++;
                break;
            case 'o':
                vowel++;
                break;
            case 'u':
                vowel++;
                break;
            default:
                consonant++;
                break;
            }
        }
        
    }
    // 결과 출력
    cout << "모음: " << vowel << endl;
    cout << "자음: " << consonant << endl;
    return 0;
    
}