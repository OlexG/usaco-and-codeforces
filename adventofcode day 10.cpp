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


int main(){
    ifstream in("in.txt");
    vector<int> jolts;
    int temp;
    jolts.push_back(0);
    for (int x = 0; x < 102; x++){
        in >> temp;
        jolts.push_back(temp);
    }
    sort(jolts.begin(), jolts.end());
    long long dp[jolts.size()];
    for (int x = 1; x < jolts.size(); x++){
        dp[x] = 0;
    }
    dp[0] = 1;
    for (int x = 1; x <= jolts.size(); x++){
        for (int y = 0; y < x; y++){
            if (jolts[x] - jolts[y] <= 3){
                dp[x] += dp[y];
            }
        }
    }
    cout << dp[102];

}
