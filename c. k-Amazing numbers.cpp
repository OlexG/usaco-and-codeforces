#include <fstream>
#include <string>
#include <iostream>
#include <math.h>
#include <algorithm>
#include<bits/stdc++.h>
#include <vector>
using namespace std;

int t, n;
int arr[300001];
int main(){
    cin >> t;
    for (int z = 0; z < t; z++){
        cin >> n;
        for (int x = 0; x < n; x++){
            cin >> arr[x];
        }

        int cnts[n];
        int left[n];
        int maxenc[n];
        int curmax[n];
        for (int x = 0; x < n; x++){
            cnts[x] = n + 1;
            left[x] = -1;
            maxenc[x] = 0;
            curmax[x] = n + 1;
        }

        for (int x = 0; x < n; x++){
            maxenc[arr[x] - 1] = max(maxenc[arr[x] - 1], x - left[arr[x] - 1]);
            left[arr[x] - 1] = x;
            curmax[arr[x] - 1] = max(maxenc[arr[x] - 1], n - x);
            if (curmax[arr[x] - 1] <= n){
                cnts[curmax[arr[x] - 1] - 1] = min(cnts[curmax[arr[x] - 1] - 1], arr[x]);
            }
        }

        for (int x = 1; x < n; x++){
            if (cnts[x - 1] <= cnts[x]){
                cnts[x] = cnts[x - 1];
            }
        }

        for (int x = 0; x < n; x++){
            if (cnts[x] == n + 1){
                cout << "-1 ";
            }
            else{
                cout << cnts[x] << " ";
            }
        }
        cout << "\n";
    }
}
