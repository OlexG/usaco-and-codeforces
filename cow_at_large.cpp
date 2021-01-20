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

int n, k;
vector<int> cons[100001];
int used[100001];
int dtol[100001];

int main(){
    ifstream in("atlarge.in");
    ofstream out("atlarge.out");
    in >> n >> k;
    k = k - 1;
    int one, two;
    for (int x = 0; x < n - 1; x++){
        in >> one >> two;
        cons[one - 1].push_back(two - 1);
        cons[two - 1].push_back(one - 1);
        used[x] = 2;
    }
    used[n - 1] = 2;
    queue<int> q;
    for (int x = 0; x < n; x++){
        if (cons[x].size() == 1){
            dtol[x] = 0;
            used[x] = 1;
            q.push(x);
        }
    }
    while(q.size() > 0){
        int cur = q.front();
        used[cur] = 1;
        q.pop();
        for (int x = 0; x < cons[cur].size(); x++){
            if (used[cons[cur][x]] == 2){
                dtol[cons[cur][x]] = dtol[cur] + 1;
                used[cons[cur][x]] = 1;
                q.push(cons[cur][x]);
            }
        }
    }

    for (int x = 0; x < n; x++){
        used[x] = 2;
    }
    if (cons[k].size() == 1){
        cout << 1 << "\n";
        return 0;
    }
    used[k] = 1;
    queue<pair<int, int>> dq;
    dq.push({k, 0});
    int answer = 0;
    while(dq.size() > 0){
        int cur = (dq.front()).first;
        used[cur] = 1;
        int curdist = (dq.front()).second;
        dq.pop();
        if (dtol[cur] <= curdist){
            answer++;
        }
        else{
            for (int x = 0; x < cons[cur].size(); x++){
                if (used[cons[cur][x]] == 2){
                    dq.push({cons[cur][x], curdist + 1});
                    used[cons[cur][x]] = 1;
                }
            }
        }
    }
    out << answer << "\n";

}
