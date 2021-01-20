#include <fstream>
#include <string>
#include <iostream>
#include <math.h>
#include <algorithm>
#include<bits/stdc++.h>
#include <vector>
using namespace std;

long long n, c;

long long arr[1000001];
long long dp[1000001];
int main(){
    cin >> n >> c;
    for (int x = 0; x < n; x++){
        cin >> arr[x];
    }
    dp[0] = 0;
    for (int x = 1; x <= c; x++){
        dp[x] = 2000001;
    }
    for (int x = 1; x <= c; x++){
        for (int y = 0; y < n; y++){
            if (x - arr[y] >= 0){
                dp[x] = min(dp[x], dp[x - arr[y]] + 1);
            }
        }
    }

    cout << (dp[c] <= 1000000?dp[c]:-1) << "\n";
}
