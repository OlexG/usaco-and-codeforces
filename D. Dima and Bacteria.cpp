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

ll n, m, k;
ll group[100005];
ll used[100005];
ll rused[100005];
ll best[500][500];
ll o;
vector<ll> gr;
vector<pair<ll, ll>> cons[100005];
set<pair<ll, ll> > gcons[100005];

void dfs(ll cur){
    if (group[o] == group[cur]){
        rused[cur] = 1;
        //cout << cur << "\n";
    }
    used[cur] = 1;
    for (int x = 0; x < cons[cur].size(); x++){
        if (used[cons[cur][x].first] == 2 && cons[cur][x].second == 0){
            dfs(cons[cur][x].first);
        }
    }
}
int main(){
    cin >> n >> m >> k;
    ll p = 0;
    ll temp;
    ll cnt = 0;
    for (int x = 0; x < k; x++){
        cin >> temp;
        gr.push_back(temp);
        while(temp > 0){
            group[p] = cnt;
            p++;
            temp--;
        }
        cnt++;
    }
    for (int x = 0; x < n; x++){
        used[x] = 2;
        rused[x] = 2;
        //cout << group[x] << " ";
    }
    //cout << "\n";
    ll one, two, three;
    for (int x = 0; x < m; x++){
        cin >> one >> two >> three;
        cons[one - 1].push_back({two - 1, three});
        cons[two - 1].push_back({one - 1, three});
        auto it = gcons[group[one - 1]].lower_bound({group[two - 1], -1});
        if (group[one - 1] != group[two - 1]){
            if (it != gcons[group[one - 1]].end()){
                if (three < (*(it)).second && (*(it)).first == group[two - 1]){
                    gcons[group[one - 1]].erase(it);
                    gcons[group[two - 1]].erase(gcons[group[two - 1]].lower_bound({group[one - 1], -1}));
                    gcons[group[one - 1]].insert({group[two - 1], three});
                    gcons[group[two - 1]].insert({group[one - 1], three});
                }
                else if ((*(it)).first != group[two - 1]){
                    gcons[group[one - 1]].insert({group[two - 1], three});
                    gcons[group[two - 1]].insert({group[one - 1], three});
                }
            }
            else{
                gcons[group[one - 1]].insert({group[two - 1], three});
                gcons[group[two - 1]].insert({group[one - 1], three});
            }
        }
    }
    ll cur = 0;
    for (int x = 0; x < gr.size(); x++){
        if (rused[cur] == 2){
            for (int x = 0; x < n; x++){
                used[x] = 2;
        //cout << group[x] << " ";
            }
            o = cur;
            dfs(cur);
            int p1 = cur;
            int p2 = cur;
            for (int y = cur; y < cur + gr[x]; y++){
                if (rused[y] == 2){
                    cout << "No\n";
                    return 0;
                }
            }
            cur += gr[x];
        }
    }

    /*for (int x = 0; x < k; x++){
        for (auto con: gcons[x]){
            cout << con.first << " " << con.second << "\n";
        }
    }*/
    cout << "Yes\n";
    for (int x = 0; x < gr.size(); x++){
        ll used[gr.size()];
        ll bdt[gr.size()];
        for (int y = 0; y < gr.size(); y++){
            bdt[y] = -1;
            used[y] = 2;
        }
        bdt[x] = 0;
        for (int y = 0; y < gr.size(); y++){
            ll b = 100000000000000000;
            ll bi = -1;
            for (int z = 0; z < gr.size(); z++){
                if (used[z] == 2 && bdt[z] != -1){
                    if (bdt[z] < b){
                        b = bdt[z];
                        bi = z;
                    }
                }
            }
            if (bi == -1){
                break;
            }
            used[bi] = 1;
            for (auto con:gcons[bi]){
                ll des = con.first;
                ll cost = con.second;
                if (bdt[des] == -1){
                    bdt[des] = cost + bdt[bi];
                }
                else{
                    bdt[des] = min(bdt[des], cost + bdt[bi]);
                }
            }
        }
        for (int y = 0; y < gr.size(); y++){
            best[x][y] = bdt[y];
            best[y][x] = bdt[y];
        }
    }
    for (int x = 0; x < gr.size(); x++){
        for (int y = 0; y < gr.size(); y++){
            cout << best[x][y] << " ";
        }
        cout << "\n";
    }



}
