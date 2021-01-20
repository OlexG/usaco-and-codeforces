#include <fstream>
#include <string>
#include <iostream>
#include <math.h>
#include <algorithm>
#include <vector>
using namespace std;


int n, m;
char arr[100][100];
int used[100][100];
int dx[8] = {0, -1, 0, 1, 1, -1, 1, -1};
int dy[8] = {1, 0, -1, 0, 1, 1, -1, -1};
void rec(int x, int y){
    if (used[x][y] == 1){
        used[x][y] = 2;
        for (int z = 0; z < 8; z++){
            int cx = x + dx[z];
            int cy = y + dy[z];
            if (cx >= 0 && cx < n && cy >=0 && cy < m && arr[cx][cy] == 'W'){
                rec(cx, cy);
            }
        }
    }
}
int main(){
    cin >> n >> m;
    for (int x = 0; x < n; x++){
        for (int y = 0; y < m; y++){
            cin >> arr[x][y];
            used[x][y] = 1;
            if (arr[x][y] == '.'){
                used[x][y] = 2;
            }
        }
    }
    int answer = 0;
    for (int x = 0; x < n; x++){
        for (int y = 0; y < m; y++){
            if (used[x][y] == 1){
                answer++;
                rec(x,y);
            }
        }
    }
    cout << answer;
}
