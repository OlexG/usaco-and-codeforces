#include <fstream>
#include <string>
#include <iostream>
#include <math.h>
#include <algorithm>
#include<bits/stdc++.h>
#include <vector>
using namespace std;
long long powb(long long a,long long b) {long long res=1;a ; assert(b>=0); for(;b;b>>=1){if(b&1)res=res*a;a=a*a;}return res;}
int t;
long long p, q;
int main(){
    cin >> t;
    for (int z = 0; z < t; z++){
        cin >> p >> q;
        if (p < q){
            cout << p << "\n";
            continue;
        }
        long long sprime = -1;
        vector<pair<int, int>> primes;
        long long qc = q;
        for (int x = 2; x * x <= qc; x++){
            if (qc % x == 0){
                primes.push_back(make_pair(x, 0));
                while(qc % x == 0){
                    qc = qc/x;
                    primes[primes.size() - 1].second ++;
                }
            }
        }
        if (qc > 1){
            primes.push_back(make_pair(qc, 1));
        }
        long long banswer = 1;
        primes.push_back(make_pair(q, 1));
        for (int x = 0; x < primes.size(); x++){
            //cout << primes[x].first << " " << primes[x].second << "\n";
            long long pc = p;
            int counter = 0;
            while(pc % primes[x].first == 0){
                pc /= primes[x].first;
                counter++;
                if (pc < q){
                    banswer = max(banswer, pc);
                }
            }
            if (primes[x].second > 1 && counter >= primes[x].second){
                pc = pc * powb(primes[x].first, (primes[x].second - 1));
            }
            banswer = max(banswer, pc);
        }
        cout << banswer << "\n";

    }
}
