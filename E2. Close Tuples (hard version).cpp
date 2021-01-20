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
long long fac[200001];
long long powmod(long long a,long long b) {long long res=1;a%=mod; assert(b>=0); for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}

long long modinv(long long n){
    return powmod(n, mod - 2);
}
long long ncrferm(long long n, long long r){
    if (n < r){
        return 0;
    }
    if (r == 0){
        return 1;
    }

    return (fac[n] * modinv(fac[r]) % mod * modinv(fac[n - r]) % mod) % mod;
}

ll t;
ll n, m, k;

int main(){
    cin >> t;
    for (int z = 0; z < t; z++){
        cin >> n >> m >> k;
        fac[0] = 1;
        for (int i = 1; i <= n; i++){
            fac[i] = (fac[i - 1] * i) % mod;
        }
        ll arr[n];
        ll answer = 0;
        for (int x = 0; x < n; x++){
            cin >> arr[x];
        }
        sort(arr, arr + n);
        ll p1 = 0; ll p2 = -1;
        while(true){
            if (p2 >= n - 1){
                break;
            }
            if (arr[p2 + 1] - arr[p1] <= k){
                p2++;
                answer += ncrferm(p2 - p1, m - 1);
                answer %= mod;
            }
            else{
                p1++;
                if (p1 > p2 + 1){
                    break;
                }
            }
        }
        cout << answer << "\n";
    }
}
