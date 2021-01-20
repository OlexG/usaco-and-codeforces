#include <fstream>
#include <string>
#include <iostream>
#include <math.h>
#include <algorithm>
#include<bits/stdc++.h>
#include <vector>
using namespace std;

long long n;

int main(){
    cin >> n;
    long long arr[n];
    long long maxes[n + 1];
    for (int x = 0; x < n; x++){
        cin >> arr[x];
    }
    for (int x = 1; x < n; x++){
        arr[x] = arr[x - 1] + arr[x];
    }
    long long curmax = arr[n - 1];
    maxes[n] = arr[n - 1];
    for (int x = n - 1; x >= 0; x--){
        curmax = max(arr[x], curmax);
        maxes[x] = curmax;
    }
    long long answer = -10000000000;
    for (int x = 0; x < n; x++){
        if (x == 0){
            answer = max(answer, maxes[x] - 0);
        }
        else{
            answer = max(answer, maxes[x + 1] - arr[x - 1]);
        }
    }
    cout << answer << "\n";



}
