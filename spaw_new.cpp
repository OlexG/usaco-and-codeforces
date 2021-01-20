#include <fstream>
#include <string>
#include <iostream>
#include <math.h>
#include <algorithm>
#include<bits/stdc++.h>
#include <vector>
using namespace std;

int n, m, k;
int arr[100000];
int used[100000];
pair<int, int> ms[100000];
vector<vector<int>> loops;
void dfs(int cur){
    used[cur] = 2;
    loops[loops.size() - 1].push_back(cur);
    if (used[arr[cur]] == 1){
        dfs(arr[cur]);
    }
}
int main(){
    ifstream in("swap.out");
    ofstream out("swap.out");
    in >> n >> m >> k;
    int one, two;
    for (int x = 0; x < m; x++){
        in >> one >> two;
        ms[x] = make_pair(one - 1, two - 1);
    }
    for (int x = 0; x < n; x++){
        used[x] = 1;
        int cur = x;
        for (int y = 0; y < m; y++){
            if (cur >= ms[y].first && cur <= ms[y].second){
                cur = ms[y].second - (cur - ms[y].first);
            }
        }
        arr[x] = cur;
    }
    for (int x = 0; x < n; x++){
        if (used[x] == 1){
            loops.push_back({});
            dfs(x);
        }
    }
    int answers[n];
    for (int x = 0; x < loops.size(); x++){
        for (int y = 0; y < loops[x].size(); y++){
            answers[loops[x][(y + k) % loops[x].size()]] = loops[x][y];
        }
    }
    for (int x = 0; x < n; x++){
        out << answers[x] + 1 << "\n";
    }

}
