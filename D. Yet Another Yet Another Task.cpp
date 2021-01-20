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
    int banswer = 0;
    for (int m = -30; m <= 30; m++){
         int p1 = n;
         int p2 = n;
         for (int x = 0; x < n; x++){
            if (arr[x] <= m){
                p1 = x;
                p2 = x;
                break;
            }
         }
         int curtotal = arr[p1];
         while(p2 < n){
            if (curtotal < 0 || arr[p2] > m){
                p2 = p2 + 1;
                p1 = p2;
                curtotal = arr[p1];
            }
            else{
                p2++;
                if (p2 < n){
                    curtotal += arr[p2];
                    if (arr[p2] <= m){
                        banswer = max(banswer, curtotal - m);
                    }
                }
            }
         }
    }
    cout << banswer << "\n";
}
