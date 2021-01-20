#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#define fast ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0)

#include <fstream>
#include <string>
#include <iostream>
#include <math.h>
#include <algorithm>
#include<bits/stdc++.h>
#include <vector>
using namespace std;

long long n, c;

long long arr[1000001];
long long dp[1000001];
long long mod = 1e9 + 7;
int main(){
    cin >> n >> c;
    for (int x = 0; x < n; x++){
        cin >> arr[x];
    }
    dp[0] = 1;
    for (int x = 1; x <= c; x++){
        dp[x] = 0;
    }
    for (int y = 0; y < n; y++){
        for (int x = 1; x <= c; x++){
                if (x - arr[y] >= 0){
                    dp[x] += dp[x - arr[y]];
                    dp[x] %= mod;
                }
        }
    }
    cout << dp[c] << "\n";
}
