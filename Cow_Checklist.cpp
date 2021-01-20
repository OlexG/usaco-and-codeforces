#include <fstream>
#include <string>
#include <iostream>
#include <bitset>
#include <math.h>
#include <algorithm>
#include<bits/stdc++.h>
#include <vector>
using namespace std;

long long h, g;
vector<pair<long long, long long>> hs;
vector<pair<long long, long long>> gs;

long long dist(pair<long long, long long> a, pair<long long, long long> b){
    return abs(a.first - b.first)*abs(a.first - b.first) + abs(a.second - b.second)*abs(a.second - b.second);
}
int main(){
    ifstream in("checklist.in");
    ofstream out("checklist.out");
    in >> h >> g;
    long long one, two;
    for (int x = 0; x < h; x++){
        in >> one >> two;
        hs.push_back(make_pair(one, two));
    }
    for (int x = 0; x < g; x++){
        in >> one >> two;
        gs.push_back(make_pair(one, two));
    }
    long long dph[g + 1][h];
    long long dpg[g + 1][h];
    for (int x = 0; x <= g; x++){
        for (int y = 0; y < h; y++){
            dph[x][y] = 100000000000000;
            dpg[x][y] = 100000000000000;
        }
    }
    dph[0][0] = 0;
    dpg[0][0] = 0;
    for (int x = 1; x < h; x++){
        dph[0][x] = dph[0][x - 1] + dist(hs[x], hs[x - 1]);
    }

    dpg[1][0] = dist(hs[0], gs[0]);

    for (int x = 2; x <= g; x++){
        dpg[x][0] = dpg[x - 1][0] + dist(gs[x - 1], gs[x - 2]);
    }



    for (int x = 1; x <= g; x++){
        for (int y = 1; y < h; y++){
            //dph
            dph[x][y] = min(dph[x][y], dph[x][y - 1] + dist(hs[y], hs[y - 1]));
            dph[x][y] = min(dph[x][y], dpg[x][y - 1] + dist(hs[y], gs[x - 1]));
            if (x != 1){
                dpg[x][y] = min(dpg[x][y], dpg[x - 1][y] + dist(gs[x - 1], gs[x - 2]));
            }
            dpg[x][y] = min(dpg[x][y], dph[x - 1][y] + dist(gs[x - 1], hs[y]));

        }
    }

    out << dph[g][h - 1] << "\n";

}
