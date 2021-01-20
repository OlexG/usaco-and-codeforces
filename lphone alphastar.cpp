/*
7 8
.......
......C
......*
*****.*
....*..
.......
.C...*.
.......
*/
#include <fstream>
#include <string>
#include <iostream>
#include <math.h>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

int n, m;
char arr[100][100];
int used[100][100];
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};
queue<pair<int, int>> cur;
queue<int> dir;
int main(){
    cin >> m >> n;
    bool first = true;
    for (int x = 0; x < n; x++){
        for (int y = 0; y < m; y++){
            cin >> arr[x][y];
            used[x][y] = 1;
            if (arr[x][y] == 'C' && first){
                arr[x][y] = 'N';
                first = false;
            }
            else if (arr[x][y] == 'C'){
                used[x][y] = 2;
                cur.push(make_pair(x, y));
            }
        }
    }
    int answer = 0;
    dir.push(-1);
    while (cur.empty() == false){
        used[cur.front().first][cur.front().second] = 2;
        int curx = cur.front().first;
        int cury = cur.front().second;
        int num = dir.front();
        while(curx - 1 >= 0 && arr[curx - 1][cury] != '*'){
            curx--;
            if (used[curx][cury] == 1){
                if (arr[curx][cury] == 'N'){
                    answer = num + 1;
                }
                used[curx][cury] = 2;
                cur.push(make_pair(curx, cury));
                dir.push(num + 1);
            }
        }
        curx = cur.front().first;
        cury = cur.front().second;
        while(curx + 1 < n && arr[curx + 1][cury] != '*'){
            curx++;
            if (used[curx][cury] == 1){
                if (arr[curx][cury] == 'N'){
                    answer = num + 1;
                }
                used[curx][cury] = 2;
                cur.push(make_pair(curx, cury));
                dir.push(num + 1);
            }
        }
        curx = cur.front().first;
        cury = cur.front().second;
        while(cury + 1 < m && arr[curx][cury + 1] != '*'){
            cury++;
            if (used[curx][cury] == 1){
                if (arr[curx][cury] == 'N'){
                    answer = num + 1;
                }
                used[curx][cury] = 2;
                cur.push(make_pair(curx, cury));
                dir.push(num + 1);
            }
        }
        curx = cur.front().first;
        cury = cur.front().second;
        while(cury - 1 >= 0 && arr[curx][cury - 1] != '*'){
            cury--;
            if (used[curx][cury] == 1){
                if (arr[curx][cury] == 'N'){
                    answer = num + 1;
                }
                used[curx][cury] = 2;
                cur.push(make_pair(curx, cury));
                dir.push(num + 1);
            }
        }
        cur.pop();
        dir.pop();
    }

    cout << answer;



}
