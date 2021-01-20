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
ll mod = 1e9 + 9;
ll dp[1001][1001][11];
ll pref[1001][1001];
//number of pos teams that end on the xth and yth team being paired, and have z pairs
ll arr1[1001];
ll arr2[1001];
int main(){
    ifstream in("team.in");
    ofstream out("team.out");
    in >> n >> m >> k;
    for (int x = 0; x < n; x++){
        in >> arr1[x];
    }
    for (int y = 0; y < m; y++){
        in >> arr2[y];
    }
    sort(arr1, arr1 + n);
    sort(arr2, arr2 + m);

     for (int x = 0; x < n; x++){
        for (int y = 0; y < m; y++){
            for (int z = 0; z <= k; z++){
                dp[x][y][z] = 0;
            }
        }
    }

    for (int x = 0; x < n; x++){
        for (int y = 0; y < m; y++){
            if (arr1[x] > arr2[y]){
                dp[x][y][1] = 1;
            }
        }
    }

    ll answer = 0;
    for (int z = 2; z <= k; z++){
        pref[0][0] = dp[0][0][z - 1];
        for (int x = 1; x < n; x++){
            pref[x][0] = dp[x][0][z - 1] + pref[x - 1][0];
            pref[x][0] %= mod;
            assert(pref[x][0] >= 0);
        }
        for (int x = 1; x < m; x++){
            pref[0][x] = dp[0][x][z - 1] + pref[0][x - 1];
            pref[0][x] %= mod;
            assert(pref[0][x] >= 0);
        }
        for (int x = 1; x < n; x++){
            for (int y = 1; y < m; y++){
                pref[x][y] = dp[x][y][z - 1];
                pref[x][y] += pref[x - 1][y];
                pref[x][y] += pref[x][y - 1];
                pref[x][y] -= pref[x - 1][y - 1];
                pref[x][y] %= mod;
                pref[x][y] += mod;
                pref[x][y] %= mod;
                assert(pref[x][y] >= 0);
            }
        }

        for (int x = 1; x < n; x++){
            for (int y = 1; y < m; y++){
                if (arr1[x] > arr2[y]){
                    dp[x][y][z] = pref[x - 1][y - 1];
                }
                assert(dp[x][y][z] >= 0);
                if (z == k){
                    answer += dp[x][y][z];
                    assert(answer >= 0);
                    answer %= mod;
                }
            }
        }
    }
    out << answer << "\n";

}
