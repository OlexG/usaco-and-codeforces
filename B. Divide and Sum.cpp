#include <fstream>
#include <string>
#include <iostream>
#include <math.h>
#include <algorithm>
#include<bits/stdc++.h>
#include <vector>
using namespace std;

int n;
long long mod = 998244353;
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
    long long fac[n + 1];
    fac[0] = 1;
    for (int i = 1; i <= n; i++){
        fac[i] = (fac[i - 1] * i) % mod;
    }

    return (fac[n] * modinv(fac[r]) % mod * modinv(fac[n - r]) % mod) % mod;
}


int main(){
    cin >> n;
    vector<int> first;
    vector<int> second;
    int temp;
    for (int x = 0; x < n; x++){
        cin >> temp;
        first.push_back(temp);
    }
    sort(first.begin(), first.end());
    for (int x = n; x < 2 * n; x++){
        cin >> temp;
        second.push_back(temp);
    }
    sort(second.rbegin(), second.rend());
    long long dif = 0;
    for (int x = 0; x < n; x++){
        dif += abs(second[x] - first[x]);
        dif %= mod;
    }
    long long answer = (ncrferm(2 * n, n) * dif) % mod;
    cout << answer << "\n";

}
