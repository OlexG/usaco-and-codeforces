#include <fstream>
#include <string>
#include <iostream>
#include <math.h>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
char arr[100][100];
int visited[100][100];
int x, y, mx, my;
queue <int> qrow;
queue <int> qcol;
queue <int> dist;
int main(){
    cin >> x >> y >> mx >> my;
    for (int z = 0; z < y; z++){
        for (int c = 0; c < x; c++){
            cin >> arr[z][c];
            visited[z][c] = 1;
        }
    }
    int curx = y - my;
    int cury = mx - 1;
    arr[curx][cury] = 'M';
    qrow.push(curx);
    qcol.push(cury);
    dist.push(0);
    int dx[8] = {-1, 0, 1, 0, 1, 1, -1, -1};
    int dy[8] = {0, -1, 0, 1,-1, 1, -1, 1};
    int answer = 0;
    while (qrow.empty() == false){
        visited[qrow.front()][qcol.front()] = 2;
        answer = max(answer, dist.front());
        for (int z = 0; z < 8; z++){
            int cx = qrow.front() + dx[z];
            int cy = qcol.front() + dy[z];
            if (cx >= 0 && cx < y && cy >= 0 && cy < x){
                if (arr[cx][cy] == '.' && visited[cx][cy] == 1){
                    visited[cx][cy] = 2;
                    arr[cx][cy] = 'M';
                    dist.push(dist.front() + 1);
                    qrow.push(cx);
                    qcol.push(cy);
                }
            }
        }
        qrow.pop();
        qcol.pop();
        dist.pop();
    }

    cout << answer;
}
