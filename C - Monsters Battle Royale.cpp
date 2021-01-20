#include <fstream>
#include <string>
#include <iostream>
#include <bitset>
#include <math.h>
#include <algorithm>
#include<bits/stdc++.h>
#include <vector>
using namespace std;

int n;
long long arr[100001];

long long gcd(long long a,long long b) { return b?gcd(b,a%b):a;}

int main(){
    cin >> n;
    for (int x = 0; x < n; x++){
        cin >> arr[x];
    }
    sort(arr, arr + n);
    long long cur = gcd(arr[0], arr[1]);
    for (int x = 2; x < n; x++){
        cur = gcd(cur, arr[x]);
    }
    cout << cur << "\n";
}
