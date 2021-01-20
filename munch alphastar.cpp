#include <fstream>
#include <string>
#include <iostream>
#include <math.h>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
/*
5 6
B...*.
..*...
.**.*.
..***.
*..*.C
*/

int n, m;
char arr[100][100];
int used[100][100];
queue <int> qrow;
queue <int> qcol;
queue <int> qdist;
int main(){
    cin >> n >> m;
    qrow.push(0);
    qcol.push(0);
    qdist.push(0);
    for (int x = 0; x < n; x++){
        for (int y = 0; y < m; y++){
            cin >> arr[x][y];
            used[x][y] = 1;
        }
    }
    int dx[4] = {-1, 0, 1, 0};
    int dy[4] = {0, -1, 0, 1};
    bool notdone = true;
    int answer = 0;
    while (qrow.empty() == false && notdone){
        used[qrow.front()][qcol.front()] = 0;

        if (arr[qrow.front()][qcol.front()] == 'C'){
            answer = qdist.front();
            notdone = false;
        }
        else{
            for (int x = 0; x < 4; x++){
                int cx = qrow.front() + dx[x];
                int cy = qcol.front() + dy[x];
                if (cx >= 0 && cx < n && cy >= 0 && cy < m){
                    if (used[cx][cy] == 1 && (arr[cx][cy] == '.' ||arr[cx][cy] == 'C') ){
                        used[cx][cy] = 0;
                        qrow.push(cx);
                        qcol.push(cy);
                        qdist.push(qdist.front() + 1);
                    }
                }
            }
        }
        qrow.pop();
        qcol.pop();
        qdist.pop();
    }
    cout << answer;
}
