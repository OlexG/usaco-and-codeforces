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


int t;
int n;
vector<int> one;
vector<int> two;
bool okone(int lim){
    //some smaller ------
    //------- some bigger
    //10101
    for (int x = 0; x < lim; x++){
        int ind = n - lim + x;
        if (two[ind] < one[x]){
            return false;
        }
    }
    return true;
}
bool oktwo(int lim){
    //-----some bigger
    //some smaller----
    for (int x = 0; x < lim; x++){
        int ind = n - lim + x;
        if (one[ind] < two[x]){
            return false;
        }
    }
    return true;
}

int main(){
    cin >> t;
    for (int z = 0; z < t; z++){
        cin >> n;
        int used[2*n];
        int temp;
        for (int x = 0; x < 2*n; x++){
            used[x] = 1;
        }
        one.clear();
        two.clear();
        for (int x = 0; x < n; x++){
            cin >> temp;
            used[temp - 1] = 2;
            one.push_back(temp);
        }
        for (int x = 0; x < 2 * n; x++){
            if (used[x] == 1){
                two.push_back(x + 1);
            }
        }

        sort(one.begin(), one.end());
        sort(two.begin(), two.end());
        int indone;
        int indtwo;
        int sm = 0;
        int la = n;
        while(sm < la){
            int mid = (sm + la + 1)/2;
            if (okone(mid)){
                sm = mid;
            }
            else{
                la = mid - 1;
            }
        }
        indone = sm;

        sm = 0;
        la = n;
        while(sm < la){
            int mid = (sm + la + 1)/2;
            if (oktwo(mid)){
                sm = mid;
            }
            else{
                la = mid - 1;
            }
        }
        indtwo = sm;
        //cout << indone << " index of one\n";
        //cout << indtwo << " index of two\n";

        cout << indone - (n - indtwo - 1) << "\n";

    }
}
