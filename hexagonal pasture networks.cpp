#include <fstream>
#include <string>
#include <iostream>
#include <math.h>
#include <algorithm>
#include <vector>
using namespace std;
int k, n, l;
int dx[6] = {-1, -1, 0, 0, 1 ,1};
int dy[6] = {-1, 1, -2, 2, -1, 1};
int main(){
    cin >> k >> n >> l;
    int col = 4 * k - 3;
    int row = 2 * k - 1;
    int arr[row][col];
    int visited[row][col];
    int cur = 1;
    int curstart = k - 1;
    int curnum = k;
    bool down = true;
    for (int x = 0; x < row; x++){
        for (int y = 0; y < col; y++){
            arr[x][y] = -1;
            visited[x][y] = -1;
        }
    }
    for (int x = 0; x < row; x++){
        for (int y = 0; y < curnum; y++){
            arr[x][curstart + y * 2] = cur;
            visited[x][curstart + y * 2] = -2;
            cur++;
        }
        if (down){
            curstart--;
            curnum++;
        }
        else{
            curstart++;
            curnum--;
        }
        if (curstart == 0){
            down = false;
        }


    }
    for (int x = 0; x < row; x++){
        for (int y = 0; y < col; y++){

            if (arr[x][y] == n){
                visited[x][y] = 1;
            }
        }

    }
    for (int x = 1; x < l + 1; x++){
        for (int y = 0; y < row; y++){
            for (int z = 0; z < col; z++){
                if (visited[y][z] == x){
                    for (int c = 0; c < 6; c++){
                        int cx = y + dx[c];
                        int cy = z + dy[c];
                        if (cx >= 0 && cx < row && cy >= 0 && cy < col){
                            if (visited[cx][cy] == -2){
                                visited[cx][cy] = x + 1;
                            }
                        }
                    }
                }
            }
        }
    }
    vector<int> answers;
    for (int x = 0; x < row; x++){
        for (int y = 0; y < col; y++){
            if (visited[x][y] == l + 1){
                answers.push_back(arr[x][y]);
            }
        }
    }
    sort(answers.begin(), answers.end());
    cout << answers.size() << "\n";
    for (int x = 0; x < answers.size(); x++){
        cout << answers[x] << "\n";
    }
}
