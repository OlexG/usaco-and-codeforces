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


ll n, m;
ll vert[100002];
ll hor[100001];
int main(){
    cin >> n >> m;
    for (int x = 0; x < n; x++){
        cin >> vert[x];
    }
    ll one, two, three;
    ll s = 0;
    for (int x = 0; x < m; x++){
        cin >> one >> two >> three;
        if (one == 1){
            hor[s] = two;
            s++;
        }
    }
    sort(hor, hor + s);
    vert[n] = 1e9;
    n += 1;
    sort(vert, vert + n);
    ll p1 = 0;
    ll answer = n + m;
    for (int x = 0; x < n; x++){
        while(vert[x] > hor[p1] && p1 < s){
            p1++;
        }
        //cout << vert[x] << " " << p1 << " " << hor[p1] << "\n";
        answer = min(answer, x + s - p1);
    }
    cout << answer << "\n";

}
