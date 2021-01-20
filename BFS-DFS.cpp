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

int arr1[4100];
int arr2[4100];
int used[4100][4100];;
int main(){
    cin >> n;
    for (int x = 0; x < n; x++){
        cin >> arr1[x];
    }
    for (int x = 0; x < n; x++){
        cin >> arr2[x];
    }
    for (int x = 0; x <= n; x++){
        for (int y = 0; y <= n; y++){
            used[x][y] = -1;
        }
    }
    if (n == 1){
        cout << 0 << "\n";
        return 0;
    }
    if (arr1[1] != arr2[1]){
        cout << -1 << "\n";
        return 0;
    }
    vector<pair<int, int>> st;
    for (int x = 1; x < n; x++){
        if (used[arr2[x - 1]][arr2[x]] == -1){
            st.push_back({arr2[x - 1], arr2[x]});
            used[arr2[x - 1]][arr2[x]] = 1;
        }
    }
    for (int x = 1; x < n; x++){
        if (used[1][arr1[x]] == -1){
            st.push_back({1, arr1[x]});
        }
    }
    cout << st.size() << "\n";
    for (int x = 0; x < st.size(); x++){
        cout << st[x].first << " " << st[x].second << "\n";
    }

}
