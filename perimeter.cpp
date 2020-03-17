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
char arr[1000][1000];
int checked[1000][1000];
int area = 0;
int cura = 0;
int curp = 0;
int perimeter = 0;
void rec(int x, int y){

    if (checked[x][y]){
        checked[x][y] = 0;
        cura = cura + 1;
        curp = curp + 4;
        int changex, changey;
        for (int z = 0; z < 4; z ++){
            changex = x + dx[z];
            changey = y + dy[z];
            if (changex >= 0 && changex <= n && changey >= 0 && changey < n && arr[changex][changey] == '#'){
                curp = curp - 1;
            }
        }
        for (int z = 0; z < 4; z ++){
            changex = x + dx[z];
            changey = y + dy[z];
            if (changex >= 0 && changex <= n && changey >= 0 && changey < n && arr[changex][changey] == '#'){
                rec(changex, changey);
            }
        }
    }
    if (cura > area){
        area = cura;
        perimeter = curp;
    }
    if (cura == area){
        if (curp < perimeter){
            perimeter = curp;
        }
    }
}
int main(){
    ifstream in("perimeter.in");
    ofstream out("perimeter.out");
    in >> n;
    for (int x = 0; x < n; x ++){
        for (int y = 0; y < n; y ++){
            in >> arr[x][y];
            checked[x][y] = 1;
        }
    }
    for (int x = 0; x < n; x ++){
        for (int y = 0; y < n; y ++){
            if (checked[x][y] && arr[x][y] == '#'){
                cura = 0;
                curp = 0;
                rec(x, y);

            }
        }
    }
    out << area << " " << perimeter << "\n";




}
