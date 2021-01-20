#include <fstream>
#include <string>
#include <iostream>
#include <math.h>
#include <algorithm>
#include<bits/stdc++.h>
#include <vector>
using namespace std;
/*
4
5 4 0
1 5 4 3 2
5 4 1
1 5 4 3 2
5 4 4
10 20 30 40 50
10 7 3
4 6 8 2 9 9 7 4 10 9
*/

int t;
int n, k, z;
int arr[300001];
int main(){
    cin >> t;
    for (int b = 0; b < t; b++){
        cin >> n >> k >> z;
        for (int x = 0; x < n; x++){
            cin >> arr[x];
        }
        int banswer = 0;
        int prefsum[n];
        prefsum[0] = arr[0];
        for (int x = 1; x < n; x++){
            prefsum[x] = prefsum[x - 1] + arr[x];
        }
        for (int l = 0; l <= z; l++){
            for(int x = 1; x < n; x++){
                int curanswer = prefsum[x];

                int usedmoves = x;
                int avmoves = k - usedmoves;
                if (avmoves - l * 2 >= 0){
                    curanswer += (arr[x] + arr[x - 1]) * l;
                    curanswer += prefsum[x + avmoves - l * 2] - prefsum[x];
                    banswer = max(banswer, curanswer);
                }
                else{
                    if (avmoves - l * 2 == -1){
                        curanswer += (arr[x] + arr[x - 1]) * l;
                        curanswer -= arr[x];
                        banswer = max(banswer, curanswer);
                    }
                }
            }
        }
        cout << banswer << "\n";
    }
}
