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
string s;
vector<pair<ll, ll>> cons[27];
ll best[27][27];
ll dp[100001][27];
//best value to change from x to n keys, such that the "streak" starts at x, and is with the yth letter
int main(){
    ifstream in("cowmbat.in");
    ofstream out("cowmbat.out");
    in >> n >> m >> k;
    in >> s;
    ll temp;
    for (ll x = 0; x < m; x++){
        for (ll y = 0; y < m; y++){
            in >> temp;
            cons[x].push_back({y, temp});
        }
    }
    for (ll x = 0; x < m; x++){
        ll used[m];
        ll bdt[m];
        for (ll y = 0; y < m; y++){
            used[y] = 2;
            bdt[y] = 10000;
        }
        bdt[x] = 0;
        for (ll y = 0; y < m; y++){
            ll curbdt = 10000;
            ll curb = -1;
            for (ll z = 0; z < m; z++){
                if (used[z] == 2){
                    if (bdt[z] < curbdt){
                        curbdt = bdt[z];
                        curb = z;
                    }
                }
            }
            used[curb] = 1;
            for (ll z = 0; z < cons[curb].size(); z++){
                bdt[cons[curb][z].first] = min(bdt[cons[curb][z].first], bdt[curb] + cons[curb][z].second);
            }
        }
        for (ll y = 0; y < m; y++){
            best[x][y] = bdt[y];
        }
    }

    for (ll y = 0; y < n; y++){
        for (ll z = 0; z < m; z++){
            dp[y][z] = 30000000001;
        }
    }
    ll cur[27];
    for (ll y = 0; y < m; y++){
        ll am = 0;
        for (ll x = n - k; x < n; x++){
            ll cur = s[x] - 'a';
            am += best[cur][y];
        }
        dp[n - k][y] = am;
        cur[y] = am;
        if (n - k - 1 >= 0){
            dp[n - k - 1][y] = dp[n - k][y] + best[s[n - k - 1] - 'a'][y];
        }

    }

    for (ll x = n - k - 1; x >= 0; x--){
        for (ll y = 0; y < m; y++){
            if (x + k < n){
                cur[y] -= best[s[x + k] - 'a'][y];
                cur[y] += best[s[x] - 'a'][y];
                for (ll b = 0; b < m; b++){
                    dp[x][y] = min(dp[x][y], dp[x + k][b] + cur[y]);
                }
            }
            ll am = 0;
            if (x > 0){
                am += best[s[x - 1] - 'a'][y];
                dp[x - 1][y] = dp[x][y] + am;
            }
        }
    }
    ll answer = 30000000001;
    for (ll x = 0; x < m; x++){
        answer = min(answer, dp[0][x]);
    }
    out << answer << "\n";


}
