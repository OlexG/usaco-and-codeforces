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
using namespace std;

long long n, m, k;
long long arr[101][101];
long long mod = 1000000007;
int main(){
    ifstream in("hopscotch.in");
    ofstream out("hopscotch.out");
    in >> n >> m >> k;
    long long dp[n][m];
    for (int x = 0; x < n; x++){
        for (int y = 0; y < m; y++){
            dp[x][y] = 0;
            in >> arr[x][y];
        }
    }
    dp[0][0] = 1;
    for (int x = 0; x < n; x++){
        for (int y = 0; y < m; y++){
            for (int z = 0; z < x; z++){
                for (int c = 0; c < y; c++){
                    if (arr[x][y] != arr[z][c]){
                        dp[x][y] += dp[z][c];
                        dp[x][y] %= mod;
                    }
                }
            }
        }
    }
    out << dp[n - 1][m - 1] << "\n";
}
