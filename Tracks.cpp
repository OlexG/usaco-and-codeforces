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

int n, m;

char arr[4001][4001];
int dist[4001][4001];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, -1, 0, 1};
bool inside(int x, int y){
    if (x < 0 || x >= n){
        return false;
    }
    if (y < 0 || y >= m){
        return false;
    }
    if (arr[x][y] == '.'){
        return false;
    }
    return true;
}
int main(){
    cin >> n >> m;
    for (int x = 0; x < n; x++){
        for (int y = 0; y < m; y++){
            cin >> arr[x][y];
            dist[x][y] = -1;
        }
    }
    int answer = 1;
    deque<pair<int, int>> q;
    dist[0][0] = 1;
    q.push_back({0, 0});
    while(q.size() > 0){
        pair<int, int> cur = q.front();
        q.pop_front();
        answer = max(answer, dist[cur.first][cur.second]);
        for (int z = 0; z < 4; z++){
            int nx = cur.first + dx[z];
            int ny = cur.second + dy[z];
            if (inside(nx, ny) && dist[nx][ny] == -1){
                if (arr[nx][ny] == arr[cur.first][cur.second]){
                    dist[nx][ny] = dist[cur.first][cur.second];
                    q.push_front({nx, ny});
                }
                else{
                    dist[nx][ny] = dist[cur.first][cur.second] + 1;
                    q.push_back({nx, ny});
                }
            }
        }
    }
    cout << answer << "\n";

}
