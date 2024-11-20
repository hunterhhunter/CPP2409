#include "user.h"

class Warrior : public User
{
public:
    Warrior(): User(){};
    void DoAttack() override;
};