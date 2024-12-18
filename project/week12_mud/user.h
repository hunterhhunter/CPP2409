#include <iostream>
using namespace std;

class User {
private:
    int HP;      // 현재 체력
    int itemCnt; // 아이템 먹은 횟수 저장

public:
    User();
    friend ostream& operator<<(ostream& os, const User& u){
        os<<"현재 HP는 "<< u.HP <<"이고, 먹은 아이템은 총" << u.itemCnt <<"개 입니다." << endl;
        return os;
    }
    void IncreaseHP(int inc_hp);
    void DecreaseHP(int dec_hp);
    int GetHP();
    void IncreaseItemCnt();
};