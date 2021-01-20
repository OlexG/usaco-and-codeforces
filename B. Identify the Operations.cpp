#include <fstream>
#include <string>
#include <iostream>
#include <math.h>
#include <algorithm>
#include<bits/stdc++.h>
#include <vector>
using namespace std;

int t;
int n, k;
int mod = 998244353;
int main(){
    cin >> t;
    for (int z = 0; z < t; z++){
        cin >> n >> k;
        int arr[n];
        for (int x = 0; x < n; x++){
            cin >> arr[x];
        }
        int res[k];
        for (int x = 0; x < k; x++){
            cin >> res[x];
        }
        int answer = 1;
        int used[n];
        int pos[n];
        for (int x = 0; x < n; x++){
            used[x] = 1;
        }
        for (int x = 0; x < k; x++){
            used[res[x] - 1] = 2;
        }

        for (int x = 0; x < n; x++){
            if (used[arr[x] - 1] == 1){
                arr[x] = 0;
            }
            else{
                pos[arr[x] - 1] = x;
            }
        }
        bool works = true;
        for (int x = 0; x < k; x++){
            int curpos = pos[res[x] - 1];
            if (curpos == 0){
                if (arr[curpos + 1] != 0){
                    works = false;
                }
            }
            if (curpos == n - 1){
                if (arr[curpos - 1] != 0){
                    works = false;
                }
            }
            if (curpos != 0 && curpos != n - 1){
                if (arr[curpos - 1] == 0 && arr[curpos + 1] == 0){
                    answer *= 2;
                    answer %= mod;
                }
                else if (arr[curpos - 1] != 0 && arr[curpos + 1] != 0){
                    works = false;
                }
            }
            arr[curpos] = 0;
        }
        if (works){
            cout << answer << "\n";
        }
        else{
            cout << 0 << "\n";
        }


    }
}
