#include <fstream>
#include <string>
#include <iostream>
#include <math.h>
#include <algorithm>
#include<bits/stdc++.h>
#include <vector>
using namespace std;

int n;
long long mod = 1e9 + 7;
long long fac[1000002];


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
    cin >> n;
    fac[0] = 1;
    for (int i = 1; i <= n; i++){
        fac[i] = (fac[i - 1] * i) % mod;
    }
    long long answer = 1;
    for (int x = n; x >= 2; x--){
        answer *= x;
        if (x > 10){
            answer %= mod;
        }
    }

    for (int x = 0; x < n; x++){
        //cout << ncrferm(n - 1, x) << "\n";
        answer -= ncrferm(n - 1, x);
    }
    answer %= mod;
    cout << answer << "\n";
}
