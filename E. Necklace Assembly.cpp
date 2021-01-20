#include <fstream>
#include <string>
#include <iostream>
#include <math.h>
#include <algorithm>
#include<bits/stdc++.h>
#include <vector>
using namespace std;
int t;
int n, k;
int carr[26];
int arr[26];
bool cs(int a, int b){
    return a > b;
}

bool ok(int cur){
    int ck = k % cur;
    char seq[cur];
    for (int x = 0; x < cur; x++){
        seq[x] = '-';
    }
    int p1 = 0;
    for (int x = 0; x < 26; x++){
        carr[x] = arr[x];
    }
    int s = 0;
    while(true){
        if (seq[p1] != '-'){
            break;
        }
        else{
            seq[p1] = '*';
            p1 += ck;
            p1 = p1 % cur;
            s++;
        }
    }
    int amount = cur;
    p1 = 0;
    while(p1 < 26){
        if (carr[p1] >= s){
            carr[p1] -= s;
            amount -= s;
            if (amount == 0){
                break;
            }
        }
        else{
            p1++;
        }
    }
    if (amount == 0){
        return true;
    }
    return false;
}
int main(){
    cin >> t;
    for (int z = 0; z < t; z++){
        cin >> n >> k;
        string s;
        cin >> s;
        for (int x = 0; x < 26; x++){
            arr[x] = 0;
        }
        for (int x = 0; x < n; x++){
            int ind = s[x] - 'a';
            arr[ind] += 1;
        }
        sort(arr, arr + 26, cs);
        int mi = 0;
        int ma = n;
        int besta = 1;
        for (int x = 1; x <= n; x++){
            if (ok(x)){
                besta = x;
            }
        }
        cout << besta << "\n";
    }
}
