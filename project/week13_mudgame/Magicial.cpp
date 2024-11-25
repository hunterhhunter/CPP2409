#include "Magician.h"
#include <iostream>
using namespace std;

Magician::Magician() : User() {}

Magician::~Magician() {}

void Magician::DoAttack() {
    cout << "마법사가 마법을 사용하여 공격합니다!" << endl;
}

string Magician::GetInfo() const {
    return "마법사 - HP: " + to_string(HP) + ", 아이템: " + to_string(itemCnt);
}

void Magician::IncreaseHP(int inc_hp) {
    HP += inc_hp;
    if (HP > 20) HP = 20;
}

void Magician::DecreaseHP(int dec_hp) {
    HP -= dec_hp;
    if (HP < 0) HP = 0;
}

int Magician::GetHP() {
    return HP;
}

bool Magician::Move(int dx, int dy, int x_max, int y_max) {
    if (!checkXY(X + dx, Y + dy, x_max, y_max)) {
        cout << "맵을 벗어났습니다. 다시 돌아갑니다." << endl;
        return false;
    }
    X += dx;
    Y += dy;
    DecreaseHP(1);
    return true;
}

pair<int, int> Magician::GetXY() {
    return {X, Y};
}

bool Magician::checkXY(int dx, int dy, int x_max, int y_max) {
    return (dx >= 0 && dy >= 0 && dx < x_max && dy < y_max);
}
