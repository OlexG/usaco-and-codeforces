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


ll a, b, c, d, n;

int main(){
    cin >> a >> b >> c >> d >> n;
    char arr[max(b, d)][a + c];
    for (int x = 0; x < max(b,d); x++){
        for (int y = 0; y < a + c; y++){
            arr[x][y] = '0';
        }
    }
    if (d > b){
        for (int x = b; x < d; x++){
            for (int y = 0; y < a; y++){
                arr[x][y] = '.';
            }
        }
    }
    else{
        for (int x = d; x < b; x++){
            for (int y = a; y < a + c; y++){
                arr[x][y] = '.';
            }
        }
    }
    char cur = 'a';
    vector<int> st;
    int p = 0;
    int temp;
    bool forw = true;
    for (int x = 0; x < n; x++){
        cin >> temp;
        st.push_back(temp);
    }
    if (d > b){
        if (b % 2 == 0){
            forw = false;
        }
    }
    else{
        if (d % 2 == 1){
            forw = false;
        }
    }
    for (int x = 0; x < max(b,d); x++){
        if (forw){
            for (int y = 0; y < a + c; y++){
                if (arr[x][y] == '.'){
                    continue;
                }
                arr[x][y] = cur;
                st[p]--;
                if (st[p] == 0){
                    p++;
                    cur++;
                }
            }
            forw = false;
        }
        else{
            for (int y = a + c - 1; y >= 0; y--){
                if (arr[x][y] == '.'){
                    continue;
                }
                arr[x][y] = cur;
                st[p]--;
                if (st[p] == 0){
                    p++;
                    cur++;
                }
            }
            forw = true;
        }
    }
    cout << "YES\n";
    for (int x = 0; x < max(b,d); x++){
        for (int y = 0; y < a + c; y++){
            cout << arr[x][y];
        }
        cout << "\n";
    }
}
