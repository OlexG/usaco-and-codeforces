#include <fstream>
#include <string>
#include <iostream>
#include <math.h>
#include <algorithm>
#include<bits/stdc++.h>
#include <vector>
using namespace std;

int t;
long long n, w;

pair<long long, long long> arr[200001];

int main(){
    cin >> t;
    for (int z = 0; z < t; z++){
        cin >> n >> w;
        long long temp;
        for (long long x = 0; x < n; x++){
            cin >> temp;
            arr[x] = make_pair(temp, x);
        }
        sort(arr, arr + n);
        if (arr[0].first > w){
            cout << -1 << "\n";
            continue;
        }
        bool done = false;
        long long mi = (w + (long long)1)/(long long)2;
        long long p = 0;
        for (int x = n - 1; x >= 0; x--){
            if (arr[x].first <= w && arr[x].first >= mi){
                done = true;
                cout << 1 << "\n" << arr[x].second + 1 << "\n";
                break;
            }
            else if (arr[x].first < mi){
                p = x;
                break;
            }
        }
        if (done){
            continue;
        }
        long long cursum = 0;
        long long p2 = 0;
        for (int x = p; x >= 0; x--){
            cursum += arr[x].first;
            if (cursum <= w && cursum >= mi){
                done = true;
                p2 = x;
                break;
            }
        }
        if (done){
            cout << p - p2 + 1 << "\n";
            for (int x = p; x >= p2; x--){
                cout << arr[x].second + 1 << " ";
            }
            cout << "\n";
        }
        else{
            cout << -1 << "\n";
        }


    }
}
