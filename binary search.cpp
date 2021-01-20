#include <fstream>
#include <string>
#include <iostream>
#include <math.h>
#include <algorithm>
#include<bits/stdc++.h>
#include <vector>
using namespace std;

long long n, t;
long long arr[200001];

bool ok(long long answer){
    unsigned long long counter = 0;
    for (long long x = 0; x < n; x++){
        counter += (answer/arr[x]);
        if (counter > t){
            return true;
        }
    }
    return counter >= t;
}
int main(){
    cin >> n;
    cin >> t;
    for (long long x = 0; x < n; x++){
        cin >> arr[x];
    }
    long long s = 0;
    long long e = 1000000000000000000;
    //a b
    while(s < e){
        long long mid = (s + e)/(long long)2;
        if (ok(mid)){
            e = mid;
        }
        else{
            s = mid + 1;
        }
    }
    cout << e << "\n";

}
