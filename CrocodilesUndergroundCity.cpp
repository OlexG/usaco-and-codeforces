//created by Oleksandr Gorpynich
#pragma GCC optimize("O2")
#include <fstream>
#include <string>
#include <iostream>
#include <bitset>
#include <math.h>
#include <string>
#include <algorithm>
#include <assert.h>
#include <bits/stdc++.h>
#include <vector>
#include <queue>
#include<stdio.h>
#include<ctype.h>
#define ll long long
using namespace std;

ll n, m, k;
struct con{
    ll des;
    ll we;
};
/*
5 7 2
0 2 4
0 3 3
3 2 2
2 1 10
0 1 100
0 4 7
3 4 9
1 3 */
vector<con> cons[100002];
ll dist[100002][2];
ll used[100002][2];
ll one, two, three;

int main(){
    cin >> n >> m >> k;
    for (int x = 0; x < m; x++){
        cin >> one >> two >> three;
        cons[one].push_back({two, three});
        cons[two].push_back({one, three});
    }
    priority_queue<tuple<ll, ll, ll>> q;
    for (int x = 0; x <= n; x++){
        used[x][0] = 2; used[x][1] = 2;
        dist[x][0] = 1e9; dist[x][1] = 1e9;
    }
    for (int x = 0; x < k; x++){
        cin >> one;
        q.push(make_tuple(0, one, 0));
        q.push(make_tuple(0, one, 1));
        dist[one][0] = 0;
        dist[one][1] = 0;
        used[one][0] = 2;
        used[one][1] = 2;
    }
    while(q.size() > 0){
        ll cur;
        ll curdist;
        ll type;
        tie(curdist, cur, type) = q.top();
        curdist *= -1;
        q.pop();
        if (used[cur][type] == 2) {
            used[cur][type] = 1;
            if (type == 1){
                for (auto con: cons[cur]){
                    if (curdist + con.we <= dist[con.des][0]){
                        dist[con.des][1] = dist[con.des][0];
                        dist[con.des][0] = curdist + con.we;
                        if (dist[con.des][1] != 1e9) {
                            q.push(make_tuple(dist[con.des][1] * -1, con.des, 1));
                        }
                    }
                    else if (curdist + con.we < dist[con.des][1]){
                        dist[con.des][1] = curdist + con.we;
                        if (dist[con.des][1] != 1e9) {
                            q.push(make_tuple(dist[con.des][1] * -1, con.des, 1));
                        }
                    }
                }
            }
        }
    }
    cout << dist[0][1] << "\n";

}
