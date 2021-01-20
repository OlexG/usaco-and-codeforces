#include <fstream>
#include <string>
#include <iostream>
#include <math.h>
#include <algorithm>
#include<bits/stdc++.h>
#include <vector>
using namespace std;
long long cbits(long long number)
{
      return (int)log2(number);
}
long long powb(long long a,long long b) {long long res=1;a ; assert(b>=0); for(;b;b>>=1){if(b&1)res=res*a;a=a*a;}return res;}

int t;
long long d, m;

int main(){
    cin >> t;
    for (int z = 0; z < t; z++){
        cin >> d >> m;
        int n = cbits(d) + 1;
        long long pref[n];
        for (int x = 0; x < n - 1; x++){
            pref[x] = powb(2, x);
        }
        pref[n - 1] = d - powb(2, n - 1) + 1;
        long long answers[n];
        answers[n - 1] = pref[n - 1];

        for (int x = n - 1; x >= 0; x--){
            answers[x] = pref[x];
            for (int y = n - 1; y > x; y--){
                answers[x] += (pref[x] * answers[y]);
                answers[x] %= m;
            }
        }
        long long banswer = 0;
        for (int x = 0; x < n; x++){
            //cout << answers[x] << "\n";
            banswer += answers[x];
            banswer %= m;
        }
        cout << banswer << "\n";


    }
}
