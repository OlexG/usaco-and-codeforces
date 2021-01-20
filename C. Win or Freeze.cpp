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
long long n;
int main(){
    cin >> n;
    if (n == 1 || n == 2){
        cout << "1\n0\n";
        return 0;
    }
    long long ogn = n;
    long long div = 1;
    long long numdiv = 0;
    for (long long x = 2; x * x <= n; x++){
       while(n % x == 0 && n/x != 1){
            n /= x;
            numdiv+=1;
            div *= x;
            if (numdiv == 2){
                break;
            }
       }
       if (numdiv == 2){
         break;
       }
    }
    if (numdiv == 0){
        cout << "1\n0\n";
    }
    else if (numdiv == 1){
        cout << "2\n";
    }
    else{
        cout << "1\n" << div << "\n";
    }
}
