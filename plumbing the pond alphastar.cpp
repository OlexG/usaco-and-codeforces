#include <fstream>
#include <string>
#include <iostream>
#include <algorithm>
#include <math.h>
#include <map>
#include <string>
using namespace std;
int r, c;
int dx[8] = {0, -1, 0, 1, 1, 1, -1, -1};
int dy[8] = {-1, 0, 1, 0, 1, -1, -1, 1};
int main(){
    cin >> r >> c;
    int arr[r][c];
    for (int x = 0; x < r; x++){
        for (int y = 0; y < c; y++){
            cin >> arr[x][y];
        }
    }
    int answer = 0;
    for (int x = 0; x < r; x++){
        for (int y = 0; y < c; y++){
            for (int z = 0; z < 8; z++){
                int cx = x + dx[z];
                int cy = y + dy[z];
                if (cx >= 0 && cx < r && cy >= 0 && cy < c){
                    if (arr[x][y] == arr[cx][cy]){
                        answer = max(answer, arr[x][y]);
                    }
                }
            }
        }
    }
    cout << answer;
}

