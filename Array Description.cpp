#include <fstream>
#include <string>
#include <iostream>
#include <bitset>
#include <math.h>
#include <algorithm>
#include<bits/stdc++.h>
#include <vector>
using namespace std;


long long mod = 1e9 + 7;

long long n,m;
long long arr[100002][102];
long long nums[100001];
int main(){
    cin >> n >> m;
    for (int x = 0; x < n; x++){
        cin >> nums[x];
    }

    for (int x = 0; x <= n; x++){
        for (int y = 0; y < m; y++){
            arr[x][y] = 0;
        }
    }
    if (nums[0] == 0){
        for (int y = 0; y < m; y++){
            arr[0][y] = 1;
        }
    }
    else{
        arr[0][nums[0] - 1] = 1;
    }
    int dx[3] = {-1, 0, 1};
    for (int x = 1; x < n; x++){
        if (nums[x] == 0){
            for (int y = 0; y < m; y++){
                for (int z = 0; z < 3; z++){
                    int cy = y + dx[z];
                    if (cy >= 0 && cy < m){
                        arr[x][y] += arr[x - 1][cy];
                        arr[x][y] %= mod;
                    }
                }
            }
        }
        else{
            for (int z = 0; z < 3; z++){
                int cy = nums[x] - 1 + dx[z];
                if (cy >= 0 && cy < m){
                    arr[x][nums[x] - 1] += arr[x - 1][cy];
                    arr[x][nums[x] - 1] %= mod;
                }
            }
        }
    }
    /*for (int x = 0; x < n; x++){
        for (int y = 0; y < m; y++){
            cout << arr[x][y];
        }
        cout << "\n";
    }*/
    long long sum = 0;
    for (int y = 0; y < m; y++){
        sum += arr[n - 1][y];
        sum %= mod;
    }
    cout << sum << "\n";

}
