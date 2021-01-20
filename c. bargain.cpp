#include <fstream>
#include <string>
#include <iostream>
#include <math.h>
#include <algorithm>
#include<bits/stdc++.h>
#include <vector>
using namespace std;

long long tens[100000];
long long twos[100000];
long long mod = 1000000007;
long long calc[10][100000];

int main(){
    string s;
    cin >> s;
    int n = s.size();
    tens[0] = 1;
    twos[0] = 1;
    for (int x = 1; x < n; x++){
        tens[x] = (10 * tens[x - 1]) % mod;
        twos[x] = (2 * twos[x - 1]) % mod;
    }
    for (int x = 0; x < 10; x++){
        calc[x][0] = 1 * x;
        for (int y = 1; y < n; y++){
            calc[x][y] = ((calc[x][y - 1]) + (tens[y] * (y + 1)) % mod * x) % mod;
        }
    }
    long long answer = 0;
    for (long long x = n - 1; x >= 0; x--){
        long long ind = s[x] - '0';
        if (x != n - 1){
            //cout << calc[ind][n - 1 - x - 1] << "here \n";
            answer = (answer + (calc[ind][n - 1 - x - 1])) % mod;
        }
        answer = (answer + ((ind * tens[n - 1 - x]) % mod) * ((x * (x + 1)/2) % mod)) % mod;
        //cout << answer << "\n";
    }

    cout << answer << "\n";
}
