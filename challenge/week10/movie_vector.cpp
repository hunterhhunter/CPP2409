#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Movie {
public:
    string name;
    float score;
    
    Movie(string nm, float sc) {
        this->name = nm;
        this->score = sc;
    }
};

int main(void) {
    vector<Movie> vec;

    vec.push_back(Movie{"titinic", 9.9});
    vec.push_back(Movie{"gone with the wind", 9.6});
    vec.push_back(Movie{"terminator", 9.7});

    for (auto& e : vec)
        cout << e.name << ": " << e.score << endl;

    return 0;
}