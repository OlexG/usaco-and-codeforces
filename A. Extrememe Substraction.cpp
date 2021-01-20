#include <fstream>
#include <string>
#include <iostream>
#include <math.h>
#include <algorithm>
#include<bits/stdc++.h>
#include <vector>
using namespace std;

int t;
int n;
int main(){
    cin >> t;
    for (int z = 0; z < t; z++){
        bool answer = false;
        cin >> n;
        int carr[n];
        for (int x = 0; x < n; x++){
            cin >> carr[x];
        }
        for (int v = 0; v <= 0; v++){
            //cout << v << " " << answer << "\n";
            int arr[n];
            if (answer){
                continue;
            }
            if (v == 0){
                for (int x = 0; x < n; x++){
                    arr[x] = carr[x];
                }
            }
            else{
                for (int x = n - 1; x >= 0; x--){
                    arr[n - 1 - x] = carr[x];
                }
            }
            int sp = -1;
            for (int x = n - 2; x >= 0; x--){
                if (arr[x] > arr[x + 1]){
                    sp = x;
                    break;
                }
            }
            if (sp == -1){
                answer = true;
            }
            int ep = -1;
            for (int x = 1; x < n; x++){
                if (arr[x] > arr[x - 1]){
                    ep = x;
                    break;
                }
            }
            //cout << sp << " " << ep << "\n";
            if (ep == -1 || ep > sp){
                answer = true;
            }
            int m = 1000000000;
            for (int x = 0; x < ep; x++){
                m = min(m, arr[x]);
            }
            int subs = 0;
            //cout << sp << " " << ep << "\n";
            if (!answer){
                for (int x = sp; x >= ep; x--){
                    if (arr[x] - subs < 0){
                        m = -1;
                    }
                    arr[x] = arr[x] - subs;
                    //cout << (arr[x]) << " " << m << " " << arr[x + 1] << "\n";
                    if (arr[x] > arr[x + 1]){
                        m -= (arr[x] - arr[x + 1]);
                        subs += (arr[x] - arr[x + 1]);
                        arr[x] = arr[x + 1];
                        if (m < 0){
                            break;
                        }
                    }
                }
            }
            if (m >= 0){
                answer = true;
            }
            if (answer){
                cout << "YES\n";
            }
        }
        if (!answer){
            cout << "NO\n";
        }

    }
}
