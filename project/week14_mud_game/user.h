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
    ~User();
    // 출력 내용을 정의하는 가상 함수
    virtual string GetInfo() const = 0;

    virtual void DoAttack() = 0;

    friend ostream& operator<<(ostream& os, const User& u) {
        os << u.GetInfo() << endl;
        return os;
    }

    virtual void IncreaseHP(int inc_hp) = 0;
    virtual void DecreaseHP(int dec_hp) = 0;
    virtual int GetHP() = 0;
    virtual void IncreaseItemCnt();
    virtual bool Move(int dx, int dy, int x_max, int y_max);
    virtual pair<int, int> GetXY();

private:
    virtual bool checkXY(int dx, int dy, int x_max, int y_max);
};