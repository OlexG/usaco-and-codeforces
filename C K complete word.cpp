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
int main(){
    cin >> t;
    for (int z = 0; z < t; z++){
        cin >> n >> k;
        string s;
        cin >> s;
        string arr[n/k];
        string temp = "";
        int counter = 0;
        int p = 0;
        for (int x = 0; x < n; x++){
            if (counter == k){
                arr[p] = temp;
                p++;
                temp = "";
                counter = 0;
            }
            counter++;
            temp += s[x];
            if (x == n - 1){
                arr[p] = temp;
            }
        }
        char best[k];
        for (int y = 0; y < (k + 1)/2; y++){
            char b = 'a';
            int bc = 0;
            for (char cur = 'a'; cur <= 'z'; cur++){
                int curc = 0;
                for (int x = 0; x < n/k; x++){
                    if (arr[x][y] == cur){
                        curc++;
                    }
                    if (arr[x][k - y - 1] == cur){
                        curc++;
                    }
                }
                if (curc > bc){
                    bc = curc;
                    b = cur;
                }
            }
            best[y] = b;
        }
        int answer = 0;
        //cout << best[0] << " " << best[1] << "\n";
        for (int x = 0; x < (k + 1)/2; x++){
            for (int y = 0; y < n/k; y++){
                if (arr[y][x] != best[x]){
                    answer++;
                }
                if (arr[y][k - x - 1] != best[x] && x != k - x - 1){
                    answer++;
                }
            }
        }
        cout << answer << "\n";

    }
}
