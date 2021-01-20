#include <fstream>
#include <string>
#include <iostream>
#include <math.h>
#include <algorithm>
#include<bits/stdc++.h>
#include <vector>
using namespace std;
long long mod = 998244353;
int n, k;
long long fac[500001];


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
    fac[0] = 1;
    for (int i = 1; i <= n; i++){
        fac[i] = (fac[i - 1] * i) % mod;
    }
    long long answer = 0;
    for (int x = 1; x <= n; x++){
        long long amount = n/x;
        answer += ncrferm(n/x - 1, k - 1);
        answer %= mod;
    }
    cout << answer << "\n";

}
