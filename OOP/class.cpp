#include<bits/stdc++.h>
using namespace std;


class Player{
    // attributes
    string name;
    int health;
    int xp;

    // methods
    void talk(string);
    bool is_dead();
};

int main(){

    Player frank;
    Player vaibhav;

    // dynamic creating variable
    Player *enemy{nullptr};
    enemy = new Player;

    Player players[] {frank, vaibhav};

    vector<Player> players_vec {frank};
    players_vec.push_back(vaibhav);

    return 0;
}