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

ll used[100001];
ll moves = 0;
vector<int> cons[100001];
void dfs(int cur){
    used[cur] = 1;
    ll am = cons[cur].size() -1;
    if (cur == 0){
        am += 1;
    }
    ll pow2 = 1;
    ll cnt = 0;
    while(pow2 <= am){
        pow2 *= 2;
        cnt+=1;
    }
    moves += cnt;
    for (int x = 0; x < cons[cur].size(); x++){
        if (used[cons[cur][x]] == 2){
            moves += 1;
            dfs(cons[cur][x]);
        }
    }
}
int main(){
    cin >> n;
    int one, two;
    for (int x = 0; x < n - 1; x++){
        used[x] = 2;
        cin >> one >> two;
        cons[one - 1].push_back(two - 1);
        cons[two - 1].push_back(one - 1);
    }
    used[n - 1] = 2;
    dfs(0);
    cout << moves << "\n";

}
