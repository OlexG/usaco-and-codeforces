#include <fstream>
#include <string>
#include <iostream>
#include <math.h>
#include <algorithm>
#include <vector>


using namespace std;
struct opoint{
    int omoney;
    int money;
    string name;
};

struct npoint{
    int money;
    string name;
    vector<string> friends;
};
int n;
vector<opoint> original;
vector<npoint> sim;
int main(){
    cin >> n;
    string temp;
    opoint tempp;
    for (int x = 0; x < n; x++){
        cin >> temp;
        tempp.money = 0;
        tempp.name = temp;
        original.push_back(tempp);
    }
    int one, two;
    npoint ntemp;
    for (int x = 0; x < n; x++){
        cin >> temp >> one >> two;
        ntemp.money = one;
        ntemp.name = temp;
        for (int y = 0; y < n; y++){
            if (original[y].name == temp){
                original[y].money = 0;
                original[y].omoney = 0;
            }
        }
        ntemp.friends.clear();
        for (int y = 0; y < two; y++){
            cin >> temp;
            ntemp.friends.push_back(temp);
        }
        sim.push_back(ntemp);
    }
    for (int x = 0; x < n; x++){
        int moneygiven = 0;
        if (sim[x].friends.size() != 0){
            moneygiven = sim[x].money / sim[x].friends.size();
        }

        for (int y = 0; y < sim[x].friends.size(); y++){
            string fr = sim[x].friends[y];
            for (int z = 0; z < n; z++){
                if (original[z].name == fr){
                    original[z].money += moneygiven;
                    for (int v = 0; v < n; v++){
                        if (original[v].name == sim[x].name){
                            original[v].money -= moneygiven;
                        }
                    }
                }
            }
        }
    }
    for (int x = 0; x < n; x++){
        cout << original[x].name << " " << original[x].money << "\n";
    }

}
