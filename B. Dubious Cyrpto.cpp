#include <fstream>
#include <string>
#include <iostream>
#include <math.h>
#include <algorithm>
#include<bits/stdc++.h>
#include <vector>
using namespace std;

int t;

long long m, r, l;

int main(){
    cin >> t;
    for (int z = 0; z < t; z++){
        cin >> l >> r >> m;
        for (int a = l; a <= r; a++){
            //a * n + b - c = m
            //m + c - b must be divisible by a
            long long ndif = m % a;
            long long pdif = a - ((m + a) % a);
            //cout << a << " " << pdif << " " << ndif << "\n";
            if (l + ndif <= r && m - ndif != 0){
                cout << a << " " << l + ndif << " " << l << "\n";
                break;
            }
            if (l + pdif <= r){
                cout << a <<  " " << l << " " << l + pdif << "\n";
                break;
            }
        }
    }
}
