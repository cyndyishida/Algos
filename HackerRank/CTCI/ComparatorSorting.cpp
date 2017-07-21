/*
    basic bubble sort with a additional criteria 
*/

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

struct Player {
    string name;
    int score;
}; 

void comparator(vector<Player> &players) {
    for (int i = 0 ; i < players.size(); ++i)
    {
        for (int j = 0; j < players.size() -1; ++j)
        {
            if (players[j].score < players[j+1].score 
                || (players[j].score == players[j+1].score 
                    && players[j].name > players[j+1].name))
                swap(players[j], players[j+1]);
        }
    }
}

int main() {
    
    int n;
    cin >> n;
    vector< Player > players;
    string name;
    int score;
    for(int i = 0; i < n; i++){
        cin >> name >> score;
        Player p1;
        p1.name = name, p1.score = score;
        players.push_back(p1);
    }
    
    comparator(players);
    for(int i = 0; i < players.size(); i++) {
        cout << players[i].name << " " << players[i].score << endl;
    }
    return 0;
}
