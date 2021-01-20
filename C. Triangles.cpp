#pragma GCC optimize("O2")
#include <fstream>
#include <string>
#include <iostream>
#include <bitset>
#include <math.h>
#include <string>
#include <algorithm>
#include<bits/stdc++.h>
#include <vector>
#include <queue>
using namespace std;


int t;
int n;
int arr[2000][2000];
int main(){
    cin >> t;
    for (int z = 0; z < t; z++){
        cin >> n;
        int best[10];
        for (int x = 0; x < n; x++){
            string s;
            cin >> s;
            for (int y = 0; y < n; y++){
                arr[x][y] = s[y] - '0';
            }
        }
        for (int x = 0; x <= 9; x++){
            best[x] = 0;
        }
        for (int i = 0; i <= 9; i++){
            int fl = -1;
            int fr = -1;
            int ft = -1;
            int fb = -1;
            for (int x = 0; x < n; x++){
                for (int y = 0; y < n; y++){
                    if (arr[x][y] == i){
                        fl = min(fl,y);
                        ft = min(x,ft);
                        if (fl == -1){
                            fl = y;
                        }
                        if (ft == -1){
                            ft = x;
                        }
                        fr = max(fr, y);
                        fb = max(fb,x);
                    }
                }
            }
            //check row;
            for (int x = 0; x < n; x++){
                int lowpos = -1;
                int highpos = -1;
                for (int y = 0; y < n; y++){
                    if (arr[x][y] == i){
                        if (lowpos == -1){
                            lowpos = y;
                        }
                        highpos = y;
                    }
                }
                if (lowpos != -1 && highpos != -1){
                    best[i] = max(best[i], (highpos - lowpos) * (n - x - 1));
                    best[i] = max(best[i], (highpos - lowpos) * (x));

                    if (ft != -1){
                        best[i] = max(best[i], (highpos) * (x - ft));
                        best[i] = max(best[i], (n - 1 - lowpos) * (x - ft));

                        best[i] = max(best[i], (highpos) * (fb - x));
                        best[i] = max(best[i], (n - 1 - lowpos) * (fb - x));
                    }
                }
            }
            //check col
            for (int y = 0; y < n; y++){
                int lowpos = -1;
                int highpos = -1;
                for (int x = 0; x < n; x++){
                    if (arr[x][y] == i){
                        if (lowpos == -1){
                            lowpos = x;
                        }
                        highpos = x;
                    }
                }
                if (lowpos != -1 && highpos != -1){
                    best[i] = max(best[i], (highpos - lowpos) * (n - y - 1));
                    best[i] = max(best[i], (highpos - lowpos) * (y));

                    if (fr != -1){
                        best[i] = max(best[i], (highpos) * (y - fl));
                        best[i] = max(best[i], (n - lowpos - 1) * (y - fl));

                        best[i] = max(best[i], (highpos) * (fr - y));
                        best[i] = max(best[i], (n - 1 - lowpos) * (fr - y));
                    }
                }
            }
        }
        for (int i = 0; i <= 9; i++){
            cout << best[i] << " ";
        }
        cout << "\n";
    }
}
