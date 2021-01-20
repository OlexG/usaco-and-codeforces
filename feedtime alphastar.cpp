/*
10 8
...*....**
..**....**
...*....**
...**.*.**
***.**.***
...**.*.**
...*.*****
...***..**
*/
#include <fstream>
#include <string>
#include <iostream>
#include <math.h>
using namespace std;
#include <vector>
int n, m;
char arr[751][751];
int used[751][751];
int dx[8] = {0, -1, 0, 1, 1, 1, -1, -1};
int dy[8] = {1, 0, -1, 0, 1, -1, -1, 1};
int total = 0;
int answer = 0;
void rec(int x, int y){

    if (used[x][y] == 1){
        used[x][y] = 2;
        arr[x][y] = '#';
        total++;
        for (int z = 0; z < 8; z++){
            int cx = x + dx[z];
            int cy = y + dy[z];
            if (cx >= 0 && cx < m && cy >= 0 && cy < n){
                if (arr[cx][cy] == '.'){
                    rec(cx, cy);
                }
            }
        }

    }
}
int main(){
    cin >> n >> m;
    for (int x = 0; x < m; x++){
        for (int y = 0; y < n; y++){
            cin >> arr[x][y];
            used[x][y] = 1;
        }
    }
    for (int x = 0; x < m; x++){
        for (int y = 0; y < n; y++){
            if (used[x][y] == 1 && arr[x][y] == '.'){
                total = 0;
                rec(x, y);
                answer = max(answer, total);
                /*if (total == 41){
                    cout << x << " " << y <<"\n";
                     for (int z = 0; z < n; z++){
                        for (int c = 0; c < m; c++){
                            cout << arr[z][c];
                        }
                        cout << "\n";
                    }
                } */
            }

        }
    }
    cout << answer << "\n";
}
