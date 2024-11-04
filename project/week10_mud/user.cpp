#include <iostream>
#include "user.h"
using namespace std;

User::User() {
    HP = 20;
}

void User::IncreaseHP(int inc_hp) {
    HP += inc_hp;
    if (HP > 20) {
        HP = 20;
    }
}

void User::DecreaseHP(int dec_hp) {
    HP -= dec_hp;
    if (HP < 0) {
        HP = 0;
    }
}

int User::GetHP() {
    return HP;
}