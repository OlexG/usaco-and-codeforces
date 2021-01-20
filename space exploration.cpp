#include <fstream>
#include <string>
#include <iostream>
#include <math.h>
#include <algorithm>
#include <vector>
using namespace std;

int n;
char arr[1000][1000];
int used[1000][1000];
int dx[8] = {0, -1, 0, 1};
int dy[8] = {1, 0, -1, 0};
void rec(int x, int y){
    if (used[x][y] == 1){
        used[x][y] = 2;
        for (int z = 0; z < 4; z++){
            int cx = x + dx[z];
            int cy = y + dy[z];
            if (cx >= 0 && cx < n && cy >=0 && cy < n && arr[cx][cy] == '*'){
                rec(cx, cy);
            }
        }
    }
}
int main(){
    cin >> n;
    for (int x = 0; x< n; x++){
        for (int y = 0; y < n; y++){
            cin >> arr[x][y];
            used[x][y] = 1;
            if (arr[x][y] == '.'){
                used[x][y] = 2;
            }
        }
    }
    int answer = 0;
    for (int x = 0; x < n; x++){
        for (int y = 0; y < n; y++){
            if (used[x][y] == 1){
                answer++;
                rec(x,y);
            }
        }
    }
    cout << answer;
}
