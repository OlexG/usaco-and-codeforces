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
char arr[501][501];
int used[501][501][2];
struct state{
    int x;
    int y;
    int g;
    int d;
};
pair<int, int> des;
pair<int, int> start;
int answer = 0;
int sw(int cur){
    if (cur == 1){
        return 0;
    }
    return 1;
}
int main(){
    ifstream in("gravity.in");
    ofstream out("gravity.out");
    in >> n >> m;
    for (int x = 0; x < n; x++){
        for (int y = 0; y < m; y++){
            in >> arr[x][y];
            if (arr[x][y] == 'C'){
                start = {x, y};
            }
            if (arr[x][y] == 'D'){
                des = {x, y};
            }
            used[x][y][0] = 2;
            used[x][y][1] = 2;
        }
    }
    bool w = false;
    for (int x = start.first + 1; x < n; x++){
        if (arr[x][start.second] == '#'){
            w = true;
            arr[start.first][start.second] = '.';
            arr[x - 1][start.second] = 'C';
            start.first = x - 1;
            break;
        }
    }
    if (!w){
        out << -1 << "\n";
        return 0;
    }
    deque<state> q;
    q.push_front({start.first, start.second, 0, 0});
    int dy[2] = {-1, 1};
    int dyo[3] = {-1, 0, 1};
    bool works = false;
    while(q.size() > 0){
        state cur = q.front();
        q.pop_front();
        used[cur.x][cur.y][cur.g] = 1;
        //cout << cur.x << " " << cur.y << " " << cur.d << "\n";
        if (cur.x == des.first && cur.y == des.second){
            works = true;
            out << cur.d << "\n";
            break;
        }
        int cx = cur.x;
        int cy = cur.y;
        if (cur.g == 0){
            for (int x = 0; x < 2; x++){
                int ny = cy + dy[x];
                if (ny >= m || ny < 0){
                    continue;
                }
                int nx = cx;
                if (arr[nx][ny] == '#'){
                    continue;
                }
                bool w = false;
                for (int z = nx + 1; z < n; z++){
                    if (arr[z][ny] == '#'){
                        w = true;
                        nx = z - 1;
                        break;
                    }
                }
                if (w && used[nx][ny][cur.g] == 2 && arr[nx][ny] != '#'){
                    for (int y = cx;y <= nx; y++){
                        if (arr[y][ny] == 'D'){
                            out << cur.d << "\n";
                            return 0;
                        }
                    }
                    used[nx][ny][cur.g] = 1;
                    q.push_front({nx, ny, cur.g, cur.d});
                }
            }
            for (int x = 0; x < 3; x++){
                int ny = cy + dyo[x];
                if (ny >= m || ny < 0){
                    continue;
                }
                int nx = cx;
                if (arr[nx][ny] == '#'){
                    continue;
                }
                bool w = false;
                for (int z = nx - 1; z >= 0; z--){
                    if (arr[z][ny] == '#'){
                        nx = z + 1;
                        w = true;
                        break;
                    }
                }
                if (w && used[nx][ny][sw(cur.g)] == 2 && arr[nx][ny] != '#'){
                    for (int y = nx;y <= cx; y++){
                        if (arr[y][ny] == 'D'){
                            out << cur.d + 1 << "\n";
                            return 0;
                        }
                    }
                    used[nx][ny][sw(cur.g)] = 1;
                    q.push_back({nx, ny, sw(cur.g), cur.d + 1});
                }
            }
        }
        else{
            for (int x = 0; x < 2; x++){
                int ny = cy + dy[x];
                if (ny >= m || ny < 0){
                    continue;
                }
                int nx = cx;
                if (arr[nx][ny] == '#'){
                    continue;
                }
                bool w = false;
                for (int z = nx - 1; z >= 0; z--){
                    if (arr[z][ny] == '#'){
                        nx = z + 1;
                        w = true;
                        break;
                    }
                }
                if (w && used[nx][ny][cur.g] == 2 && arr[nx][ny] != '#'){
                    for (int y = nx;y <= cx; y++){
                        if (arr[y][ny] == 'D'){
                            out << cur.d << "\n";
                            return 0;
                        }
                    }
                    used[nx][ny][cur.g] = 1;
                    q.push_front({nx, ny, cur.g, cur.d});
                }
            }
            for (int x = 0; x < 3; x++){
                int ny = cy + dyo[x];
                if (ny >= m || ny < 0){
                    continue;
                }
                int nx = cx;
                if (arr[nx][ny] == '#'){
                    continue;
                }
                bool w = false;
                for (int z = nx + 1; z < n; z++){
                    if (arr[z][ny] == '#'){
                        nx = z - 1;
                        w = true;
                        break;
                    }
                }
                if (w && used[nx][ny][sw(cur.g)] == 2 && arr[nx][ny] != '#'){
                    for (int y = cx;y <= nx; y++){
                        if (arr[y][ny] == 'D'){
                            out << cur.d + 1 << "\n";
                            return 0;
                        }
                    }
                    used[nx][ny][sw(cur.g)] = 1;
                    q.push_back({nx, ny, sw(cur.g), cur.d + 1});
                }
            }
        }
    }
    if (!works){
        out << -1 << "\n";
    }

}
