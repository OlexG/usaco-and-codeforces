#include <fstream>
#include <string>
#include <iostream>
#include <math.h>
#include <algorithm>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

int n, k, r;
set<int> roads[100][100];
int arr[100][100];
int used[100][100];
int counter = 1;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
void dfs(int x, int y){
    used[x][y] = 2;
    arr[x][y] = counter;
    for (int z = 0; z < 4; z++){
        int curx = x + dx[z];
        int cury = y + dy[z];
        if (curx >= 0 && curx < n && cury >= 0 && cury < n && used[curx][cury] == 1){
            if (roads[x][y].count(curx * 1000 + cury) == 0){
                dfs(curx, cury);
            }
        }
    }
}
int main(){
    ifstream in("countcross.in");
    ofstream out("countcross.out");
    in >> n >> k >> r;
    int one, two, three, four;
    for (int x = 0; x < r; x++){
        in >> one >> two >> three >> four;
        roads[one - 1][two - 1].insert((three - 1) * 1000 + (four - 1));
        roads[three - 1][four - 1].insert((one - 1) * 1000 + (two - 1));
    }
    for (int x = 0; x < n; x++){
        for (int y = 0; y < n; y++){
            used[x][y] = 1;
        }
    }
    for (int x = 0; x < n; x++){
        for (int y = 0; y < n; y++){
            if (used[x][y] == 1){
                dfs(x, y);
                counter += 1;
            }
        }
    }
    vector<pair<int, int>> c;
    for (int x = 0; x < k; x++){
        in >> one >> two;
        c.push_back(make_pair(one, two));
    }
    int answer = 0;
    for (int x = 0; x < k; x++){
        for (int y = 0; y < k; y++){
            if (arr[c[x].first - 1][c[x].second - 1] != arr[c[y].first - 1][c[y].second - 1]){
                answer++;
            }
        }
    }
    out << answer/2 << "\n";
}


