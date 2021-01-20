#include <fstream>
#include <string>
#include <iostream>
#include <bitset>
#include <math.h>
#include <algorithm>
#include<bits/stdc++.h>
#include <vector>
using namespace std;

int n;

char arr[1001][1001];
long long dp[1001][1001];
long long mod = 1e9 + 7;
int main(){
    cin >> n;
    for (int x = 0; x < n; x++){
        string s;
        cin >> s;
        for (int y = 0; y < n; y++){
            arr[x][y] = s[y];
        }
    }
    for (int x = 0; x < n; x++){
        for (int y = 0; y < n; y++){
            dp[x][y] = 0;
        }
    }
    dp[0][0] = 1;
    if (arr[0][0] == '*'){
        dp[0][0] = 0;
    }
    for (int x = 0; x < n; x++){
        for (int y = 0; y < n; y++){
            if (arr[x][y] != '*'){
                if (x - 1 >= 0){
                    dp[x][y] += dp[x-1][y];
                }
                if (y - 1 >= 0){
                    dp[x][y] += dp[x][y - 1];
                }
                dp[x][y] %= mod;
            }
        }
    }
    cout << dp[n - 1][n - 1] << "\n";
}
