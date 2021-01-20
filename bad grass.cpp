#include <fstream>
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;
int r, c;
int dx[8] = {1, 0, -1 ,0, 1, 1, -1, -1};
int dy[8] = {0, -1, 0, 1, -1, 1, -1, 1};
int used[1000][1000];
int arr[1000][1000];
int answer = 0;
int rec(int x, int y){
    used[x][y] = 2;
    for (int z = 0; z < 8; z++){
        int cx = x + dx[z];
        int cy = y + dy[z];
        if (cx >= 0 && cx < r && cy >= 0 && cy < c){
            if (arr[cx][cy] > 0 && used[cx][cy] == 1){
                used[cx][cy] = 2;
                rec(cx, cy);
            }
        }
    }
}
int main(){
    cin >> r >> c;
    for (int x = 0; x < r; x++){
        for (int y = 0; y < c;y ++){
            cin >> arr[x][y];
            used[x][y] = 1;
        }
    }
    for (int x = 0; x < r; x++){
        for (int y = 0; y < c;y ++){
            if (arr[x][y] > 0 && used[x][y] == 1){
                answer++;
                rec(x, y);
            }
        }
    }
    cout << answer << "\n";



}
