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
int main(){
    cin >> t;
    for (int z = 0; z < t; z++){
        cin >> n >> k;
        pair<int, int> arr[n];
        int temp;
        for (int x = 0; x < n; x++){
            cin >> temp;
            arr[x] = make_pair(temp, x);
        }
        sort(arr, arr + n);
        int p1 = 0;
        int p2 = n - 1;
        int answers[n];
        for (int x = 0; x < n; x++){
            answers[x] = 2;
        }
        while(p1 <= p2){
            if (k > arr[p1].first + arr[p2].first){
                if (answers[arr[p1].second] != 0 && answers[arr[p1].second] != 1){
                    answers[arr[p1].second] = 0;
                }
                p1++;
            }
            else if (k < arr[p1].first + arr[p2].first){
                if (answers[arr[p2].second] != 0 && answers[arr[p2].second] != 1){
                    answers[arr[p2].second] = 1;
                }
                p2--;
            }
            else{
                answers[arr[p2].second] = 1;
                answers[arr[p1].second] = 0;
                p2--;
                p1++;
            }
        }
        for (int x = 0; x < n; x++){
            cout << answers[x] << " ";
        }
        cout << "\n";
    }
}
