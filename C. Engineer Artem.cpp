#include <fstream>
#include <string>
#include <iostream>
#include <math.h>
#include <bitset>
#include <algorithm>
#include<bits/stdc++.h>
#include <vector>
using namespace std;

int t;
int n, m;
int dx[2] = {-1, 0};
int dy[2] = {0, -1};

int main(){
    cin >> t;
    for (int z = 0; z < t; z++){
        cin >> n >> m;
        long long mat[n][m];
        for (int x = 0; x < n; x++){
            for (int y = 0; y < m; y++){
                cin >> mat[x][y];
            }
        }
        for (int x = 0; x < n; x++){
            for (int y = 0; y < m; y++){
                if ((x + y) % 2 == 0){
                    if (mat[x][y] % 2 == 1){
                        mat[x][y] += 1;
                    }
                }
                else{
                    if (mat[x][y] % 2 == 0){
                        mat[x][y] += 1;
                    }
                }
            }
        }
        for (int x = 0; x < n; x++){
            for (int y = 0; y < m; y++){
                cout << mat[x][y] << " ";
            }
            cout << "\n";
        }
    }
}
