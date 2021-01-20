#include <fstream>
#include <string>
#include <iostream>
#include <math.h>
#include <algorithm>
#include<bits/stdc++.h>
#include <vector>
using namespace std;

int n, k;
int main(){
    cin >> n >> k;
    vector<int> arr;
    int sums[n];
    int one, two;
    for (int x = 0; x < k; x++){
        cin >> one >> two;
        for (int y = one; y <= two; y++){
            arr.push_back(y);
        }
    }
    sort(arr.begin(), arr.end());

}
