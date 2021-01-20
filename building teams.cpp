#include <fstream>
#include <string>
#include <iostream>
#include <math.h>
#include <algorithm>
#include<bits/stdc++.h>
#include <vector>
using namespace std;
int n, m;
int pos[2] = {1, 2};
int used[200001];
int answers[200001];
vector<int> cons[200001];
bool answer = true;
void dfs(int cur, int mark){

    used[cur] = 2;
    answers[cur] = pos[mark];
    for (int x = 0; x < cons[cur].size(); x++){
        if (answers[cons[cur][x]] == pos[mark]){
            answer = false;
        }
        if (answers[cons[cur][x]] == -1 && used[cons[cur][x]] == 1){
            dfs(cons[cur][x], (mark + 1)%2);
        }
    }
}
int main(){
    cin >> n >> m;
    int a, b;
    for (int x = 0; x < n; x++){
        answers[x] = -1;
        used[x] = 1;
    }
    for (int x = 0; x < m; x++){
        cin >> a >> b;
        cons[a - 1].push_back(b - 1);
        cons[b - 1].push_back(a - 1);
    }

    for (int x = 0; x < n; x++){
        if (used[x] == 1){
            dfs(x, 0);
        }
    }
    if (answer){
        for (int x = 0; x < n; x++){
            cout << answers[x] << " ";
        }
    }
    else{
        cout << "IMPOSSIBLE\n";
    }
}
