#include <fstream>
#include <string>
#include <iostream>
#include <math.h>
#include <algorithm>
#include<bits/stdc++.h>
#include <vector>
using namespace std;

long long t;
long long n, k;
long long arr[1000001];
int main(){
    cin >> t;
    for (int z = 0; z < t; z++){
        cin >> n >> k;
        for (int x = 0; x < n * k; x++){
            cin >> arr[x];
        }
        sort(arr, arr + (n * k));
        long long bsum = 0;
        int p1 = k * n;
        int p2 = -1;
        while(p2 < p1){
            p1 -= ((n/2) + 1);
            p2 += ((n - 1)/2);
            //cout << p1 << " " << p2 << "\n";
            if (p2 < p1){
                bsum += arr[p1];
            }
        }
        cout << bsum << "\n";

    }
}
