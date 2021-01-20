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


int t;

int main(){
    cin >> t;
    long long n;
    for (int z = 0; z < t; z++){
        cin >> n;
        vector<int> curanswer;
        vector<long long> p2;
        long long curp = 2;
        for (int x = 0; x < 59; x++){
            p2.push_back(curp);
            curp *= 2;
        }
        if (n % 2 == 1){
            cout << -1 << "\n";
            continue;
        }
        curanswer.push_back(1);
        n -= 2;
        for (int x = p2.size() - 1; x >= 0; x--){
            while(n - p2[x] >= 0){
                n -= p2[x];
                curanswer.push_back(1);
                for (int b = 0; b < x - 1; b++){
                    curanswer.push_back(0);
                }
                if (p2[x] != 2){
                    curanswer.push_back(1);
                }
            }
        }
        cout << curanswer.size() << "\n";
        for (int x = 0; x < curanswer.size(); x++){
            cout << curanswer[x] << " ";
        }
        cout << "\n";
    }
}
