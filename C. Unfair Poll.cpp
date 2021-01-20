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
#define ll long long
using namespace std;

ll n, m;
ll k;
ll a, a2;
ll arr[101][101];
int main(){
    cin >> n >> m >> k >> a >> a2;
    ll ma = 0;
    ll mi = 1e18 + 1e9;
    if (n == 1){
        ll st = k / m;
        ll left = k % m;
        for (int x = 0; x < m; x++){
            arr[0][x] = st;
        }
        for (int x = 0; x < left; x++){
            arr[0][x] += 1;
        }
    }
    else{
        ll amount = (2 * n - 2) * m;
        ll st = k / amount;
        k %= amount;
        for (int x = 0; x < n; x++){
            for (int y = 0; y < m; y++){
                if (x != 0 && x != n - 1){
                    arr[x][y] = st * 2;
                }
                else{
                    arr[x][y] = st;
                }
            }
        }
        ll cnt = 0;
        if (k != 0){
            for (int x = 0; x < n; x++){
                for (int y = 0; y < m; y++){
                    arr[x][y] += 1;
                    cnt += 1;
                    if (cnt == k){
                        break;
                    }
                }
                if (cnt == k){
                    break;
                }
            }
            if (cnt != k){
                for (int x = n - 2; x >= 1; x--){
                    for (int y = 0; y < m; y++){
                        arr[x][y] += 1;
                        cnt += 1;
                        if (cnt == k){
                            break;
                        }
                    }
                    if (cnt == k){
                        break;
                    }
                }
            }
        }
    }
    for (int x = 0; x < n; x++){
        for (int y = 0; y < m; y++){
            ma = max(ma, arr[x][y]);
            mi = min(mi, arr[x][y]);
        }
    }

    cout << ma << " " << mi << " " << arr[a - 1][a2 - 1] << "\n";

}
