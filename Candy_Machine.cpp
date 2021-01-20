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

pair<ll, ll> arr[100001];
vector<ll> st;
vector<ll> dp;
vector<ll> dp2;
vector<pair<int, int>> an[100001];

int main(){
    cin >> n;
    ll one, two;
    for (int x = 0; x < n; x++){
        cin >> one >> two;
        arr[x] = {two, one};
    }
    sort(arr, arr + n);



}
