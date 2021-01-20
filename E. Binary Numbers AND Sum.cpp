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

ll mod = 998244353;
long long powmod(long long a,long long b) {long long res=1;a%=mod; assert(b>=0); for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}

ll n, m;
string a, b;
int main(){
    cin >> n >> m;
    cin >> a >> b;
    ll sum[m];
    sum[m - 1] = (b[0] == '1');
    for (int x = m - 2; x >= 0; x--){
        sum[x] = sum[x + 1] + (b[m - x - 1] == '1');
    }
    long long answer = 0;
    for (int x = n - 1; x >= 0; x--){
        if (x < m && a[n - x - 1] == '1'){
            //cout << x << "\n";
            answer += (sum[x] * powmod(2, x) % mod);
            answer %= mod;
        }
    }
    cout << answer << "\n";
}
