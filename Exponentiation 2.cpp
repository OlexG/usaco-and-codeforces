#include <fstream>
#include <string>
#include <iostream>
#include <math.h>
#include <algorithm>
#include<bits/stdc++.h>
#include <vector>
using namespace std;
long long mod = 1000000007;

unsigned long long powmod(unsigned long long a,unsigned long long b) {unsigned long long res=1;a%=mod; assert(b>=0); for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
int n;

int main(){
    cin >> n;
    unsigned long long a, b, c;
    for (int x = 0; x < n; x++){
        cin >> a >> b >> c;
        long long power = c * a;
        long long answer = powmod(b, power);
        cout << answer << "\n";

    }

}

