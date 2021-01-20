#include <fstream>
#include <string>
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

int n, m;
int main(){
    cin >> n >> m;
    char arr[n][m];
    int used[n][m];
    queue<pair<int, int>> pos;
    queue<int> moves;
    queue<bool> exited;
    for (int x = 0; x < n; x++){
        for (int y = 0; y < m; y++){
            cin >> arr[x][y];
            used[x][y] = 1;
            if (arr[x][y] == '@'){
                pos.push(make_pair(x, y));
                moves.push(0);
                exited.push(0);
            }
        }
    }
    int dx[4] = {1, 0, -1, 0};
    int dy[4] = {0, 1, 0, -1};
    while (pos.empty() == false){
        int curx = pos.front().first;
        int cury = pos.front().second;
        if (arr[curx][cury] != '.' && arr[curx][cury] != '@'){
            if (!exited.front()){
                used[curx][cury] = 2;
            }
        }
        else{
            used[curx][cury] = 2;
        }
        if (arr[curx][cury] == '='){
            cout << moves.front() << "\n";
            break;
        }
        else{
            if (arr[curx][cury] == '.' || exited.front() || arr[curx][cury] == '@'){
                for (int z = 0; z < 4; z++){
                    int cx = curx + dx[z];
                    int cy = cury + dy[z];
                    if (arr[cx][cy] != '#' && used[cx][cy] == 1){
                        used[cx][cy] = 2;
                        moves.push(moves.front() + 1);
                        pos.push(make_pair(cx, cy));
                        exited.push(0);
                    }
                }
            }
            else{
                cout << "yeet";
                char cur = arr[curx][cury];
                for (int x = 0; x < n; x++){
                    for (int y = 0; y < m; y++){
                        if (x != curx || y != cury){
                            if (arr[x][y] == cur){
                                pos.push(make_pair(x, y));
                                moves.push(moves.front());
                                exited.push(1);
                                break;
                            }
                        }
                    }
                }
            }
            pos.pop();
            moves.pop();
            exited.pop();
        }
    }
}
