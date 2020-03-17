#include <fstream>
#include <string>
#include <iostream>
#include <math.h>
#include <algorithm>
#include <cstdlib>
using namespace std;
#include <vector>
#define MAX_N 100000

int groups[MAX_N];
struct cow {
    long long x;
    long long y;
};

void ff(int s, int gn, vector<int> con[]){
    groups[s] = gn;
    for (int x = 0; x < con[s].size(); x++ ){
        if (groups[con[s][x]] == 0){
            ff(con[s][x], gn, con);
        }
    }
}
long long rectangle(vector<cow> group){
    long long left = 1000000000;
    long long right = 0;
    long long top = 0;
    long long bottom = 1000000000;
    for (int z =0; z < group.size(); z++){
        if (group[z].x < left){
            left = group[z].x;
        }
        if (group[z].x > right){
            right = group[z].x;
        }
         if (group[z].y < bottom){
            bottom = group[z].y;
        }
        if (group[z].y > top){
            top = group[z].y;
        }
    }
    return (abs(top - bottom) + abs(right - left)) * 2;
}

int main() {
    ifstream in("fenceplan.in");
    ofstream out("fenceplan.out");
    int n;
    int m;
    in >> n;
    in >> m;
    vector<int> con[n];
    vector<cow> cows;
    for (int x = 0; x < n; x ++){
        cow temp;
        in >> temp.x;
        in >> temp.y;
        cows.push_back(temp);
    }
    long s;
    long e;
    int gn = 1;
    for (int x =0 ; x < m; x ++){
        in >> s;
        in >> e;
        con[s - 1].push_back(e - 1);
        con[e - 1].push_back(s - 1);


    }
    for (int x =0; x < n; x++){
        if (groups[x] == 0){
            ff(x, gn, con);
            gn ++;
        }
    }

    vector<vector<cow>> gr(gn - 1);
    for (int x =0; x < n; x++){

        gr[groups[x] - 1].push_back(cows[x]);
    }

    long long answer = rectangle(gr[0]);

    for (int x =0; x < gr.size(); x++){
        if (rectangle(gr[x]) < answer){
            answer = rectangle(gr[x]);

        }


    }
    out << answer << "\n";



}
