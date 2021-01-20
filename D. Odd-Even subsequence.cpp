#include <fstream>
#include <string>
#include <iostream>
#include <math.h>
#include <algorithm>
#include<bits/stdc++.h>
#include <vector>
using namespace std;

int n, k;
int arr[200005];
bool odd(int cur){
    int p1 = 0;
    int c = 0;
    while(p1 < n){
        if (arr[p1] <= cur){
            if (k % 2 != 0 || p1 < n - 1){
                p1++;
                c++;
            }
        }
        p1++;
    }
    if (c >= (k + 1)/2){
        return true;
    }
    return false;
}
bool even(int cur){
    int p1 = 1;
    int c = 0;
    while(p1 < n){
        if (arr[p1] <= cur){
            if (k % 2 != 1 || p1 < n - 1){
                p1++;
                c++;
            }
        }
        p1++;
    }
    if (c >= (k)/2){
        return true;
    }
    return false;
}

int main(){
    cin >> n >> k;
    for (int x = 0; x < n; x++){
        cin >> arr[x];
    }
    int mi = 0;
    int ma = 1000000001;
    int bo;
    int be;
    while(mi < ma){
        int mid = (mi + ma)/2;
        if (odd(mid)){
            ma = mid;
        }
        else{
            mi = mid + 1;
        }
    }
    bo = ma;

    mi = 0;
    ma = 1000000001;
    while(mi < ma){
        int mid = (mi + ma)/2;
        if (even(mid)){
            ma = mid;
        }
        else{
            mi = mid + 1;
        }
    }
    be = ma;
    cout << min(be, bo) << "\n";


}
