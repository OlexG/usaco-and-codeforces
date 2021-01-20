#include <fstream>
#include <string>
#include <iostream>
#include <math.h>
#include <algorithm>
#include <vector>
using namespace std;
int used[999999];
int arr[5][5];
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};
int answer = 0;

void rec(int cur, int len, int x, int y){
    if (len == 1000000){
        if (used[cur] == 1){
            answer++;
            used[cur] = 0;
        }
    }
    else{
        for (int z = 0; z < 4; z++){
            int cx = x + dx[z];
            int cy = y + dy[z];
            if (cx >= 0 && cx < 5 && cy >= 0 && cy < 5){
                rec(cur + len * arr[cx][cy], len * 10, cx, cy);
            }
        }
    }
}
int main(){
    for (int x = 0; x < 5; x++){
        for (int y = 0; y < 5; y++){
            cin >> arr[x][y];
        }
    }
    for (int x = 0; x < 999999; x++){
        used[x] = 1;
    }
    for (int x = 0; x < 5; x++){
        for (int y = 0; y < 5; y++){
            rec(0, 1, x, y);
        }
    }
    cout << answer;
}
