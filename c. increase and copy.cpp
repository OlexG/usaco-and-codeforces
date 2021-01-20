#include <fstream>
#include <string>
#include <iostream>
#include <math.h>
#include <algorithm>
#include<bits/stdc++.h>
#include <vector>
using namespace std;
int t;

int main(){
    cin >> t;
    for (int x = 0; x < t; x++){
        long long a;
        cin >> a;
        long long low = 0;
        long long high = 1000000000;
        while(low < high){
            long long mid = (low + high)/2;
            if ((1 + mid/2) * (mid - mid/2 + 1) >= a){
                high = mid;
            }
            else{
                low = mid + 1;
            }
        }
        cout << high << "\n";
    }
}
