#pragma once
#include "user.h"

class Warrior : public User {
public:
    Warrior();
    ~Warrior();
    void DoAttack() override;
    string GetInfo() const override;
    void IncreaseHP(int inc_hp) override;
    void DecreaseHP(int dec_hp) override;
    int GetHP() override;
    bool Move(int dx, int dy, int x_max, int y_max) override;
    pair<int, int> GetXY() override;

private:
    bool checkXY(int dx, int dy, int x_max, int y_max) override;
};
