#include <fstream>
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;
int n;
char arr[100][100][100];
int used[100][100][100];

int dz[6] = {-1,1,0,0,0,0};
int dy[6] = {0,0,1,-1,0,0};
int dx[6] = {0,0,0,0,1,-1};
int curnum = 0;
void rec(int z, int x, int y){
    if (used[z][x][y] == 2){
        return;
    }
    else{
        used[z][x][y] = 2;
        for (int c = 0; c < 6; c++){
            int cz = z + dz[c];
            int cx = x + dx[c];
            int cy = y + dy[c];
            if (cz >= 0 && cz < n && cy >= 0 && cy < n && cx >= 0 && cx < n){
                if (used[cz][cx][cy] == 1 && arr[cz][cx][cy] == '*'){
                    rec(cz, cx, cy);
                }
            }
        }
    }
}
int main(){
    cin >> n;
    for (int z = 0; z < n; z++){
        for (int x = 0; x < n; x++){
            for (int y = 0; y < n; y++){
                cin >> arr[z][x][y];
                used[z][x][y] = 1;
            }
        }
    }

    for (int z = 0; z < n; z++){
        for (int x = 0; x < n; x++){
            for (int y = 0; y < n; y++){
                if (arr[z][x][y] == '*' && used[z][x][y] == 1){
                    rec(z,x,y);
                    curnum++;
                }
            }
        }
    }
    cout << curnum << "\n";


}
