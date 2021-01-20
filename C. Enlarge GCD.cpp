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

int n;
int ntocheck[3900];
int arr[300005];
int facs[15000005];
int isprime[15000005];
int smprime[15000005];

int lgcd;
long long gcd(long long a,long long b) { return b?gcd(b,a%b):a;}
long long powb(long long a,long long b) {long long res=1;a ; assert(b>=0); for(;b;b>>=1){if(b&1)res=res*a;a=a*a;}return res;}

int main(){
    cin >> n;
    for (int x = 0; x < 15000005; x++){
        facs[x] = 0;
        isprime[x] = 2;
        smprime[x] = x;
    }
    lgcd = arr[0];
    for (int x = 0; x < n; x++){
        cin >> arr[x];
        lgcd = gcd(lgcd, arr[x]);
    }

    isprime[1] = 1;
    for (int x = 2; x * x <= 15000005; x++){
        if (isprime[x] == 2){
            for (int y = x * x; y < 15000005; y+=x){
                if (isprime[y] == 2){
                    isprime[y] = 1;
                    smprime[y] = x;
                }
            }
        }
    }
    for (int x = 0; x < n; x++){
        arr[x] /= lgcd;
    }

    int curbest = n;
    for (int x = 0; x < n; x++){
        int cur = arr[x];
        int prevdiv = -1;
        while(smprime[cur] != cur){
            if (smprime[cur] != prevdiv){
                prevdiv = smprime[cur];
                facs[prevdiv] += 1;
            }
            cur /= smprime[cur];
        }
        if (cur != prevdiv){
            facs[cur] += 1;
        }
    }
    //cout << facs[5] << "\n";
    for (int x = 2; x < 15000005; x++){
        curbest = min(curbest, n - facs[x]);
    }
    //cout << curbest << "\n";
    if (curbest == n || curbest == 0){
        cout << -1 << "\n";
    }
    else{
        cout << curbest << "\n";
    }
}
