#include "user.h"
using namespace std;

User::User() {
    HP = 20;
    itemCnt = 0;
    X = 0;
    Y = 0;
}

User::~User()
{
    
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

void User::IncreaseItemCnt()
{
    itemCnt++;
}

bool User::Move(int dx, int dy, int x_max, int y_max)
{
    if (!checkXY(X+dx, Y+dy, x_max, y_max))
    {
        cout << "맵을 벗어났습니다. 다시 돌아갑니다." << endl;
        return false;
    }
    X += dx;
    Y += dy;
    DecreaseHP(1);
    return true;
}

pair<int, int> User::GetXY()
{
    return {X, Y};
}

// private
bool User::checkXY(int dx, int dy, int x_max, int y_max)
{
    if (dx < 0 || dy < 0 || dx >= x_max || dy >= y_max)
        return false;
    return true;
}
