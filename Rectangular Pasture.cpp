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

struct Edge{
    char a;
    ll x;
    ll y;
};
int n;
vector<Edge> cowse;
vector<Edge> cowsn;

set<ll> cons[1001];
ll am[1001];
ll used[1001];

void dfs(ll cur){
    used[cur] = 1;
    am[cur] += cons[cur].size();
    for (int x = 0; x < cons[cur].size(); x++){
        if (used[cons[cur][x]] == 2){
            dfs(cons[cur][x]);
            am[cur] += am[cons[cur][x]];
        }
    }
}


int main(){
    cin >> n;
    char one;
    ll two;
    ll three;
    for (int x = 0; x < n; x++){
        cin >> one;
        cin >> two;
        cin >> three;
        if (one == 'E'){
            cowse.push_back({one, two, three});
        }
        else{
            cowsn.push_back({one, two, three});
        }
        am[x] = 0;
        used[x] = 2;
        stoped[x] = make_pair(-1, 10000000000000);
    }


}
