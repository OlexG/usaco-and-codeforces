#include <fstream>
#include <string>
#include <iostream>
#include <math.h>
#include <algorithm>
#include<bits/stdc++.h>
#include <vector>
using namespace std;

int num, n, pos;
int mod = 1000000007;
int main(){
    cin >> n >> num >> pos;
    int arr[n];
    arr[pos] = num;
    for (int x = 0; x < pos; x++){
        arr[x] = num - 1;
    }
    for (int x = pos + 1; x < n; x++){
        arr[x] = num + 1;
    }

    vector<int> bigger;
    vector<int> smaller;

    int left = 0;
    int right = n;
    while(left < right){
        int middle = (left + right)/2;
        if (arr[middle] <= num){
            left = middle + 1;
            smaller.push_back(middle);
        }
        else{
            right = middle;
            bigger.push_back(middle);
        }
    }
    if (bigger.size() > n - num){
        cout << 0 << "\n";
        return 0;
    }
    if (smaller.size() - 1 >= num){
        cout << 0 << "\n";
        return 0;
    }
    long long cur = num - 1;
    long long answer = 1;
    for (int x = 0; x < smaller.size() - 1; x++){
        answer = (answer * cur) % mod;
        cur--;
    }
    cur = n - num;
    for (int x = 0; x < bigger.size(); x++){
        answer = (answer * cur) % mod;
        cur--;
    }
    cur = n - smaller.size() - bigger.size();
    while(cur > 0){
        answer = (answer * cur) % mod;
        cur--;
    }
    cout << answer << "\n";
}
