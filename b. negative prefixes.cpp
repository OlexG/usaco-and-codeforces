#include <fstream>
#include <string>
#include <iostream>
#include <math.h>
#include <algorithm>
#include<bits/stdc++.h>
#include <vector>
using namespace std;

int t, n;

int main(){
    cin >> t;
    for (int z = 0; z < t; z++){
        cin >> n;
        int arr[n];
        for (int x = 0; x < n; x++){
            cin >> arr[x];
        }
        int locked[n];
        for (int x = 0; x < n; x++){
            cin >> locked[x];
        }
        vector<int> vals;
        for (int x = 0; x < n; x++){
            if (locked[x] == 0){
                vals.push_back(arr[x]);
            }
        }
        sort(vals.rbegin(), vals.rend());
        int p1 = 0;
        for (int x = 0; x < n; x++){
            if (locked[x] == 0){
                arr[x] = vals[p1];
                p1++;
            }
        }
        for (int x = 0; x < n; x++){
            cout << arr[x] << " ";
        }
        cout << "\n";

    }
}
