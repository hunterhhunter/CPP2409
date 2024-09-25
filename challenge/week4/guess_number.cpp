#include<time.h>
#include<iostream>
using namespace std;


int main() {
    srand(time(NULL)); // 랜덤함수 관련 설정
    
    int answer = rand() % 100; // 정답 100이내로 한정
    int tries = 0; // 시도 횟수

    int guess; // 사용자 입력 저장 변수
    
    while (1)
    {
        cout << "정답을 추측하여 보시오: ";
        cin >> guess;
        tries++;
        
        if (guess == answer) // 정답시 탈출
            break;
        else if(guess < answer) 
            cout << "제시한 정수가 정답보다 낮습니다" << endl;
        else
            cout << "제시한 정수가 정답보다 높습니다" << endl;
    }
    
    cout << "축하합니다. 시도 횟수=" << tries << endl;
    return 0;
}