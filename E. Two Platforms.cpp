#include <fstream>
#include <string>
#include <iostream>
#include <math.h>
#include <algorithm>
#include<bits/stdc++.h>
#include <vector>
using namespace std;

int t, n, k;

int main(){
    cin >> t;
    for (int z = 0; z < t; z++){
        cin >> n >> k;
        int arr[n];
        int maxes[n];
        int best[n];
        int temp;
        for (int x = 0; x < n; x++){
            cin >> arr[x];
        }
        for (int x = 0; x < n; x++){
            cin >> temp;
        }
        sort(arr, arr + n);
        int p1 = 0;
        int p2 = 0;
        while(p2 < n){
            if (p2 < n - 1 && arr[p2 + 1] - arr[p1] <= k){
                p2++;
            }
            else{
                best[p1] = p2 - p1 + 1;
                p1++;
                if (p2 < p1){
                    p2 = p1;
                }
            }
        }
        maxes[n - 1] = best[n - 1];
        for (int x = n - 2; x >= 0; x--){
            maxes[x] = max(best[x], maxes[x + 1]);
        }
        int answer = 0;
        for (int x = 0; x < n; x++){
            if (x + best[x] < n){
                answer = max(answer, best[x] + maxes[x + best[x]]);
            }
            else{
                answer = max(answer, best[x]);
            }
        }
        cout << answer << "\n";

    }
}
