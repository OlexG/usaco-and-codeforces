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

ll mod = 1e9 + 7;
ll n, m, k;
ll dp[1000001];
long long powmod(long long a,long long b) {long long res=1;a%=mod; assert(b>=0); for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
int main(){
    ifstream in("spainting.in");
    ofstream out("spainting.out");
    in >> n >> m >> k;
    dp[0] = m;
    for (int x = 1; x < k - 1; x++){
        dp[x] = (dp[x - 1] * m) % mod;
    }
    for (int x = k - 1; x < n; x++){
        if (x == k - 1){
            dp[x] = (dp[x - 1] * m - m) % mod;
        }
        else{
            dp[x] = (dp[x - 1] * m - dp[x - k] * (m - 1)) % mod;
        }
        if (dp[x] < 0){
            while(dp[x] < 0){
                dp[x] += mod;
            }
        }
    }
    ll answer = powmod(m, n) - dp[n - 1];
    if (answer < 0){
        answer += mod;
    }
    out << answer << "\n";
}
