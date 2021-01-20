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
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
#define ll long long
using namespace std;
using namespace __gnu_pbds;
/*
4
0 2
1 0
2 3
3 5
*/
int n;
vector<pair<int, int>> recs;

template <class T> using Tree = tree<T, null_type, less<T>,
	rb_tree_tag, tree_order_statistics_node_update>;


bool csort(pair<int, int> a, pair<int, int> b){
    if (a.second == b.second){
        return a.first < b.first;
    }
    else{
        return a.second < b.second;
    }
}
int main(){
    cin >> n;
    int one, two;
    for (int x = 0; x < n; x++){
        cin >> one >> two;
        recs.push_back(make_pair(one, two));
    }
    sort(recs.begin(), recs.end(), csort);

    ll answer = 0;
    for (int x = 0; x < n; x++){
        answer++;
        Tree<int> curp;
        Tree<int> curpneg;
        curp.insert(recs[x].first);
        curpneg.insert(-1 * recs[x].first);
        for (int y = x - 1; y >= 0; y--){
            ll aml = 0;
            ll amr = 0;
            curp.insert(recs[y].first);
            curpneg.insert(-1 * recs[y].first);
            aml = curp.order_of_key(min(recs[x].first, recs[y].first));
            amr = curpneg.order_of_key(min(-1 * recs[x].first, -1 * recs[y].first));
            //cout << aml << " " << amr << "\n";
            answer += (aml * amr + aml + amr);
            answer += 1;
        }
        //cout << answer << "\n";
    }
    cout << answer + 1 << "\n";
}
