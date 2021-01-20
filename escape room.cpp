#include <fstream>
#include <string>
#include <iostream>
#include <math.h>
#include <algorithm>
#include<bits/stdc++.h>
#include <vector>
using namespace std;

int n, m;
int arr[1000][1000];
int used[1000][1000];
int answer = false;
vector<pair<int , int>> cons[1000005];
void dfs(int curx, int cury){
    used[curx][cury] = 2;
    if (curx == n - 1 && cury == m - 1){
        answer = true;
        return;
    }
    for (int x = 0; x < cons[arr[curx][cury]].size(); x++){
        int newx = cons[arr[curx][cury]][x].first;
        int newy = cons[arr[curx][cury]][x].second;
        if (used[newx][newy] == 1){
            dfs(newx, newy);
        }
    }
}
int main(){
    cin >> n >> m;
    for (int x = 0; x < n; x++){
        for (int y = 0; y < m; y++){
            cin >> arr[x][y];
            if ((x + 1) * (y + 1) <= 1000000){
                cons[(x + 1) * (y + 1)].push_back(make_pair(x, y));
            }
            used[x][y] = 1;
        }
    }
    dfs(0,0);
    cout << (answer ? "yes" : "no");


}
