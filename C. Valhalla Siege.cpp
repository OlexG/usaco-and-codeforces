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


ll n, q;

ll arr[200001];

int main(){
    cin >> n >> q;
    for (int x = 0; x < n; x++){
        cin >> arr[x];
    }
    vector<ll> st;
    ll cursum = 0;
    for (int x = 0; x < n; x++){
        cursum += arr[x];
        st.push_back(cursum);
    }

    ll fired = 0;
    ll temp;
    for (int x = 0; x < q; x++){
        cin >> temp;
        if (st[st.size() - 1] <= fired + temp){
            fired = 0;
            cout << n << "\n";
        }
        else{
            auto cur = prev(upper_bound(st.begin(), st.end(), fired + temp));
            ll ind = st.end() - cur;
            if ((*(cur)) > fired + temp){
                cout << min(ind,n) << "\n";
            }
            else{
                 cout << ind - 1 << "\n";
            }
            fired += temp;
        }
    }
}
