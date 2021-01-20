#include <fstream>
#include <string>
#include <iostream>
#include <math.h>
#include <algorithm>
#include <vector>
#include <bits/stdc++.h>
using namespace std;
/*
6
##....
....#.
.#..#.
.#####
...###
....##
*/
int n;
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};
int arr[1000][1000];
int used[1000][1000];
int ca = 0;
int cpe = 0;
void dfs(int curx, int cury){
    used[curx][cury] = 2;
    ca += 1;
    for (int x = 0; x < 4; x++){
        if (curx + dx[x] >= n || cury + dy[x] >= n || cury + dy[x] < 0 || curx + dx[x] < 0){
            cpe++;
        }
        else if (arr[curx + dx[x]][cury + dy[x]] == 1){
            cpe++;
        }
        else{
            if (used[curx + dx[x]][cury + dy[x]] == 1){
                dfs(curx + dx[x], cury + dy[x]);
            }
        }
    }
}
int main(){
    ifstream in("perimeter.in");
    ofstream out("perimeter.out");
    in >> n;
    char temp;
    for (int x = 0; x < n; x++){
        for (int y = 0; y < n; y++){
            in >> temp;
            if (temp == '#'){
                arr[x][y] = 2;
            }
            else{
                arr[x][y] = 1;
            }
            used[x][y] = 1;
        }
    }
    int ba = 0;
    int bp = 0;
    for (int x = 0; x < n; x++){
        for (int y = 0; y < n; y++){
            if (used[x][y] == 1 && arr[x][y] == 2){
                ca = 0;
                cpe = 0;
                dfs(x, y);
                if (ca > ba){
                    ba = ca;
                    bp = cpe;
                }
                else if (ca == ba){
                    bp = min(bp, cpe);
                }
            }
        }
    }
    out << ba << " " << bp << "\n";




}
