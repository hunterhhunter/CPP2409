#include "Warrior.h"
#include <iostream>
using namespace std;

Warrior::Warrior() : User() {}

Warrior::~Warrior() {}

void Warrior::DoAttack() {
    cout << "전사가 검으로 공격합니다!" << endl;
}

string Warrior::GetInfo() const {
    return "전사 - HP: " + to_string(HP) + ", 아이템: " + to_string(itemCnt);
}

void Warrior::IncreaseHP(int inc_hp) {
    HP += inc_hp;
    if (HP > 20) HP = 20;
}

void Warrior::DecreaseHP(int dec_hp) {
    HP -= dec_hp;
    if (HP < 0) HP = 0;
}

int Warrior::GetHP() {
    return HP;
}

bool Warrior::Move(int dx, int dy, int x_max, int y_max) {
    if (!checkXY(X + dx, Y + dy, x_max, y_max)) {
        cout << "맵을 벗어났습니다. 다시 돌아갑니다." << endl;
        return false;
    }
    X += dx;
    Y += dy;
    DecreaseHP(1);
    return true;
}

pair<int, int> Warrior::GetXY() {
    return {X, Y};
}

bool Warrior::checkXY(int dx, int dy, int x_max, int y_max) {
    return (dx >= 0 && dy >= 0 && dx < x_max && dy < y_max);
}
