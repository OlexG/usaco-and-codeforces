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
#include<stdio.h>
#include<ctype.h>
#define ll long long
using namespace std;
ll mod = 998244353;
ll a, b, c;

ll ab;
ll bc;
ll ca;
long long fac[5001];

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


ll calc(ll one, ll two){
    if (one > two){
        ll temp = two;
        two = one;
        one = temp;
    }
    ll answer = 1;
    for (int x = 1; x <= one; x++){
        ll curanswer = 1;
        for (int y = two; y > two - x; y--){
            curanswer *= y;
            curanswer %= mod;
        }
        curanswer *= ncrferm(one, x);
        curanswer %= mod;
        answer += curanswer;
        answer %= mod;
    }
    return answer;
}
int main(){
    cin >> a >> b >> c;
    fac[0] = 1;
    for (int i = 1; i <= 5001; i++){
        fac[i] = (fac[i - 1] * i) % mod;
    }
    ab = calc(a,b);
    bc = calc(b,c);
    ca = calc(c,a);
    ll fanswer = (ab * bc) % mod * ca % mod;
    cout << fanswer << "\n";


}
