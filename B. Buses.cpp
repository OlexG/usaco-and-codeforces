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

ll mod = 1000000007;
bool csort(pair<ll,ll> a, pair<ll,ll>b){
    return a.second < b.second;
}
ll n, m;
ll sum[100005];
pair<ll,ll> arr[100005];
vector<ll> endings;

int main(){
    cin >> n >> m;
    ll one, two;
    for (ll x = 0; x < m; x++){
        cin >> one >> two;
        arr[x] = {one, two};
    }
    sort(arr, arr + m, csort);
    for (ll x = 0; x < m; x++){
        endings.push_back(arr[x].second);
        sum[x] = 0;
    }
    for (ll x = 0; x < m; x++){
        auto ending = prev(lower_bound(endings.begin(), endings.end(), arr[x].second));
        auto start = prev(lower_bound(endings.begin(), endings.end(), arr[x].first));
        ll am;
        if (lower_bound(endings.begin(), endings.end(), arr[x].first) == endings.begin()){
            am = ending - endings.begin() + 1;
        }
        else{
            am = ending - start;
        }
        ll findex = ending - endings.begin();
        assert(am >= 0);
        if (am != 0){
            if (findex - am < 0){
                sum[x] = ((sum[findex]) % mod + sum[x - 1]) % mod;
                sum[x] %= mod;
            }
            else{
                sum[x] = (sum[findex] - sum[findex - am] + mod) % mod + sum[x - 1];
                sum[x] %= mod;
            }
        }
        else{
            if (x != 0){
                sum[x] = sum[x] + sum[x - 1];
            }
        }
        if (arr[x].first == 0){
            sum[x] += 1;
        }

        sum[x] %= mod;
        //cout << sum[x] << "\n";
    }
    ll answer = 0;
    for (ll x = 0; x < m; x++){
        if (arr[x].second == n){
            if (x == 0){
                answer += sum[x];
            }
            else{

                answer += (sum[x] - sum[x - 1] + mod);
            }
            answer %= mod;
        }
    }
    cout << answer << "\n";

}
