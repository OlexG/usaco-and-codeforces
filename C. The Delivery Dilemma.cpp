#include <fstream>
#include <string>
#include <iostream>
#include <math.h>
#include <algorithm>
#include<bits/stdc++.h>
#include <vector>
using namespace std;

int t;
int n;
int a[200001];
int b[200001];
bool ok(long long mid){
    long long total = 0;
    for (int x = 0; x < n; x++){
        if (a[x] > mid){
            total += b[x];
        }
    }
    return total <= mid;
}
int main(){
    cin >> t;
    for (int z = 0; z < t; z++){
        cin >> n;
        for (int x = 0; x < n; x++){
            cin >> a[x];
        }
        for (int x = 0; x < n; x++){
            cin >> b[x];
        }
        long long s = 0;
        long long l = 100000000000000;
        while(s < l){
            long long mid = (l + s)/2;
            if (ok(mid)){
                l = mid;
            }
            else{
                s = mid + 1;
            }
        }
        cout << l << "\n";
    }
}
