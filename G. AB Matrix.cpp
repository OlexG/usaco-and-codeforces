#include <fstream>
#include <string>
#include <iostream>
#include <math.h>
#include <algorithm>
#include<bits/stdc++.h>
#include <vector>
using namespace std;

int t;

int matrix[50][50];
int n, m, a, b;

bool check(){
    int counter = 0;
    for (int x = 0; x < n; x++){
        counter = 0;
        for (int y = 0; y < m; y++){
            if (matrix[x][y] == 1){
                counter++;
            }
        }
        if (counter != a){
            return false;
        }
    }
    for (int x = 0; x < m; x++){
        counter = 0;
        for (int y = 0; y < n; y++){
            if (matrix[y][x] == 1){
                counter++;
            }
        }
        //cout << counter << " " << b << "\n";
        if (counter != b){
            return false;
        }
    }
    return true;
}
int main(){
    cin >> t;
    for (int z = 0; z < t; z++){
        cin >> n >> m >> a >> b;
        if (n * a != b * m){
            cout << "NO\n";
        }
        else{
            cout << "YES\n";
            int c = 0;
            int shift = 0;


            for (shift = 0; shift <= m; shift++){
                bool works = true;
                int p1 = 0;
                for (int x = 0; x < n; x++){
                    for (int y = 0; y < m; y++){
                        matrix[x][y] = 0;
                    }
                }
                for (int x = 0; x < n; x++){
                    for (int y = p1; y < p1 + a; y++){
                        matrix[x][y%m] = 1;
                    }
                    //c++;
                    //if (c == b){
                        //c = 0;
                        p1 += shift;
                        p1 %= m;
                    //}
                }
                if (check()){
                    break;
                }

            }
            for (int x = 0; x < n; x++){
                for (int y = 0; y < m; y++){
                    cout << matrix[x][y];
                }
                cout << "\n";
            }
        }
    }
}
