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


ll n, k, q;

int main(){
    cin >> n >> k >> q;
    int arr[200005];
    for (int x = 0; x < 200005; x++){
        arr[x] = 0;
    }
    ll one, two;
    for (int x = 0; x < n; x++){
        cin >> one >> two;
        arr[one] += 1;
        arr[two + 1] -= 1;
    }
    for (int x = 1; x < 200005; x++){
        arr[x] += arr[x - 1];
    }
    int pref[200005];
    for (int x = 0; x < 200005; x++){
        pref[x] = 0;
    }
    pref[0] = (arr[0] < k)?0:1;
    for (int x = 1; x < 200005; x++){
        if (arr[x] >= k){
            pref[x] = pref[x - 1] + 1;
        }
        else{
            pref[x] = pref[x - 1];
        }
    }
    for (int x = 0; x < q; x++){
        cin >> one >> two;
        if (one == 0){
            cout << pref[two] << "\n";
        }
        else{
            cout << pref[two] - pref[one - 1] << "\n";
        }
    }
}


