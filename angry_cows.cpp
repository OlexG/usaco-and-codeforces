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
double arr[50001];
double rdp[50001];
// minimum forces to break all from the right side
double ldp[50001];
// minimum force to break all from the left side
int main(){
    cin >> n;
    for (int x = 0; x < n; x++){
        cin >> arr[x];
        rdp[x] = 1000000000;
        ldp[x] = 1000000000;
    }
    sort(arr, arr + n);
    rdp[0] = 0;
    ldp[n - 1] = 0;
    int p = n - 1;
    for (int x = n - 2; x >= 0; x--){
        if (p > x + 1){
            while(arr[p] - arr[x] > ldp[p] + 1 && p > x + 1){
                p--;
            }
            /*if (arr[p] - arr[x] < ldp[p] + 1 && (ldp[p] + 1 > arr[p + 1]- arr[x]) && p != n - 1){
                p++;
            }*/
        }
        ldp[x] = max(ldp[p] + 1, arr[p] - arr[x]);
    }
    p = 0;
    for (int x = 1; x < n; x++){
        if (p < x - 1){
            while(arr[x] - arr[p] > rdp[p] + 1 && p < x - 1){
                p++;
            }
            /*if (arr[x] - arr[p] < rdp[p] + 1 && (rdp[p] + 1 > arr[x]- arr[p - 1]) && p != 0){
                p--;
            }*/
        }
        rdp[x] = max(rdp[p] + 1, arr[x] - arr[p]);
    }
    //cout << rdp[1] << "\n";
    /*for (int x = 0; x < n; x++){
        cout << rdp[x] << " " << ldp[x] << "\n";
    }*/
    double answer = 1000000000;
    for (int x = 1; x < n; x++){
        if ((arr[x] - arr[x - 1])/(double)2 > max(ldp[x], rdp[x - 1]) + 1){
                double dist = (arr[x] - arr[x - 1])/(double)2;
                double m = max(ldp[x], rdp[x - 1]);
                answer = min(answer, max(dist, m + 1));
        }
        else{
            answer = min(answer, max(ldp[x], rdp[x - 1]) + 1);
        }
        answer = min(answer, max(ldp[x], rdp[x]));
    }
    answer = min(answer, max(ldp[0], rdp[0]));

    //answer = min(answer, max(max(ldp[n - 1], rdp[n - 2]), (arr[n - 1] - arr[n - 2] + 1)/2));
    cout << setprecision(1) << fixed << answer << "\n";

}
