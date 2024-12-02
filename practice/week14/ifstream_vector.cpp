#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

class TempData
{
public:
    int time;
    float temperature;
};

int main()
{
    vector<TempData> tempData = {};
    ifstream is{ "temp.txt" };

    if (!is)
    {
        cerr << "파일 오픈 실패" << endl;
        exit(1);
    }

    int time;
    float temperature;

    while (is >> time >> temperature)
    {
        tempData.push_back(TempData{ time, temperature });
    }

    for (TempData& t : tempData)
    {
        cout << t.time <<"시: 온도 " << t.temperature << endl;
    }

    return 0;

}