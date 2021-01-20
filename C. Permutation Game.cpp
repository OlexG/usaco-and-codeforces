#pragma GCC optimize("O2")
#include <fstream>
#include <string>
#include <iostream>
#include <bitset>
#include <math.h>
#include <string>
#include <algorithm>
#include <assert.h>
#include<bits/stdc++.h>
#include <vector>
#include <queue>
#include<stdio.h>
#include<ctype.h>
#define ll long long
using namespace std;

int n;

int arr[100002];
int pos[100002];
char answers[100002];

int main(){
    cin >> n;
    int temp;
    for (int x = 0; x < n; x++){
        cin >> temp;
        pos[temp] = x;
        arr[x] = temp;
        if (temp == 8){
            answers[x] = 'B';
        }
    }
    for (int x = n; x > n/2; x--){
        int spos = pos[x] - x;
        if (spos < 0){
            spos = pos[x] + x;
        }
        if (spos >= n){
            answers[pos[x]] = 'B';
            continue;
        }
        if (arr[spos] < x){
            answers[pos[x]] = 'B';
        }
        else{
            if (answers[spos] == 'B'){
                answers[pos[x]] = 'A';
            }
            else{
                answers[pos[x]] = 'B';
            }
        }
    }
    for (int x = n/2; x >= 1; x--){
        bool found = false;
        int p1 = pos[x];
        int p2 = pos[x];
        while(p1 >= 0){
            if (answers[p1] == 'B' && arr[p1] > x){
                found = true;
                break;
            }
            p1 -= x;
        }
        while(p2 < n){
            if (answers[p2] == 'B' && arr[p2] > x){
                found = true;
                break;
            }
            p2 += x;
        }
        if (found){
            answers[pos[x]] = 'A';
        }
        else{
            answers[pos[x]] = 'B';
        }
    }
    for (int x = 0; x < n; x++){
        cout << answers[x];
    }
    cout << "\n";

}
