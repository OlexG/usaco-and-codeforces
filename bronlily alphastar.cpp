#include <fstream>
#include <string>
#include <iostream>
#include <algorithm>
#include <queue>
#include <set>
#include <map>
using namespace std;
int m, n, m1, m2;

int main(){
    cin >> n >> m >> m1 >> m2;
    int arr[n][m];
    int used[n][m];
    int desx, desy;
    queue<pair<int, int>> pos;
    queue<int> moves;
    for (int x = 0; x < n; x++){
        for (int y = 0; y < m; y++){
            cin >> arr[x][y];
            used[x][y] = 1;
            if (arr[x][y] == 3){
                pos.push(make_pair(x, y));
                moves.push(0);
            }
            else if (arr[x][y] == 4){
                desx = x;
                desy = y;
            }
        }
    }
    int dx[4] = {1, -1, 1, -1};
    int dy[4] = {1, -1, -1, 1};
    bool notdone = true;
    while (pos.empty() == false){
        int curx = pos.front().first;
        int cury = pos.front().second;
        //cout << curx << " " << cury << "\n";
        if (curx == desx && cury == desy){
            cout << moves.front();
            break;
        }
        else{
            for (int z = 0; z < 4; z++){
                int cx = curx + dx[z] * m1;
                int cy = cury + dy[z] * m2;
                if (cx >= 0 && cx < n && cy >= 0 && cy < m){
                    //cout << cx << " " << cy << "\n";
                    if (arr[cx][cy] == 1 && used[cx][cy] == 1){
                        used[cx][cy] = 2;
                        pos.push(make_pair(cx, cy));
                        moves.push(moves.front() + 1);
                    }
                    else if (arr[cx][cy] == 4){
                        used[cx][cy] = 2;
                        pos.push(make_pair(cx, cy));
                        moves.push(moves.front() + 1);
                    }
                }
                cx = curx + dx[z] * m2;
                cy = cury + dy[z] * m1;
                if (cx >= 0 && cx < n && cy >= 0 && cy < m){
                    if (arr[cx][cy] == 1 && used[cx][cy] == 1){
                        used[cx][cy] = 2;
                        pos.push(make_pair(cx, cy));
                        moves.push(moves.front() + 1);
                    }
                    else if (arr[cx][cy] == 4){
                        used[cx][cy] = 2;
                        pos.push(make_pair(cx, cy));
                        moves.push(moves.front() + 1);
                    }
                }
            }
            pos.pop();
            moves.pop();
        }
    }

}
