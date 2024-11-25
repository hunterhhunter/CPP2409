#include <iostream>
using namespace std;

class RemoteControl
{
public:
    virtual void TurnON() = 0;
    virtual void TurnOFF() = 0;
};

class Television : public RemoteControl
{
private:
    bool isOn;

public:
    void TurnON() override
    {
        isOn = true;
        cout << "Tv를 켭니다." << endl;
    }

    void TurnOFF() override
    {
        isOn = false;
        cout << "Tv를 끕니다." << endl;
    }
};

class Refrigerator : public RemoteControl
{
private:
    bool isOn;

public:
    void TurnON() override
    {
        isOn = true;
        cout << "냉장고를 켭니다." << endl;
    }

    void TurnOFF() override
    {
        isOn = false;
        cout << "냉장고를 끕니다." << endl;
    }
};

int main()
{
    RemoteControl* remoteTV = new Television(); // 업캐스팅
    remoteTV->TurnON(); // 켜기
    remoteTV->TurnOFF(); // 끄기

    RemoteControl* remoteRefrigerator = new Refrigerator();
    remoteRefrigerator->TurnON();
    remoteRefrigerator->TurnOFF();

    delete remoteRefrigerator, remoteTV;

    return 0;
}