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
int n, k;

bool csort(pair<int, int> a, pair<int, int>b){
    if (a.first == b.first){
        return a.second < b.second;
    }
    else{
        return a.first < b.first;
    }
}
int main(){
    cin >> t;
    for (int z = 0; z < t; z++){
        cin >> n >> k;
        string a, b;
        cin >> a >> b;
        int fra[27];
        int frb[27];
        for (int x = 0; x < 27; x++){
            fra[x] = 0;
            frb[x] = 0;
        }
        for (int x = 0; x < n; x++){
            int dig = a[x] - 'a';
            int dig2 = b[x] - 'a';

            fra[dig]++;
            frb[dig2]++;
        }
        bool answer = true;
        int i = 0;
        while(true){
            if (i >= 26){
                break;
            }
            if (fra[i] > frb[i]){
                if ((fra[i] - frb[i]) % k != 0){
                    answer = false;
                }
                fra[i + 1] += (fra[i] - frb[i]);
            }
            else if (fra[i] < frb[i]){
                answer = false;
            }
            i++;

        }
        if (answer){
            cout << "YES\n";
        }
        else{
            cout << "NO\n";
        }
    }
}
