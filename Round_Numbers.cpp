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

ll a, b;
ll dp[32][32];
int cbits(long long number)
{
      return (int)log2(number)+1;
}
//length of number, number of zeroes
int main(){
    cin >> b >> a;
    int la = cbits(a);
    int lb = cbits(b);
    string sa = bitset<31>(a).to_string();
    string sb = bitset<31>(b).to_string();

    for (int x = 0; x < 32; x++){
        for (int y = 0; y < 32; y++){
            dp[x][y] = 0;
        }
    }
    dp[1][0] = 1;
    dp[1][1] = 1;
    dp[0][0] = 1;
    dp[2][0] = 1;
    dp[2][1] = 2;
    dp[2][2] = 1;
    for (int x = 3; x < 32; x++){
        dp[x][0] = 1;
        for (int y = 1; y < 32; y++){
            dp[x][y] = dp[x - 1][y - 1] + dp[x - 1][y];
            if (y == x){
                break;
            }
        }
    }
    int t = 0;
    int s = 0;
    int ocnt = 0;
    int zcnt = 0;
    int n = la;
    //cout << sa << " " << sb << "\n";
    for (int x = sa.size() - la; x < sa.size(); x++){
        if (sa[x] == '0'){
            zcnt += 1;
        }
        if (sa[x] == '1'){
            ocnt += 1;
            int least;
            if (ocnt == 1){
                for (int z = sa.size() - x - 1; z >= 1; z--){
                    least = (z + 1)/2;
                    //cout << z << " " << least << "\n";
                    for (int y = least; y <= (z - 1); y++){
                        t += dp[z - 1][y];
                    }
                }
                t += 1;
            }
            else{
                //zcnt + x >= la - zcnt - x
                //x >= (la - 2 * znct)/2
                zcnt += 1;
                least = max((la - 2 * zcnt + 1)/2, 0);
                zcnt -= 1;
                for (int y = least; y <= (sa.size() - x - 1); y++){
                    t += dp[(sa.size() - x - 1)][y];
                }
            }
        }
    }
    //cout << t << "\n";
    zcnt = 0;
    ocnt = 0;
    n = lb;
    for (int x = sb.size() - lb; x < sb.size(); x++){
        if (sb[x] == '0'){
            zcnt += 1;
        }
        if (sb[x] == '1'){
            ocnt += 1;
            int least;
            if (ocnt == 1){
                for (int z = sb.size() - x - 1; z >= 1; z--){
                    least = (z + 1)/2;
                    //cout << z << " " << least << "\n";
                    for (int y = least; y <= (z - 1); y++){
                        s += dp[z - 1][y];
                    }
                }
                s += 1;
            }
            else{
                //zcnt + x >= la - zcnt - x
                //x >= (la - 2 * znct)/2
                zcnt += 1;
                least = max((lb - 2 * zcnt + 1)/2, 0);
                zcnt -= 1;
                for (int y = least; y <= (sb.size() - x - 1); y++){
                    s += dp[(sb.size() - x - 1)][y];
                }
            }
        }
    }
    int numz = 0;
    for (int x = 0; x < la; x++){
        if (sa[sa.size() - x - 1] == '0'){
            numz += 1;
        }
    }
    if (numz >= la - numz){
        t++;
    }
    cout << t - s << "\n";
}
