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

int n;
int arr[101];
int dp1[101][101];
//starting, ending;
int dp2[101][101];
//current player starting, ending;
int main(){
    cin >> n;
    for (int x = 0; x < n; x++){
        cin >> arr[x];
    }
    for (int x = 0; x < n; x++){
        for (int y = 0; y < n; y++){
            dp1[x][y] = 0;
            dp2[x][y] = 0;
        }
        if (n % 2 == 0){
            dp2[x][x] = arr[x];
        }
        else{
            dp1[x][x] = arr[x];
        }
    }
    for (int s = 1; s < n; s++){
        for (int x = n - s - 1; x >= 0; x--){
            int y = x + s;
            if ((n - (y - x)) % 2 == 0){
                if (dp1[x + 1][y] > dp1[x][y - 1]){
                    dp2[x][y] = dp2[x][y - 1] + arr[y];
                    dp1[x][y] = dp1[x][y - 1];
                }
                else{
                    dp2[x][y] = dp2[x + 1][y] + arr[x];
                    dp1[x][y] = dp1[x + 1][y];
                }
                //dp2[x][y] = max(dp1[x + 1][y] + arr[x], dp1[x][y - 1] + arr[y]);
            }
            else{
                if (dp2[x + 1][y] > dp2[x][y - 1]){
                    dp1[x][y] = dp1[x][y - 1] + arr[y];
                    dp2[x][y] = dp2[x][y - 1];
                }
                else{
                    dp1[x][y] = dp1[x + 1][y] + arr[x];
                    dp2[x][y] = dp2[x + 1][y];
                }
            }
        }
    }
    cout << dp1[0][n - 1] << " ";
    cout << dp2[0][n - 1] << "\n";

}
