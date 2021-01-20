#include <fstream>
#include <string>
#include <iostream>
#include <math.h>
#include <bitset>
#include <algorithm>
#include<bits/stdc++.h>
#include <vector>
using namespace std;

int t;
long long n, k;
long long arr[100001];

int main(){
    cin >> t;
    for (int z = 0; z < t; z++){
        cin >> n >> k;
        for (int x = 0; x < n; x++){
            cin >> arr[x];
        }
        bool worksone = false;
        for (int x = 0; x < n; x++){
            if (arr[x] == k){
                worksone = true;
            }
        }
        bool workstwo = false;
        for (int x = 0; x < n; x++){
            if (arr[x] >= k){
                if (x < n - 1 && arr[x + 1] >= k){
                    workstwo = true;
                }
                if (x < n - 2 && arr[x + 2] >= k){
                    workstwo = true;
                }
            }
        }
        if ((worksone && workstwo) || (n == 1 && worksone)){
            cout << "yes\n";
        }
        else{
            cout << "no\n";
        }
    }
}
