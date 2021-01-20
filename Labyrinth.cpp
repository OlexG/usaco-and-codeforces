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
pair<int, int> dir[1001][1001];
char arr[1001][1001];

bool inside(int x, int y){
    if (x < 0 || x >= n){
        return false;
    }
    if (y < 0 || y >= m){
        return false;
    }
    if (arr[x][y] == '#'){
        return false;
    }
    return true;
}
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, -1, 0, 1};
char rdir(pair<int, int> one, pair<int, int> two){
    if (one.first < two.first){
        return 'D';
    }
    if (one.first > two.first){
        return 'U';
    }
    if (one.second < two.second){
        return 'R';
    }
    if (one.second > two.second){
        return 'L';
    }
}
pair<int, int> cur;
int main(){
    cin >> n >> m;
    queue<pair<int, int>> q;

    for (int x = 0; x < n; x++){
        for (int y = 0; y < m; y++){
            cin >> arr[x][y];
            dir[x][y] = {-1, -1};
            if (arr[x][y] == 'A'){
                q.push({x, y});
                dir[x][y] = {0, 0};
            }
            if (arr[x][y] == 'B'){
                cur = {x, y};
            }
        }
    }

    while(q.size() > 0){
        pair<int, int> cur = q.front();
        q.pop();
        for (int z = 0; z < 4; z++){
            int nx = cur.first + dx[z];
            int ny = cur.second + dy[z];
            if (inside(nx, ny) && dir[nx][ny].first == -1){
                q.push({nx, ny});
                dir[nx][ny] = cur;
            }
        }
    }

    bool works = false;
    vector<char> st;
    while(dir[cur.first][cur.second].first != -1){
        if (arr[cur.first][cur.second] == 'A'){
            works = true;
            break;
        }
        char c = rdir(dir[cur.first][cur.second], {cur.first,cur.second});
        st.push_back(c);
        cur = dir[cur.first][cur.second];
    }
    if (works){
        cout << "YES\n";
        cout << st.size() << "\n";
        reverse(st.begin(), st.end());
        for (int x = 0; x < st.size(); x++){
            cout << st[x];
        }
        cout << "\n";
    }
    else{
        cout << "NO\n";
    }


}
