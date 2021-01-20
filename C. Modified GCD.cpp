#pragma GCC optimize("O2")
#include <fstream>
#include <string>
#include <iostream>
#include <bitset>
#include <math.h>
#include <string>
#include <algorithm>
#include<bits/stdc++.h>
#include <vector>
#include <queue>
using namespace std;

long long a, b;
int n;
int main(){
    cin >> a >> b;
    cin >> n;
    set<long long> divs;
    for (long long x = 1; x * x <= a; x++){
        if (a % x == 0){
            if (b % x == 0){
                divs.insert(x);
            }
            long long div = a/x;
            if (b % div == 0){
                divs.insert(div);
            }
        }
    }
    long long one, two;
    for (int x = 0; x < n; x++){
        cin >> one >> two;
        long long w = *(prev(divs.upper_bound(two)));
        if (w < one){
            cout << -1 << "\n";
        }
        else{
            cout << w << "\n";
        }
    }
}
