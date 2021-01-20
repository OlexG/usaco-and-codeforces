#include <fstream>
#include <string>
#include <iostream>
#include <math.h>
#include <algorithm>
#include<bits/stdc++.h>
#include <vector>
using namespace std;

int n, m;

int fmatrix[2001][2001];
int bmatrix[2001][2001];
int vmatrix[2001][2001];
int xmatrix[2001][2001];
char arr[2001][2001];
int main(){
    cin >> n >> m;
    for (int x = 0; x < n; x++){
        for (int y = 0; y < m; y++){
            cin >> arr[x][y];
        }
    }
    for (int x = 0; x < n; x++){
        for (int y = 0; y < m; y++){
            int x1 = x - 1;
            int y1 = y;
            int x2 = x;
            int y2 = y - 1;
            if (x1 >= 0 && x1 < n && x2 >= 0 && x2 < n && y1 >= 0 && y1 < m && y2 >= 0 && y2 < m){
                if (arr[x1][y1] == arr[x][y] && arr[x2][y2] == arr[x][y]){
                    fmatrix[x][y] = min(fmatrix[x1][y1],fmatrix[x2][y2]) + 1;
                }
                else{
                    fmatrix[x][y] = 1;
                }
            }
            else{
                fmatrix[x][y] = 1;
            }
        }
    }
    for (int x = n - 1; x >= 0; x--){
        for (int y = m - 1; y >= 0; y--){
            int x1 = x + 1;
            int y1 = y;
            int x2 = x;
            int y2 = y + 1;
            if (x1 >= 0 && x1 < n && x2 >= 0 && x2 < n && y1 >= 0 && y1 < m && y2 >= 0 && y2 < m){
                if (arr[x1][y1] == arr[x][y] && arr[x2][y2] == arr[x][y]){
                    bmatrix[x][y] = min(bmatrix[x1][y1],bmatrix[x2][y2]) + 1;
                }
                else{
                    bmatrix[x][y] = 1;
                }
            }
            else{
                bmatrix[x][y] = 1;
            }
        }
    }
    for (int x = n - 1; x >= 0; x--){
        for (int y = 0; y < m; y++){
            int x1 = x + 1;
            int y1 = y;
            int x2 = x;
            int y2 = y - 1;
            if (x1 >= 0 && x1 < n && x2 >= 0 && x2 < n && y1 >= 0 && y1 < m && y2 >= 0 && y2 < m){
                if (arr[x1][y1] == arr[x][y] && arr[x2][y2] == arr[x][y]){
                    vmatrix[x][y] = min(vmatrix[x1][y1],vmatrix[x2][y2]) + 1;
                }
                else{
                    vmatrix[x][y] = 1;
                }
            }
            else{
                vmatrix[x][y] = 1;
            }
        }
    }
    for (int x = 0; x < n; x++){
        for (int y = m - 1; y >= 0; y--){
            int x1 = x - 1;
            int y1 = y;
            int x2 = x;
            int y2 = y + 1;
            if (x1 >= 0 && x1 < n && x2 >= 0 && x2 < n && y1 >= 0 && y1 < m && y2 >= 0 && y2 < m){
                if (arr[x1][y1] == arr[x][y] && arr[x2][y2] == arr[x][y]){
                    xmatrix[x][y] = min(xmatrix[x1][y1],xmatrix[x2][y2]) + 1;
                }
                else{
                    xmatrix[x][y] = 1;
                }
            }
            else{
                xmatrix[x][y] = 1;
            }
        }
    }
    int answer = 0;
    for (int x = 0; x < n; x++){
        for (int y = 0; y < m; y++){
            answer += min(min(fmatrix[x][y], bmatrix[x][y]), min(xmatrix[x][y], vmatrix[x][y]));
        }
    }
    cout << answer << "\n";

}
