#include <fstream>
#include <string>
#include <iostream>
#include <math.h>
#include <algorithm>
#include<bits/stdc++.h>
#include <vector>
using namespace std;

int n;
string s;
long long MOD = 1000000007;
int main(){
    cin >> n;
    cin >> s;
    long long qs = (long long)1;
    long long cs[n + 1];
    long long bs[n + 1];
    long long as[n + 1];
    cs[n] = 0;
    bs[n] = 0;
    as[n] = 0;
    for (int x = n - 1; x >= 0; x--){
        if (s[x] == 'c'){
            cs[x] = qs + cs[x + 1];
        }
        else if (s[x] == '?'){
            cs[x] = (qs + (cs[x + 1] * 3))% MOD;
            qs = (qs * (long long)3) % MOD;
        }
        else{
            cs[x] = cs[x + 1];
        }
        //cout << cs[x] << "\n";
    }

    for (int x = n - 1; x >= 0; x--){
        if (s[x] == 'b'){
            bs[x] = (cs[x + 1] + bs[x + 1]) % MOD;
        }
        else if (s[x] == '?'){
            bs[x] = (cs[x + 1] + (bs[x + 1] * 3)) % MOD;
        }
        else{
            bs[x] = bs[x + 1];
        }
    }

    for (int x = n - 1; x >= 0; x--){
        if (s[x] =='a'){
            as[x] = (as[x + 1] + bs[x + 1]) % MOD;
        }
        else if (s[x] == '?'){
            as[x] = (bs[x + 1] + (as[x + 1] * 3)) % MOD;
        }
        else{
            as[x] = as[x + 1];
        }
    }
    cout << as[0] << "\n";
}
