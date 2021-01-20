#include <fstream>
#include <string>
#include <iostream>
#include <math.h>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

#include <iostream>
#include <queue>

using namespace std;

void solve()
{
    int n;
    cin >> n;
    char arr[n][n];
    for (int x = 0; x < n; x++){
        for (int y = 0; y < n; y++){
            cin >> arr[x][y];
        }
    }
    queue<int> qrow;
    queue<int> qcol;
    int dx[4] = {-1, 0, 1, 0};
    int dy[4] = {0, -1, 0, 1};
    int answer = 0;
    for (int x = 0; x < n; x++){
        for (int y = 0; y < n; y++){
            if (arr[x][y] == '*'){
                answer++;
                arr[x][y] = '.';
                qrow.push(x);
                qcol.push(y);
                while(qrow.empty() == false){
                    for (int z = 0; z < 4; z++){
                        int cx = qrow.front() + dx[z];
                        int cy = qcol.front() + dy[z];
                        if (cx >= 0 && cx < n && cy >= 0 && cy < n){
                            if (arr[cx][cy] == '*'){
                                qrow.push(cx);
                                qcol.push(cy);
                                arr[cx][cy] = '.';
                            }
                        }
                    }
                    qrow.pop();
                    qcol.pop();

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

