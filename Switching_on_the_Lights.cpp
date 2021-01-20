#include <fstream>
#include <string>
#include <iostream>
#include <math.h>
#include <algorithm>
#include<bits/stdc++.h>
#include <vector>
using namespace std;

int n, m;
vector<pair<int, int>> cons[200005];
int vis[100][100];
int lit[100][100];

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};

int main(){
    ifstream in("lightson.in");
    ofstream out("lightson.out");
    in >> n >> m;
    queue<pair<int, int>> q;
    q.push(make_pair(0, 0));
    for (int x = 0; x < n; x++){
        for (int y = 0; y < n; y++){
            vis[x][y] = 2;
            lit[x][y] = 2;
        }
    }
    lit[0][0] = 1;
    int one, two, three, four;
    for (int x = 0; x < m; x++){
        in >> one >> two >> three >> four;
        cons[(one-1) * 1000 + (two - 1)].push_back(make_pair(three - 1, four - 1));
    }
    while(q.empty() == false){
        pair<int, int> top = q.front();
        vis[top.first][top.second] = 1;
        for (int x = 0; x < cons[top.first * 1000 + top.second].size(); x++){
            lit[cons[top.first * 1000 + top.second][x].first][cons[top.first * 1000 + top.second][x].second] = 1;
            int cx = cons[top.first * 1000 + top.second][x].first;
            int cy = cons[top.first * 1000 + top.second][x].second;
            if (vis[cx][cy] == 2){
                for (int z = 0; z < 4; z++){
                    int nx = cx + dx[z];
                    int ny = cy + dy[z];
                    if (nx >= 0 && nx < n && ny >= 0 && ny < n && vis[nx][ny] == 1 && vis[cx][cy] == 2){
                        vis[cx][cy] = 1;
                        q.push(make_pair(cx, cy));
                        break;
                    }
                }
            }
        }
        for (int z = 0; z < 4; z++){
            int cx = top.first;
            int cy = top.second;
            for (int z = 0; z < 4; z++){
                int nx = cx + dx[z];
                int ny = cy + dy[z];
                if (nx >= 0 && nx < n && ny >= 0 && ny < n && vis[nx][ny] == 2 && lit[nx][ny] == 1){
                    vis[nx][ny] = 1;
                    q.push(make_pair(nx, ny));
                }
            }
        }
        q.pop();
    }
    int answer = 0;
    for (int x = 0; x < n; x++){
        for (int y = 0; y < n; y++){
            if (lit[x][y] == 1){
                answer++;
            }
        }
    }
    out << answer << "\n";
}
