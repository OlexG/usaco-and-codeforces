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
    for (int z = 0; z < t;z++){
        cin >> n;
        int arr[n];
        for (int x = 0; x < n; x++){
            cin >> arr[x];
        }
        set<int> q;
        bool first[n];
        bool second[n];
        for (int x = 0; x < n; x++){
            first[x] = false;
            second[x] = false;
        }
        for (int x = 0; x < n; x++){
            if (q.find(arr[x]) != q.end()){
                break;
            }
            q.insert(arr[x]);
            if (*(prev(q.end(), 1)) == x + 1){
                first[x] = true;
            }
        }
        q.clear();
        for (int x = n - 1; x >= 0; x--){
            if (q.find(arr[x]) != q.end()){
                break;
            }
            q.insert(arr[x]);
            if (*(prev(q.end(), 1)) == n - x){
                second[x] = true;
            }
        }
        int counter = 0;
        for (int x = 0; x < n - 1; x++){
            if (first[x] && second[x + 1]){
                counter++;
            }
        }
        cout << counter << "\n";
        for (int x = 0; x < n - 1; x++){
            if (first[x] && second[x + 1]){
                cout << x + 1 << " " << n - x - 1 << "\n";
            }
        }

    }
}
