#include <fstream>
#include <string>
#include <iostream>
#include <math.h>
#include <algorithm>
#include<bits/stdc++.h>
#include <vector>
using namespace std;

int n;
int arr[100001];
int main(){
    cin >> n;
    for (int x = 0; x < n; x++){
        cin >> arr[x];
    }
    int c = 0;
    sort(arr, arr + n);
    //last = x^n
    int v1 = floor(pow(arr[n - 1], 1/(double)(n - 1)));
    int v2 = ceil(pow(arr[n - 1], 1/(double)(n - 1)));
    long long svalue = 1000000000000000;
    long long cvalue = 0;
    long long cur = 1;
    for (int x = 0; x < n; x++){
        cvalue += abs(arr[x] - cur);
        cur *= v1;
    }
    svalue = min(svalue, cvalue);
    cvalue = 0;
    cur = 1;
    for (int x = 0; x < n; x++){
        cvalue += abs(arr[x] - cur);
        cur *= v2;
        if (cvalue > svalue){
            break;
        }
    }
    svalue = min(svalue, cvalue);
    cout << svalue << "\n";
}
