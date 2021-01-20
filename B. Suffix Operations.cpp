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

int t;
int n;
int main(){
    cin >> t;
    for (int z = 0; z < t; z++){
        cin >> n;
        vector<long long> st;
        long long temp;
        for (int x = 0; x < n; x++){
            cin >> temp;
            st.push_back(temp);
        }
        long long tanswer = 0;
        long long banswer = 10000000000000000;
        for (int x = n - 2; x >= 0; x--){
            tanswer += abs(st[x] - st[x + 1]);
        }
        //cout << tanswer << "\n";
        banswer = tanswer;
        for (int x = 1; x < n - 1; x++){
            long long curanswer = tanswer;
            curanswer -= abs(st[x] - st[x + 1]);
            curanswer -= abs(st[x - 1] - st[x]);
            curanswer += abs(st[x + 1] - st[x - 1]);
            banswer = min(banswer, curanswer);
        }
        banswer = min(banswer, tanswer - abs(st[0] - st[1]));
        banswer = min(banswer, tanswer - abs(st[n - 2] - st[n - 1]));
        cout << banswer << "\n";
    }
}
