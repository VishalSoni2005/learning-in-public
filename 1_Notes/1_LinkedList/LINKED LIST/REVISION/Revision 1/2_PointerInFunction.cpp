#include<iostream>
using namespace std;
class CricketTeam{
public:
    string team;
    string bestBatter;
    string bestBowller;
    CricketTeam(string team, string bestBatter, string bestBowller) {
        this->team = team;
        (*this).bestBatter = bestBatter;
        this->bestBowller =bestBowller ;
    }
};
void change(CricketTeam* team2){
    team2->team = "CSK";
    team2->bestBatter = "M.S. Dhoni";
    team2->bestBowller = "Jadeja";
}
int main() {
    CricketTeam team1("RCB", "Virat Kolhi", "Siraj");
    cout << team1.team << endl;
    // CricketTeam* ptr = &team1;
    // cout << ptr->team << endl;

    change(&team1);
    cout << team1.team << endl;


}