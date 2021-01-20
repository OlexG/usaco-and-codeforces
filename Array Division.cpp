#include <fstream>
#include <string>
#include <iostream>
#include <bitset>
#include <math.h>
#include <string>
#include <algorithm>
#include<bits/stdc++.h>
#include <vector>
using namespace std;

long long n, k;

long long arr[200005];

bool ok(long long sum){
    long long c = 0;
    long long cursum = 0;
    for (int x = 0; x < n; x++){
        if (arr[x] > sum){
            return false;
        }
        if (cursum + arr[x] > sum){
            c++;
            cursum = arr[x];
        }
        else{
            cursum += arr[x];
        }
        if (x == n - 1){
            c++;
        }
    }
    //cout << c << " " << sum << "\n";
    return (c <= k);
}
int main(){
    cin >> n >> k;
    for (int x = 0; x < n; x++){
        cin >> arr[x];
    }
    long long mi = 0;
    long long ma = 1e15;
    //ok(7);
    while(mi < ma){
        long long mid = (mi + ma)/(long long)2;
        if (ok(mid)){
            ma = mid;
        }
        else{
            mi = mid + 1;
        }
    }
    cout << ma << "\n";
}
