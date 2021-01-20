/*
ID: alex.go2
LANG: C++11
PROB: nocows
*/
#include <fstream>
#include <string>
#include <iostream>
#include <algorithm>
#include <math.h>
#include <vector>
using namespace std;
long long n, k;
int main(){
    ifstream in("nocows.in");
    ofstream out("nocows.out");
    in >> n >> k;
    long long matrix[k + 3][n + 3];
    for (int x = 0; x < k + 3; x++){
        for (int y = 0; y < n + 3; y++){
            matrix[x][y] = 0;
        }
    }
    for (int x = 0; x < k + 3; x++){
        matrix[x][0] = 1;
    }
    for (int x = 0; x < n + 3; x++){
        matrix[0][x] = 1;
    }
    matrix[1][1] = 1;
    for (int x = 2; x <= k; x++){
        for (int y = 1 + 2 * (x - 1); y <= n; y +=2){
            int needed = y - 1;
            for (int b = 0; b <= needed/2; b++){
                if (needed - b == b){
                    long long total1 = matrix[x - 1][b];
                    long long total2 = 0;
                    for (int h = 1; h < x - 1; h++){
                        total2 += matrix[h][b];
                    }
                    matrix[x][y] += (total1 * total2 * 2) % 9901;
                    matrix[x][y] += (matrix[x - 1][needed - b] * matrix[x - 1][b]) % 9901;
                }
                else{
                    long long total1 = matrix[x - 1][b];
                    long long total2 = 0;
                    for (int h = 1; h < x - 1; h++){
                        total2 += matrix[h][needed - b];
                    }
                    matrix[x][y] += (total1 * total2 * 2) % 9901;
                    total1 = matrix[x - 1][needed - b];
                    total2 = 0;
                    for (int h = 1; h < x - 1; h++){
                        total2 += matrix[h][b];
                    }
                    matrix[x][y] += (total1 * total2 * 2) % 9901;
                    matrix[x][y] += (matrix[x - 1][needed - b] * matrix[x - 1][b] * 2) % 9901;

                }
                /*if (x == 4 && y == 13){
                    cout << matrix[x][y] << " " << b << " " << needed - b << "\n";
                }*/
            }
            matrix[x][y] = matrix[x][y] ;//% 9901;
        }
    }
    /*for (int x = 0; x <=k; x++){
        for (int y = 0; y <= n; y++){
            cout << matrix[x][y] << " ";
        }
        cout << "\n";
    }*/
    out << matrix[k][n] % 9901 << "\n";

}
