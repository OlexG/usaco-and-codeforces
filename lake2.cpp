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
    int n, m, k;
    cin >> n >> m >> k;
    char arr[n][m];
    for (int x = 0; x < n; x++){
        for (int y = 0; y < m; y++){
            arr[x][y] = '.';
        }
    }
    int one, two;
    for (int x = 0; x < k; x++){
        cin >> one >> two;
        arr[one - 1][two - 1] = 'w';

    }
    queue<char> qrow;
    queue<char> qcol;
    int dx[4] = {-1, 0, 1, 0};
    int dy[4] = {0, -1, 0, 1};
    int answer = 0;
    for (int x = 0; x < n; x++){
        for (int y = 0; y < m; y++){
            if (arr[x][y] == 'w'){
                arr[x][y] = '.';
                qrow.push(x);
                qcol.push(y);
                int curanswer = 0;
                while(qrow.empty() == false){
                    curanswer++;
                    for (int z = 0; z < 4; z++){
                        int cx = qrow.front() + dx[z];
                        int cy = qcol.front() + dy[z];
                        if (cx >= 0 && cx < n && cy >= 0 && cy < m){
                            if (arr[cx][cy] == 'w'){
                                qrow.push(cx);
                                qcol.push(cy);
                                arr[cx][cy] = '.';
                            }
                        }
                    }
                    qrow.pop();
                    qcol.pop();

                }
                answer = max(answer, curanswer);
            }
        }
    }
    cout << answer;
}

int main()
{
    solve();
}

