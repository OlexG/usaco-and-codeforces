#include <fstream>
#include <string>
#include <iostream>
#include <math.h>
#include <algorithm>
#include<bits/stdc++.h>
#include <vector>
using namespace std;

int t;
int n;
int sums[300001];
vector<int> cons[300001];
bool done = false;
int color[300001];
int used[300001];
int centroid = -1;
void dfs(int cur){
    used[cur] = 2;
    sums[cur] = 1;
    for (int x = 0; x < cons[cur].size(); x++){
        if (used[cons[cur][x]] == 1){
            dfs(cons[cur][x]);
            sums[cur] += sums[cons[cur][x]];
        }
    }
    if (sums[cur] == n/2){
        color[cur] = 1;
        centroid = cur;
    }
}
void dfscolor(int cur, int prev){
    if (prev != -1){
        if (color[cur] == -1){
            color[cur] = color[prev];
        }
    }
    used[cur] = 3;
    for (int x = 0; x < cons[cur].size(); x++){
        if (used[cons[cur][x]] == 2){
            dfscolor(cons[cur][x], cur);
        }
    }
}
int main(){
    cin >> t;
    int one, two;
    for (int z = 0; z < t; z++){
        cin >> n;
        done = false;
        for (int x = 0; x < n; x++){
            sums[x] = 0;
            color[x] = -1;
            used[x] = 1;
            centroid = -1;
            cons[x].clear();
        }
        int one, two;
        for (int x = 0; x < n - 1; x++){
            cin >> one >> two;
            cons[one-1].push_back(two - 1);
            cons[two-1].push_back(one - 1);
        }
        if (n % 2 == 1){
            cout << 1 << " " << cons[0][0] + 1 << "\n";
            cout << 1 << " " << cons[0][0] + 1 << "\n";
            continue;
        }
        for (int x = 0; x < n; x++){
            if (cons[x].size() > 1){
                dfs(x);
                color[x] = 2;
                dfscolor(x, -1);
                break;
            }
        }
        if (centroid == -1){
            cout << 1 << " " << cons[0][0] + 1 << "\n";
            cout << 1 << " " << cons[0][0] + 1 << "\n";
            continue;
        }
        for (int x = 0; x < n; x++){
            if (color[x] == 2 && cons[x].size() == 1){
                cout << x + 1 << " " << cons[x][0] + 1 << "\n";
                cout << centroid + 1 << " " << x + 1 << "\n";
                break;
            }
        }



    }
}
