#include <iostream>
using namespace std;

class User {
private:
    int HP;
public:
    User();
    void IncreaseHP(int inc_hp);
    void DecreaseHP(int dec_hp);
    int GetHP();
};