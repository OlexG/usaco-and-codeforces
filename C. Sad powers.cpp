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
#include <assert.h>
#include <queue>
#include<stdio.h>
#include<ctype.h>
#define ll long long
using namespace std;

long long powb(long long a,long long b) {long long res=1;a ; assert(b>=0); for(;b;b>>=1){if(b&1)res=res*a;a=a*a;}return res;}
ll q;
ll lim = 1e18 + 1;
vector<ll> squares;
set<ll> squaress;


ll upperbound(ll x){
    ll l = 0;
    ll t = 1e9 + 1;
    while (l < t){
        ll mid = (l + t)/(ll)2;
        if (x >= mid * mid){
            l = mid + 1;
        }
        else{
            t = mid;
        }
    }
    return (l - 1);
}

int main(){
    for (ll x = 3; x <= 60; x+=2){
        ll cnt = 2;
        while(true){
            if (pow(cnt, 0.5) == (double)round(pow(cnt,0.5))){
                cnt++;
                continue;
            }
            ll power = powb(cnt, x);
            if (power > lim){
                break;
            }
            if (squaress.find(power) == squaress.end()){
                squaress.insert(power);
                squares.push_back(power);
            }
            cnt++;
        }
    }

    sort(squares.begin(), squares.end());
    cin >> q;
    ll one, two;
    for (int x = 0; x < q; x++){
        cin >> one >> two;
        ll answer = upper_bound(squares.begin(), squares.end(), two) - lower_bound(squares.begin(), squares.end(), one);
        answer += (upperbound(two) - upperbound(one - 1));
        cout << answer << "\n";
    }

}


