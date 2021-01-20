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
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
template <class T> using Tree = tree<T, null_type, less<T>,
	rb_tree_tag, tree_order_statistics_node_update>;

int t;
int n;
struct point{
    ll c;
    ll t;
    ll w;
};

bool csortp(point a, point b){
    if (a.c == b.c){
        return a.t < b.t;
    }
    else{
        return a.c < b.c;
    }
}
int main(){
    cin >> t;
    for (int z = 0; z < t; z++){
        cin >> n;
        vector<pair<ll,ll>> segs;
        ll one, two;
        for (int x = 0; x < n; x++){
            cin >> one >> two;
            segs.push_back(make_pair(one, two));
        }
        sort(segs.begin(), segs.end());
        ll curc = 0;
        ll answer = n - 1;
        ll cur = 1;
        set<ll> starts;
        for (int x = 0; x < segs.size(); x++){
            starts.insert(segs[x].first);
        }
        starts.insert(segs[0].second);
        for (int x = 0; x < segs.size(); x++){

        }
        cout << answer << "\n";
    }
}
