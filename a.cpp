#include <fstream>
#include <string>
#include <iostream>
#include <bitset>
#include <math.h>
#include <algorithm>
#include<bits/stdc++.h>
#include <vector>
using namespace std;

int t;
long long gcd(long long a,long long b) { return b?gcd(b,a%b):a;}
int main(){
    cin >> t;
    for (int z = 0; z < t; z++){
        long long n;
        cin >> n;
        long long moves = 0;
        while (n > 1){
            long long bdivisor = 0;
            if (n % 2 == 1){
                n--;
                moves++;
                continue;
            }
            for (long long x = 2; x * x <= n; x++){
                if (n % x == 0){
                    bdivisor = n/x;
                    break;
                }
            }
            if (bdivisor != 0){
                n /= bdivisor;
            }
            else{
                n -= 1;
            }
            moves++;
            //cout << n << "\n";
        }
        cout << moves << "\n";
    }
}
