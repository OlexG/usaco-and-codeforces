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

ll n;
ll x1, yy1, x2, y2;
pair<ll,ll> pos[100005];
pair<ll, pair<ll, ll>> arr[100005];

map<ll, set<ll>> consx;
map<ll, set<ll>> consy;
int used[100005];

int main(){
    ifstream in("lasers.in");
    ofstream out("lasers.out");
    in >> n >> x1 >> yy1 >> x2 >> y2;
    ll one, two;
    arr[0] = {0, {x1, yy1}};
    arr[n + 1] = {n + 1, {x2, y2}};
    for (int x = 0; x < n; x++){
        in >> one >> two;
        pos[x + 1] = {one, two};
        arr[x + 1] = {x + 1, {one, two}};
    }

    for (int x = 1; x <= n + 1; x++){
        consx[arr[x].second.first].insert(arr[x].first);
        consy[arr[x].second.second].insert(arr[x].first);
    }
    for (int x = 0; x < n + 5; x++){
        used[x] = 2;
    }

    queue<pair<int, int>> q;
    q.push({0,0});
    int answer = -1;
    while(q.size() > 0){
        pair<int, int> cur = q.front();
        q.pop();
        used[cur.first] = 1;
        if (cur.first == n + 1){
            answer = cur.second;
            break;
        }
        vector<int> td;
        for (auto it: consx[arr[cur.first].second.first]){
            if (used[it] == 2){
                q.push({it, cur.second + 1});
                td.push_back(it);
                used[it] = 1;
            }
        }
        for (auto it: consy[arr[cur.first].second.second]){
            if (used[it] == 2){
                q.push({it, cur.second + 1});
                td.push_back(it);
                used[it] = 1;
            }
        }
        for (int x = 0; x < td.size(); x++){
            consx[arr[td[x]].second.first].erase(td[x]);
        }
        for (int x = 0; x < td.size(); x++){
            consy[arr[td[x]].second.second].erase(td[x]);
        }
    }
    out << answer - 1 << "\n";


}
