#include "user.h"

class Warrior : public User
{
public:
    Warrior(): User(){};
    void DoAttack() override;
    string GetInfo() const override {
    return "전사 - HP: " + to_string(HP) + ", 아이템: " + to_string(itemCnt);
}

};