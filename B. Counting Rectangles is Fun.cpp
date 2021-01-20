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


int n, m, q;
int dp[45][45];
int arr[45][45];
int sum[45][45];
int main(){
    cin >> n >> m >> q;
    for (int x = 0; x <= m; x++){
        dp[0][x] = 0;
    }
    for (int x = 0; x <= n; x++){
        dp[x][0] = 0;
    }
    for (int x = 0; x < n; x++){
        string s;
        cin >> s;
        for (int y = 0; y < m; y++){
            arr[x][y] = s[y] - '0';
        }
    }
    for (int x = 0; x <= n; x++){
        sum[x][0] = 0;
    }
    for (int x = 0; x <= m; x++){
        sum[0][x] = 0;
    }
    for (int x = 1; x <= n; x++){
        for (int y = 1; y <= m; y++){
            sum[x][y] = arr[x - 1][y - 1] + sum[x - 1][y] + sum[x][y - 1] - sum[x - 1][y - 1];
        }
    }


    for (int x = 1; x <= n; x++){
        for (int y = 1; y <= m; y++){
            dp[x][y] = dp[x - 1][y] + dp[x][y - 1] - dp[x - 1][y - 1];
            if (arr[x - 1][y - 1] == 0){
                for (int z = 1; z <= x; z++){
                    for (int c = 1; c <= y; c++){
                        int cursum = sum[x][y] - sum[x][c - 1] - sum[z - 1][y] + sum[c - 1][z - 1];
                        if (cursum == 0){
                            dp[x][y] += 1;
                        }
                    }
                }
            }
        }
    }
    for (int x = 0; x <= n; x++){
        for (int y = 0; y <= m; y++){
            cout << dp[x][y] << " ";
        }
        cout << "\n";
    }
    int x1, y1, x2, y2;
    for (int x = 0; x < q; x++){
        cin >> x1 >> y1 >> x2 >> y2;
        cout << (dp[x2][y2] - dp[x2][y1 - 1] - dp[x1 - 1][y2] + dp[x1 - 1][y1 - 1]) << "\n";
    }


}
