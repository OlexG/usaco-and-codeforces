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


ll n, m;
struct con{
    ll d;
    ll color;
    ll cost;
};

map<ll, vector<con>> cons[100001];
map<ll, ll> cost[100001];
// how much to convert all nodes of a color to some other color

map<ll, ll> dist[100001];
ll dist2[100001];



int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> m;
    ll one, two, three;
    ll four;
    for (int x = 0; x < m; x++){
        cin >> one >> two >> three >> four;
        cons[one - 1][three].push_back({two - 1, three, four});
        cons[two - 1][three].push_back({one - 1, three, four});
    }
    for (int x = 0; x < n; x++){
        for (auto& i : cons[x]) {
            for (auto con: i.second){
                ll col = con.color;
                ll cst = con.cost;
                if (cost[x].find(col) == cost[x].end()){
                    cost[x][col] = cst;
                } else {
                    cost[x][col] += cst;
                }
            }
        }
        dist2[x] = 1e18;
    }
    priority_queue<tuple<ll, ll, ll>> q;
    //cost, node, color
    q.push(make_tuple(0, 0, 0));
    dist2[0] = 0;
    while(q.size() > 0){
        ll node;
        ll cst;
        ll color;
        tie(cst, node, color) = q.top();
        cst *= -1;
        q.pop();

        if (color != 0){
            if (cst != dist[node][color]){
                continue;
            }
            //we need to go to a node with the same color
            for (auto con: cons[node][color]){
                if (con.color == color){
                    ll ncost = cst + cost[node][color] - con.cost;
                    if (dist2[con.d] > ncost){
                        dist2[con.d] = ncost;
                        q.push(make_tuple(-1 * ncost, con.d, 0));
                    }
                }
            }
        }
        else{
            if (cst != dist2[node]){
                continue;
            }
            //there are 3 things which we can do
            for (auto& i : cons[node]) {
                for (auto con: i.second){
                    //switch everything but the connection
                    ll ncost = cst + cost[node][con.color] - con.cost;
                    if (dist2[con.d] > ncost){
                        dist2[con.d] = ncost;
                        q.push(make_tuple(-1 * ncost, con.d, 0));
                    }
                    //switch our node only
                    ncost = cst + con.cost;
                    if (dist2[con.d] > ncost){
                        dist2[con.d] = ncost;
                        q.push(make_tuple(-1 * ncost, con.d, 0));
                    }
                    //dont switch anything and make the next node switch
                    ncost = cst;
                    if (dist[con.d].find(con.color) == dist[con.d].end() || (dist[con.d][con.color] > ncost && ncost < dist2[con.d] && cost[con.d][con.color] > con.cost)){
                        dist[con.d][con.color] = ncost;
                        q.push(make_tuple(-1 * ncost, con.d, con.color));
                    }
                }
            }
        }
    }
    if (dist2[n - 1] == 1e18){
        cout << -1 << "\n";
    }
    else{
        cout << dist2[n - 1] << "\n";
    }
}
