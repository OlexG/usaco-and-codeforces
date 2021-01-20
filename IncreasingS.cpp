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

ll n;
ll arr[200001];

int main(){
    cin >> n;
    for (int x = 0; x < n; x++){
        cin >> arr[x];
    }
    vector<int> dp;
    for (int x = 0; x < n; x++){
        int pos = lower_bound(dp.begin(), dp.end(), arr[x]) - dp.begin();
        if (pos == dp.size()){
            dp.push_back(arr[x]);
        }
        else{
            dp[pos] = arr[x];
        }
    }
    cout << dp.size() << "\n";

}
