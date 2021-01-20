#include <fstream>
#include <string>
#include <iostream>
#include <math.h>
#include <algorithm>
#include<bits/stdc++.h>
#include <vector>
using namespace std;

long long xi, yi, xf, yf, n;
string s;
long long tdx = 0;
long long tdy = 0;
bool ok(long long days){
    long long changes = days/n;
    long long tx = xi + changes * tdx;
    long long ty = yi + changes * tdy;
    long long extra = days % n;
    for (int x = 0; x < extra; x++){
        if (s[x] == 'U'){
            ty++;
        }
        else if (s[x] == 'D'){
            ty--;
        }
        else if (s[x] == 'L'){
            tx--;
        }
        else{
            tx++;
        }
    }
    if (abs(xf - tx) + abs(yf - ty) <= days){
        return true;
    }
    return false;
}
int main(){
    cin >> xi >> yi >> xf >> yf >> n;
    cin >> s;

    for (int x = 0; x < n; x++){
        if (s[x] == 'U'){
            tdy++;
        }
        else if (s[x] == 'D'){
            tdy--;
        }
        else if (s[x] == 'L'){
            tdx--;
        }
        else{
            tdx++;
        }
    }
    long long mi = 0;
    long long ma = 1000000000000000;
    //cout << ok(0) << "\n";
    while (mi < ma){
        long long cur = (mi + ma)/2;
        if (ok(cur)){
            ma = cur;
        }
        else{
            mi = cur + 1;
        }
    }
    if (mi >= 1000000000000000){
        cout << "-1\n";
    }
    else{
        cout << mi << "\n";
    }
}
