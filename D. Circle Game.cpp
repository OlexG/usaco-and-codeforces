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
long long d, k;
bool more(long long x, long long y, long long d){
    return (x * x + y * y) > (d * d);
}
int main(){
    cin >> t;
    for (int z = 0; z < t; z++){
        cin >> d >> k;
        long long curx, cury;
        curx = 0;
        cury = 0;
        long long a = true;
        while(true){
            if (more(curx + k, cury, d)){
                break;
            }
            curx += k;
            if (more(curx, cury + k, d)){
                a = false;
                break;
            }
            cury += k;
        }
        if (a){
            cout << "Utkarsh\n";
        }
        else{
            cout << "Ashish\n";
        }
    }
}


