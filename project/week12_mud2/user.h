#pragma once
#include <iostream>
#include <vector>
using namespace std;

class User 
{
protected:
    int HP;      // 현재 체력
    int itemCnt; // 아이템 먹은 횟수 저장
    int X;
    int Y;

public:
    User();
    // 출력 내용을 정의하는 가상 함수
    virtual string GetInfo() const {
        return "현재 HP는 " + to_string(HP) + "이고, 먹은 아이템은 총 " + to_string(itemCnt) + "개 입니다.";
    }

    friend ostream& operator<<(ostream& os, const User& u) {
        os << u.GetInfo() << endl;
        return os;
    }
    void IncreaseHP(int inc_hp);
    void DecreaseHP(int dec_hp);
    int GetHP();
    void IncreaseItemCnt();
    virtual void DoAttack();
    bool Move(int dx, int dy, int x_max, int y_max);
    pair<int, int> GetXY();

private:
    bool checkXY(int dx, int dy, int x_max, int y_max);
};