#include "user.h"

class Magician : public User
{
public:
    Magician(): User(){};
    void DoAttack() override;
};