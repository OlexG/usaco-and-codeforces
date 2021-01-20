#include <fstream>
#include <string>
#include <iostream>
#include <math.h>
#include <algorithm>
#include<bits/stdc++.h>
#include <vector>
using namespace std;
int q, n;
bool ok(long long cur){
    long long needed = (cur + 1)/2;
    long long nodesleft = n - needed;
    long long edgesleft = cur - needed;
    //1 cout << needed << " " << nodesleft << " " << edgesleft << "\n";
    if (nodesleft <= 0){
        return false;
    }
    else{
        long long current = 0;
        current += (nodesleft * (nodesleft - 1))/2;
        if (current >= edgesleft){
            return true;
        }
        return false;
    }
}
int main(){
    cin >> q;
    for (int z = 0; z < q; z++){
        cin >> n;
        long long ma = 1000000000000;
        long long mi = 0;
        //cout << ok(7) << "\n";
        while(mi < ma){
            long long cur = (mi + ma + 1)/2;
            //cout << cur << "\n";
            if (ok(cur)){
                mi = cur;
            }
            else{
                ma = cur - 1;
            }
        }
        cout << ma << "\n";
    }
}
