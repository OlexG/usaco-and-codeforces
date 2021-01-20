#pragma GCC optimize("O2")
#include <fstream>
#include <string>
#include <iostream>
#include <bitset>
#include <math.h>
#include <string>
#include <algorithm>
#include<bits/stdc++.h>
#include <vector>
#include <queue>
using namespace std;

int t;
int n;

vector<int> cons[200001];
int md[200001];
int mind[200001];
int used[200001];

void dfs(int cur){
    used[cur] = 1;
    if (cons[cur].size() == 1){
        md[cur] = 0;
        mind[cur] = 0;
    }
    for (int x = 0; x < cons[cur].size(); x++){
        if (used[cons[cur][x]] == 2 && cons[cur][x] != 0){
            dfs(cons[cur][x]);
            md[cur] = max(md[cur], md[cons[cur][x]] + 1);
            mind[cur] = min(mind[cur], mind[cons[cur][x]] + 1);
        }
    }
}
int main(){
    cin >> t;
    for (int z = 0; z < t; z++){
        cin >> n;
        int one, two;
        for (int x = 0; x < n; x++){
            cons[x].clear();
            md[x] = 0;
            mind[x] = 1000000;
            used[x] = 2;
        }
        for (int x = 0; x < n - 1; x++){
            cin >> one >> two;
            cons[one - 1].push_back(two - 1);
            cons[two - 1].push_back(one - 1);
        }
        int answer = 0;
        vector<pair<int, int>> st;
        vector<int> ost;
        for (int x = 0; x < cons[0].size(); x++){
            dfs(cons[0][x]);
            st.push_back(make_pair(md[cons[0][x]], mind[cons[0][x]]));

        }
        sort(st.begin(), st.end());
    }
}
