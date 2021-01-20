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
ll t, k;
int ma = 100001;
ll sums[100001];
ll rways[100001];
ll wways[100001];
int main(){
    cin >> t >> k;
    rways[0] = 0;
    wways[0] = 1;
    rways[1] = 1;
    if (k == 1){
        wways[1] = 1;
    }
    else{
        wways[1] = 0;
    }
    for (int x = 2; x < ma; x++){
        rways[x] = wways[x - 1] + rways[x - 1];
        if (x - k >= 0){
            wways[x] = rways[x - k] + wways[x - k];
        }
        rways[x] %= mod;
        wways[x] %= mod;
    }

    sums[0] = rways[0] + wways[0];
    for (int x = 1; x < ma; x++){
        sums[x] = (sums[x - 1] + rways[x]) % mod + wways[x];
        sums[x] %= mod;
        //cout << sums[x] << "\n";
    }
    //cout << t << "\n";
    ll a, b;
    //ll answers[t];
    for (int x = 0; x < t; x++){
        //cout << "yes\n";
        cin >> a >> b;
        cout << ((sums[b] - sums[a - 1] + mod) % mod) << "\n";
    }
}
