#pragma GCC optimize("O2")
#include <fstream>
#include <string>
#include <iostream>
#include <bitset>
#include <math.h>
#include <string>
#include <algorithm>
#include<bits/stdc++.h>
#include <vector>
#include <queue>
using namespace std;

int n, m;
vector<pair<int, int>> bcons[101];
vector<pair<int, int>> econs[101];
int bways[101][10001];
int eways[101][10001];

int main(){
    ifstream in("meeting.in");
    ofstream out("meeting.out");
    for (int x = 0; x < 101; x++){
        for (int y = 0; y < 10001; y++){
            eways[x][y] = 0;
            bways[x][y] = 0;
        }
    }
    in >> n >> m;
    for (int x = 0; x < m; x++){
        int a, b, c, d;
        in >> a >> b >> c >> d;
        bcons[a-1].push_back({b - 1, c});
        econs[a-1].push_back({b - 1, d});
    }
    bways[0][0] = 1;
    eways[0][0] = 1;
    for (int x = 0; x < n; x++){
        for (int y = 0; y < bcons[x].size(); y++){
            for (int z = 0; z < 10001; z++){
                if (bways[x][z] == 1){
                    bways[bcons[x][y].first][bcons[x][y].second + z] = 1;
                }
            }
            for (int z = 0; z < 10001; z++){
                if (eways[x][z] == 1){
                    eways[econs[x][y].first][econs[x][y].second + z] = 1;
                }
            }
        }
    }
    int answer = -1;
    for (int x = 0; x < 10001; x++){
        if (eways[n - 1][x] == 1 && bways[n - 1][x] == 1){
            answer = x;
            break;
        }
    }
    if (answer == -1){
        out << "IMPOSSIBLE\n";
    }
    else{
        out << answer << "\n";
    }
}
