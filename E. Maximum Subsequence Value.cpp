#include <fstream>
#include <string>
#include <iostream>
#include <math.h>
#include <algorithm>
#include<bits/stdc++.h>
#include <vector>
#include <bitset>
using namespace std;

int n;
long long arr[501];
long long powb(long long a,long long b) {long long res=1;a ; assert(b>=0); for(;b;b>>=1){if(b&1)res=res*a;a=a*a;}return res;}
int main(){
    cin >> n;
    for (int x = 0; x < n; x++){
        cin >> arr[x];
        //bitset< 64 >( arr[x] ).to_string();
        //cout << nums[x] << "\n";
    }
    long long best = 0;
    for (int x = 0; x < n; x++){
        for (int y = 0; y < n; y++){
            for (int z = 0; z < n; z++){
                best = max(best, arr[x] | arr[y] | arr[z]);
            }
        }
    }
    long long answer = 0;
    string banswer = bitset< 64 >(best).to_string();
    for (int y = 0; y < 64; y++){
        if (banswer[y] == '1'){
            //cout << y << " " << "\n";
            answer += powb(2, 63 - y);
        }
    }
    cout << answer << "\n";



}
