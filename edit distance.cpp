#include <fstream>
#include <string>
#include <iostream>
#include <bitset>
#include <math.h>
#include <algorithm>
#include<bits/stdc++.h>
#include <vector>
using namespace std;

string a, b;

int main(){
    cin >> a >> b;

    int dp[a.size() + 1][b.size() + 1];
    for (int x = 0; x < b.size() + 1; x++){
        dp[0][x] = x;
    }
    for (int x = 0; x < a.size() + 1; x++){
        dp[x][0] = x;
    }
    for (int x = 1; x < a.size() + 1; x++){
        for (int y = 1; y < b.size() + 1; y++){
            dp[x][y] = 100000;
        }
    }
    for (int x = 1; x < a.size() + 1; x++){
        for (int y = 1; y < b.size() + 1; y++){
            if (a[x - 1] == b[y - 1]){
                dp[x][y] = min(dp[x - 1][y - 1], dp[x][y]);
            }
            dp[x][y] = min(dp[x][y], dp[x - 1][y] + 1);
            dp[x][y] = min(dp[x][y], dp[x][y - 1] + 1);
            dp[x][y] = min(dp[x][y], dp[x - 1][y - 1] + 1);
        }
    }
    /*for (int x = 0; x < a.size() + 1; x++){
        for (int y = 0; y < b.size() + 1; y++){
            cout << dp[x][y];
        }
        cout << "\n";
    }*/
    cout << dp[a.size()][b.size()] << "\n";
}
