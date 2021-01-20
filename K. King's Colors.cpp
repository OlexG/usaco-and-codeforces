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
using namespace std;

long long mod = 1000000007;

long long n, k;
vector<long long> cons[2501];
long long levels[2501];
long long amount[2501];
long long fac[2502];
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


int main(){
    cin >> n >> k;
    long long amount[n];
    long long amount2[k][n];
    fac[0] = 1;
    for (long long i = 1; i <= n; i++){
        fac[i] = (fac[i - 1] * i) % mod;
    }
    long long temp;
    amount[0] = k;
    for (long long x = 0; x < k; x++){
        amount2[x][0] = x;
    }
    for (long long x = 0; x < n - 1; x++){
        cin >> temp;
        cons[temp].push_back(x + 1);
    }

    for (long long x = 1; x < n; x++){
        amount[x] = amount[x - 1] * (k - 1);
        amount[x] %= mod;
        for (long long y = 0; y < k; y++){
            amount2[y][x] = amount2[y][x - 1] * (y - 1);
            amount2[y][x] %= mod;
        }
    }

    long long answer = amount[n - 1];
    long long cur[k + 1][k + 1];
    for (int x = 0; x <= k; x++){
        cur[x][0] = 1;
        cur[x][x] = 1;
    }
    for (int x = 1; x <= k; x++){
        for (int y = 1; y <= k; y++){
            if (y != x){
                cur[x][y] = (cur[x - 1][y - 1]) + (cur[x - 1][y]);
                cur[x][y] %= mod;
            }
        }
    }
    //cout << amount[n - 1] << "\n";
    for (long long x = 2; x < k; x++){
        answer -= ((amount2[x][n - 1] * cur[k][x]) % mod);
        //cout << answer << " " << x << "\n";

        for (long long y = x + 1; y < k; y++){
            amount2[y][n - 1] -= ((amount2[x][n - 1] * cur[y][x]) % mod);
            if (amount2[y][n - 1] < 0){
                amount2[y][n - 1] += mod;
            }
        }
        if (answer < 0){
            answer += mod;
        }
    }



    cout << answer % mod << "\n";

}
