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

int n;
vector<int> dp;
int temp;
int main(){
    cin >> n;
    for (int x = 0; x < n; x++){
        cin >> temp;
        int pos = upper_bound(dp.begin(), dp.end(), temp) - dp.begin();
        if (pos == dp.size()){
            dp.push_back(temp);
        }
        else{
            dp[pos] = temp;
        }
    }
    cout << dp.size() << "\n";
}
