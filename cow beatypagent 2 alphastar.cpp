#include <iostream>
#include <queue>
#include <fstream>
using namespace std;

void solve()
{
    int n;
    int m;
    cin >> n >> m;
    char arr[n][m];
    int visited[n][m];
    int newarr[n][m];
    for (int x = 0; x < n; x++){
        for (int y = 0; y < m; y++){
            cin >> arr[x][y];
            visited[x][y] = 1;
            newarr[x][y] = 0;
        }
    }

    int dx[4] = {-1, 0, 1, 0};
    int dy[4] = {0, -1, 0, 1};
    queue <int> qrow;
    queue <int> qcol;
    int cur = 1;
    for (int x = 0; x < n; x++){
        for (int y = 0; y < m; y++){
            if (visited[x][y] == 1 && arr[x][y] == 'X'){
                qrow.push(x);
                qcol.push(y);
                while(qcol.empty() == false){
                    visited[qrow.front()][qcol.front()] = 0;
                    newarr[qrow.front()][qcol.front()] = cur;
                    for (int z = 0; z < 4; z++){
                        int cx = qrow.front() + dx[z];
                        int cy = qcol.front() + dy[z];
                        if (cx >= 0 && cx < n && cy >= 0 && cy < m){
                            if (arr[cx][cy] == 'X' && visited[cx][cy] == 1){
                                visited[cx][cy] = 0;
                                qcol.push(cy);
                                qrow.push(cx);
                            }
                        }
                    }
                    qcol.pop();
                    qrow.pop();
                }
                cur++;
            }
        }
    }
    int answer = 100000;
    for (int x = 0; x < n; x++){
        for (int y = 0; y < m; y++){
           for (int z = 0; z < n; z++){
            for (int c = 0; c < m; c++){
                if (newarr[x][y] == 1 && newarr[z][c] == 2){
                    answer = min(answer, abs(z - x) + abs(c - y) - 1);
                }
              }
           }
        }
    }
    cout << answer;


}

int main()
{

    solve();
}
