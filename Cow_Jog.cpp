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
using namespace std;

long long n, t;
pair<long long, long long> st[100001];
vector<pair<long long, long long>> se;
int main(){
    ifstream in("cowjog.in");
    ofstream out("cowjog.out");
    in >> n >> t;
    long long one, two;
    for (int x = 0; x < n; x++){
        in >> one >> two;
        st[x] = make_pair(one, two);
    }
    for (int x = 0; x < n; x++){
        se.push_back({st[x].first, st[x].first + (st[x].second * t)});
    }
    vector<long long> dp;
    sort(se.rbegin(), se.rend());
    for (int x = 0; x < n; x++){
        int pos = upper_bound(dp.begin(), dp.end(), se[x].second) - dp.begin();
        if (pos == dp.size()){
            dp.push_back(se[x].second);
        }
        else{
            dp[pos] = se[x].second;
        }
    }
    out << dp.size() << "\n";
}
