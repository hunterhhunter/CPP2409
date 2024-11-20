#include "user.h"

class Magician : public User
{
public:
    Magician(): User(){};
    void DoAttack() override;
    string GetInfo() const override {
        return "마법사 - HP: " + to_string(HP) + ", 아이템: " + to_string(itemCnt);
    }
};