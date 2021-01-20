#include <fstream>
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;

int r, c, k;
int used[5][5];
char farm[5][5];
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};
int answer = 0;
void rec(int curx, int cury, int moves){

    if (curx == 0 && cury == c - 1){
        answer++;
    }
    else{
        for (int z = 0; z < 4; z++){
            int cx = curx + dx[z];
            int cy = cury + dy[z];
            if (cx >= 0 && cx < r && cy >= 0 && cy < c){
                if (farm[cx][cy] == '.' && used[cx][cy] == 1 && moves + 1 <= k - 1){

                    used[cx][cy] = 2;
                    rec(cx, cy, moves + 1);
                    used[cx][cy] = 1;
                }
            }
        }
    }
}
int main(){
    cin >> r >> c >> k;
    for (int x = 0; x < r; x++){
        for (int y = 0; y < c; y++){
            cin >> farm[x][y];
            used[x][y] = 1;
        }
    }
    used[r - 1][0] = 2;
    rec(r - 1, 0, 0);
    cout << answer;

}
