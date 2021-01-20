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
#include<stdio.h>
#include<ctype.h>
#define ll long long
using namespace std;

int n, m;
int pows2[31];
multiset<int> arr;
int fit[1000001];

int main(){
    cin >> n >> m;
    int temp;
    pows2[0] = 1;
    for (int x = 1; x <= 30; x++){
        pows2[x] = pows2[x - 1] * 2;
    }
    for (int x = 0; x < n; x++){
        cin >> temp;
        arr.insert(temp);
    }
    for (int x = 0; x < m; x++){
        cin >> temp;
        fit[x] = temp;
    }
    sort(fit, fit + m);
    for (int x = 0; x < m; x++){
        fit[x] = pows2[fit[x]];
    }
    int p = 0;
    ll answer = 0;
    for (int x = 0; x < m; x++){
        if (arr.lower_bound(fit[x]) == arr.end()){
            break;
        }
        ll cur = *arr.lower_bound(fit[x]);
        if (cur >= fit[x]){
            arr.erase(arr.find(cur));
            cur -= fit[x];
            arr.insert(cur);
            answer++;
        }
    }
    cout << answer << "\n";


}
