#include <fstream>
#include <string>
#include <iostream>
#include <math.h>
#include <algorithm>
#include<bits/stdc++.h>
#include <vector>
using namespace std;

int t, n;
int arr[101];
int main(){
    cin >> t;
    for (int p = 0; p < t; p++){
        cin >> n;
        for (int x = 0; x < n; x++){
            cin >> arr[x];
        }
        for (int x = n - 1; x >= 0; x --){
            cout << arr[x] << " ";
        }
        cout << "\n";
    }
}
