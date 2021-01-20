#include <fstream>
#include <string>
#include <iostream>
#include <math.h>
#include <algorithm>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

int n;
char arr[20][20];
int rx;
int ry;
int lx;
int ly;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int used[20][20];
int answer = 0;
int dfs(int x, int y){
    used[x][y] = 2;
    for (int z = 0; z < 4; z++){
        int curx = x + dx[z];
        int cury = y + dy[z];
        if (curx >= rx && curx <= lx && cury >= ry && cury <= ly){
            if (used[curx][cury] == 1 && arr[curx][cury] == arr[x][y]){
                dfs(curx, cury);
            }
        }
    }
}
int main(){
    ifstream in("where.in");
    ofstream out("where.out");
    in >> n;
    for (int x = 0; x < n; x++){
        for (int y = 0; y < n; y++){
            in >> arr[x][y];
            used[x][y] = 1;
        }
    }
    int answer = 0;
    int allowed[20][20][20][20];
    for (int x = 0; x < 20 ; x++){
        for (int y = 0; y < 20; y++){
            for (int z = 0; z < 20; z++){
                for (int i = 0; i < 20; i++){
                    allowed[x][y][z][i] = 1;
                }
            }
        }
    }
    for (int sizex = n - 1; sizex >= 0; sizex --){
        for (int sizey = n - 1; sizey >= 0; sizey--){
            for (int x = 0; x < n; x++){
                for (int y = 0; y < n; y++){
                    if (x + sizex < n && y + sizey < n && allowed[x][y][x + sizex][y + sizey] == 1){
                        int sx = x;
                        int ex = x + sizex;
                        int sy = y;
                        int ey = y + sizey;
                        rx = sx;
                        ry = sy;
                        lx = ex;
                        ly = ey;
                        bool works = true;
                        char one = '1';
                        char two = '2';
                        for (int z = sx; z <= ex; z++){
                            for (int g = sy; g <= ey; g++){
                                used[z][g] = 1;
                                if (one == '1'){
                                    one = arr[z][g];
                                }
                                else if (two == '2' && arr[z][g] != one){
                                    two = arr[z][g];
                                }
                                else{
                                    if (arr[z][g] != one && arr[z][g] != two){
                                        works = false;
                                        //cout << x << " " << y << " " << sizex << " " << sizey << "\n";
                                    }
                                }
                            }
                        }
                        int counter1 = 0;
                        int counter2 = 0;
                        for (int z = sx; z <= ex; z++){
                            for (int g = sy; g <= ey; g++){
                                if (used[z][g] == 1){
                                    dfs(z, g);
                                    if (arr[z][g] == one){
                                        counter1++;
                                    }
                                    else{
                                        counter2++;
                                    }
                                }
                            }
                        }
                        if ((counter1 == 1 && counter2 >= 2) || (counter2 == 1 && counter1 >= 2)){
                            if (works){
                                //cout << x << " " << y << " " << sizex << " " << sizey << "\n";
                                for (int z = sx; z <= ex; z++){
                                    for (int g = sy; g <= ey; g++){
                                        for (int h = sx; h <= ex; h++){
                                            for (int j = sy; j <= ey; j++){
                                                allowed[z][g][h][j] = 2;
                                            }
                                        }
                                    }
                                }
                                //cout << x << " " << y << " " << sizex << " " << sizey << "\n";
                                answer++;
                            }
                        }

                    }
                }
            }
        }
    }

    out << answer << "\n";


}
