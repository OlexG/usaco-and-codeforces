#pragma GCC optimize("O2")
#include <fstream>
#include <string>
#include <iostream>
#include <bitset>
#include <math.h>
#include <string>
#include <algorithm>
#include <assert.h>
#include<bits/stdc++.h>
#include <vector>
#include <queue>
#include<stdio.h>
#include<ctype.h>
#define ll long long
using namespace std;

struct Edge{
    char a;
    ll x;
    ll y;
};
int n;
vector<Edge> cows;

vector<int> cons[1001];

int field[5001][5001];
int used[1001];
int am[1001];
int fam[1001];
void dfs(int cur){
    am[cur] = 0;
    for (int x = 0; x < cons[cur].size(); x++){
        am[cur] += 1;
        dfs(cons[cur][x]);
        am[cur] += am[cons[cur][x]];
    }
}
int main(){
    cin >> n;
    char one;
    ll two;
    ll three;
    for (int x = 0; x < n; x++){
        cin >> one;
        cin >> two;
        cin >> three;
        cows.push_back({one, two, three});
        am[x] = 0;
        fam[x] = 0;
        used[x] = 2;
    }
    for (int x = 0; x < 5001; x++){
        for (int y = 0; y < 5001; y++){
            field[x][y] = -1;
        }
    }
    for (int c = 0; c < n; c++){
        field[cows[c].y][cows[c].x] = c;
    }
    for (int z = 0; z < 3001; z++){
        for (int c = 0; c < n; c++){
            if (cows[c].a != 'D'){
                if (cows[c].a == 'E'){
                    if (field[cows[c].y][cows[c].x + 1] == -1){
                        //field[cows[c].y][cows[c].x] = c;
                        cows[c].x += 1;
                    }
                    else{
                        cons[field[cows[c].y][cows[c].x + 1]].push_back(c);
                        cows[c].a = 'D';
                    }
                }
                else{
                    if (field[cows[c].y + 1][cows[c].x] == -1){
                        //field[cows[c].y][cows[c].x] = c;
                        cows[c].y += 1;
                    }
                    else{
                        //cout << c << " " << field[cows[c].y + 1][cows[c].x] << "\n";
                        cons[field[cows[c].y + 1][cows[c].x]].push_back(c);
                        cows[c].a = 'D';
                    }
                }
            }
        }
        for (int c = 0; c < n; c++){
            if (cows[c].a != 'D'){
                field[cows[c].y][cows[c].x] = c;
            }
        }
    }

    for (int x = 0; x < n; x++){
        for (int y = 0; y < n; y++){
            am[y] = 0;
        }
        dfs(x);
        fam[x] = am[x];
    }
    for (int x = 0; x < n; x++){
        cout << fam[x] << "\n";
    }



}
