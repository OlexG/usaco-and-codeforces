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
int dp[101][101];
int arr[101];
//smallest differences using nth breakouts such that the first (second) breakout is on the yth number


int main(){
    ifstream in("taming.in");
    ofstream out("taming.out");
    for (int x = 0; x < 101; x++){
        for (int y = 0; y < 101; y++){
            dp[x][y] = 10000;
        }
    }
    in >> n;
    for (int x = 0; x < n; x++){
        in >> arr[x];
    }
    int cnt = 0;
    for (int x = 0; x < n; x++){
        if (arr[x] != x){
            cnt++;
        }
    }
    out << cnt << "\n";
    for (int x = 1; x < n; x++){
        int cnt = 0;
        int an = 0;
        for (int y = x; y < n; y++){
            if (y == x){
                cnt = 0;
            }
            if (arr[y] != cnt){
                an++;
            }
            cnt++;
        }
        dp[1][x] = an;
    }
    for (int x = 1; x < n; x++){
        int aout = 101;
        int cnt = 0;
        int curanswer = 0;
        for (int y = 1; y < n; y++){
            if (arr[y - 1] != cnt){
                curanswer++;
            }
            cnt++;
            aout = min(aout, dp[x][y] + curanswer);
        }
        out << aout << "\n";
        for (int z = 1; z < n; z++){
            int scnt = 0;
            int nanswer = 0;
            for (int y = z + 1; y < n; y++){
                if (arr[y - 1] != scnt){
                    nanswer++;
                }
                scnt++;
                dp[x + 1][z] = min(dp[x + 1][z], dp[x][y] + nanswer);
            }
        }
    }
}
