#include <fstream>
#include <string>
#include <iostream>
#include <math.h>
#include <algorithm>
#include <vector>
using namespace std;
int n, k;
int arr[100][10];
int used[100][10];
/*
6 3
0000000000
0000000300
0054000300
1054502230
2211122220
1111111223
*/
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};
int total = 0;
bool notdone = true;
void howmany(int x, int y, int desired){
/*
0000000300
0054000300
1054502230
2211122220
1111111223
*/

    if (used[x][y] == 2){
        used[x][y] = 3;
        total = total + 1;
        int curx;
        int cury;
        for (int z = 0; z < 4; z++){
            curx = x + dx[z];
            cury = y + dy[z];
            if (curx >= 0 && curx < n && cury >= 0 && cury < 10){
                if (arr[curx][cury] == desired){
                    howmany(curx, cury, desired);
                }
            }
        }

    }
}
void undo(int x, int y, int desired){

    if (used[x][y] == 1 || used[x][y] == 3){
        used[x][y] = 2;
        int curx;
        int cury;
        for (int z = 0; z < 4; z++){
            curx = x + dx[z];
            cury = y + dy[z];
            if (curx >= 0 && curx < n && cury >= 0 && cury < 10){
                if (arr[curx][cury] == desired){
                    undo(curx, cury, desired);
                }
            }
        }

    }
}
void destroy(int x, int y, int desired){
    if (used[x][y] == 3){
        used[x][y] = 1;
        arr[x][y] = 0;
        int curx;
        int cury;
        for (int z = 0; z < 4; z++){
            curx = x + dx[z];
            cury = y + dy[z];
            if (curx >= 0 && curx < n && cury >= 0 && cury < 10){
                if (arr[curx][cury] == desired){
                    destroy(curx, cury, desired);
                }
            }
        }
    }
}
void applyg(){
    vector<int> em;
    for (int y = 0; y < 10; y ++){
        em.clear();
        for (int x = n - 1; x >= 0; x --){
            if (arr[x][y] != 0){
                em.push_back(arr[x][y]);
            }
        }
        for (int x = 0; x < n; x ++){
            if (x < em.size()){
                arr[n - x - 1][y] = em[x];
            }
            else{
                arr[n-x - 1][y] = 0;
            }
        }
        cout << "\n";

    }
}
int main(){
    ifstream in("mooyomooyo.in");
    ofstream out("mooyomooyo.out");
    in >> n >> k;
    string cur;

    for (int x = 0; x < n; x ++){
        in >> cur;
        for (int y = 0; y < 10; y ++){
            arr[x][y] = cur[y] - 48;
            used[x][y] = 2;
        }
    }
    while(notdone){
        notdone = false;
         for (int x = 0; x < n; x ++){
            for (int y = 0; y < 10; y ++){
                total = 0;
                if (arr[x][y] != 0){
                    howmany(x, y, arr[x][y]);
                    if (total >= k){
                        notdone = true;
                        destroy(x, y, arr[x][y]);
                    }
                    undo(x, y, arr[x][y]);
                }
            }
        }
        applyg();


    }

    for (int x = 0; x < n; x ++){

        for (int y = 0; y < 10; y ++){
            out << arr[x][y];
        }
        out << "\n";
    }








}
