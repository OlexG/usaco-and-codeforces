#include <fstream>
#include <string>
#include <iostream>
#include <math.h>
#include <algorithm>
#include <vector>
#include <math.h>
using namespace std;
int n;
char arr[1000][1000];
char copyarr[1000][1000];
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};
int totalarea = 0;
int bestarea = 0;
int totalp = 0;
int bestx = 0;
int besty = 0;
void rec(int x, int y){
    arr[x][y] = '.';
    totalarea ++ ;
    for (int z = 0; z < 4; z++){
        int cx = x + dx[z];
        int cy = y + dy[z];
        if (cx >= 0 && cx < n && cy >= 0 && cy < n){
            if (arr[cx][cy] == '#'){
                rec(cx, cy);
            }
        }
    }
}
void pem(int x, int y){
    copyarr[x][y] = 'o';
    for (int z = 0; z < 4; z++){
        int cx = x + dx[z];
        int cy = y + dy[z];
        if (cx >= 0 && cx < n && cy >= 0 && cy < n){
            if (copyarr[cx][cy] == '#'){
                pem(cx, cy);
            }
            else if (copyarr[cx][cy] == '.'){
                totalp++;
            }
        }
        else{
            totalp++;
        }
    }
}
int main(){
    cin >> n;
    for (int x = 0; x < n; x++){
        for (int y = 0; y < n; y++){
            char f;
            cin >> f;
            arr[x][y] = f;
            copyarr[x][y] = f;
        }
    }

    for (int x = 0; x < n; x++){
        for (int y = 0; y < n; y++){
            totalarea = 0;
            if (arr[x][y] == '#'){
                rec(x, y);
                if(totalarea >= bestarea){
                    bestarea = totalarea;
                    bestx = x;
                    besty = y;
                }
            }
        }
    }
    pem(bestx, besty);
    cout << bestarea << " " << totalp << "\n";


}
