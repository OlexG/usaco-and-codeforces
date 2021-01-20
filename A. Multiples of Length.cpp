#include <fstream>
#include <string>
#include <iostream>
#include <math.h>
#include <algorithm>
#include<bits/stdc++.h>
#include <vector>
using namespace std;

int n;
long long arr[100001];
int main(){
    cin >> n;
    for (int x = 0; x < n; x++){
        cin >> arr[x];
    }
    vector<long long> op1;
    op1.push_back(0);
    for (int x = 1; x < n; x++){
        long long mpos = 0;
        if (arr[x] < 0){
            mpos = (-1 * arr[x] + n - 1)/n;
        }
        arr[x] += mpos * n;
        long long away = (arr[x]) % (n - 1);

        if (away != 0){
            long long add = n - 1 - away;
            op1.push_back((add + mpos) * n);
            arr[x] += add * n;
        }
        else{
            op1.push_back(mpos * n);
        }
    }
    vector<long long> op2;
    for (int x = 1; x < n; x++){
        op2.push_back(-1 * arr[x]);
    }
    cout << 1 << " " << n << "\n";
    for (int x = 0; x < n; x++){
        cout << op1[x] << " ";
    }
    cout << "\n";
    cout << 1 << " " << 1 << "\n" << -1 * arr[0] << "\n";
    if (n >= 2){
        cout << 2 << " " << n << "\n";
        for (int x = 0; x < n - 1; x++){
            cout << op2[x] << " ";
        }
    }
    else{
        cout << 1 << " " << 1 << "\n" << 0 << "\n";
    }


}
