#include <fstream>
#include <string>
#include <iostream>
#include <math.h>
#include <algorithm>
#include <vector>
using namespace std;
int n, m;
char arr[50][50];
int numarr[50][50];
int used[50][50];
int dx[4] = {0, -1, 0, 1};
int dy[4] = {1, 0, -1, 0};
int rec(int x, int y, int num){
    if (used[x][y] == 1){
        used[x][y] = 2;
        numarr[x][y] = num;
        for (int z = 0; z < 4; z++){
            int cx = x + dx[z];
            int cy = y + dy[z];
            if (cx >= 0 && cx < n && cy >=0 && cy < m && arr[cx][cy] == 'X'){
                rec(cx, cy, num);
            }
        }
    }
}
int indanswer = 100000;
int ovanswer = 100000;
void recpath(int x, int y, int total){
     cout << x << y << "\n";
    if (numarr[x][y] == 3 && used[x][y] == 1){
        used[x][y] = 2;
        indanswer = min(total, indanswer);
    }
    else if (used[x][y] == 1){

        used[x][y] = 2;
        for (int z = 0; z < 4; z++){
            int cx = x + dx[z];
            int cy = y + dy[z];
            if (cx >= 0 && cx < n && cy >=0 && cy < m){
                if (numarr[cx][cy] == 0 || numarr[cx][cy] == 3){
                    recpath(cx, cy, total + 1);
                    used[cx][cy] = 1;
                }
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
            numarr[x][y] = 0;
            if (arr[x][y] == '.'){
                used[x][y] = 2;
            }
        }
    }
    int num = 1;
    for (int x = 0; x < n; x++){
        for (int y = 0; y < m; y++){
            if (used[x][y] == 1){
                num++;
                rec(x,y, num);
            }
        }
    }
    /*for (int x = 0; x < n; x++){
        for (int y = 0; y < m; y++){
            cout << numarr[x][y];
        }
        cout << "\n";
    }*/

    for (int x = 0; x < n; x++){
        for (int y = 0; y < m; y++){
            indanswer = 100000;
            if (numarr[x][y] == 2){
                for (int z = 0; z < n; z++){
                    for (int c = 0; c < m; c++){
                        if (numarr[z][c] == 3){
                            ovanswer = min(ovanswer, abs(x - z) + abs(c - y) - 1);
                        }
                    }
                }
            }

        }
    }
    cout << ovanswer;


}
