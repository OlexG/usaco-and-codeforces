#include <fstream>
#include <string>
#include <iostream>
#include <algorithm>
#include <queue>
#include <set>
using namespace std;
queue<int> x2;
queue<int> y2;
queue<int> x3;
queue<int> y3;
queue<int> moves;
set<int> states;
int mark[50][50][50][50];
int w[3];
int h[3];
int n, m, f;
pair<int, int> arr1[1000];
pair<int, int> arr2[1000];
pair<int, int> arr3[1000];
int minx1 = 1000;
int miny1 = 1000;
int maxy1 = -1000;
int maxx1 = -1000;
int minx2 = 1000;
int miny2 = 1000;
int maxy2 = -1000;
int maxx2 = -1000;
int minx3 = 1000;
int miny3 = 1000;
int maxy3 = -1000;
int maxx3 = -1000;
int ogx2;
int ogy2;
int ogx3;
int ogy3;
bool checkstate(int x2, int y2, int x3, int y3){
    for (int x = 0; x < n; x++){
        for (int y = 0; y < m; y++){
            if (arr1[x].first == arr2[y].first + x2 - ogx2 && arr1[x].second == arr2[y].second + y2 - ogy2){
                return false;
            }
        }
        for (int y = 0; y < f; y++){
            if (arr1[x].first == arr3[y].first + x3 - ogx3 && arr1[x].second == arr3[y].second + y3 - ogy3){
                return false;
            }
        }
    }
    for (int x = 0; x < m; x++){
        for (int y = 0; y < f; y++){
            if (arr2[x].first + x2 - ogx2 == arr3[y].first + x3 - ogx3 && arr2[x].second + y2 - ogy2 == arr3[y].second + y3 - ogy3){
                return false;
            }
        }
    }
    return true;
}
bool overlapoftwo(int minx1, int miny1, int maxx1, int maxy1, int minx2, int miny2, int maxx2, int maxy2){
    if (minx1 >= maxx2){
        return false;
    }
    if (maxx1 <= minx2){
        return false;
    }
    if (miny1 >= maxy2){
        return false;
    }
    if (maxy1 <= miny2){
        return false;
    }
    return true;
}
bool checkifdone(int x2, int y2, int x3, int y3){
    int newminx2 = minx2 + x2 - ogx2;
    int newminy2 = miny2 + y2 - ogy2;
    int newminx3 = minx3 + x3 - ogx3;
    int newminy3 = miny3 + y3 - ogy3;
    if (overlapoftwo(minx1, miny1, minx1 + w[0], miny1 + h[0], newminx2, newminy2, newminx2 + w[1], newminy2 + h[1])){
        return false;
    }
    if (overlapoftwo(minx1, miny1, minx1 + w[0], miny1 + h[0], newminx3, newminy3, newminx3 + w[2], newminy3 + h[2])){
        return false;
    }
    if (overlapoftwo(newminx2, newminy2, newminx2 + w[1], newminy2 + h[1], newminx3, newminy3, newminx3 + w[2], newminy3 + h[2])){
        return false;
    }
    return true;

}
int main(){
    cin >> n >> m >> f;
    //READ SHAPE 1
    int one, two;
    for (int x = 0; x < n; x++){
        cin >> one >> two;
        minx1 = min(one, minx1);
        miny1 = min(two, miny1);
        maxx1 = max(one, maxx1);
        maxy1 = max(two, maxy1);
        arr1[x] = make_pair(one, two);

    }
    for (int x = 0; x < 50; x++){
        for (int y = 0; y < 50; y++){
            for (int z = 0; z < 50; z++){
                for (int c = 0; c < 50; c++){
                    mark[x][y][z][c] = 1;
                }
            }
        }
    }
    maxx1++;
    maxy1++;
    w[0] = maxx1 - minx1;
    h[0] = maxy1 - miny1;
    //READ SHAPE 2
    for (int x = 0; x < m; x++){
        cin >> one >> two;
        minx2 = min(one, minx2);
        miny2 = min(two, miny2);
        maxx2 = max(one, maxx2);
        maxy2 = max(two, maxy2);
        arr2[x] = make_pair(one, two);

    }
    maxx2++;
    maxy2++;
    w[1] = maxx2 - minx2;
    h[1] = maxy2 - miny2;
    //READ SHAPE 3
    for (int x = 0; x < f; x++){
        cin >> one >> two;
        minx3 = min(one, minx3);
        miny3 = min(two, miny3);
        maxx3 = max(one, maxx3);
        maxy3 = max(two, maxy3);
        arr3[x] = make_pair(one, two);

    }
    maxx3++;
    maxy3++;
    w[2] = maxx3 - minx3;
    h[2] = maxy3 - miny3;
    //APPEND TO QUEUE NOW
    x2.push(minx2 - minx1);
    y2.push(miny2 - miny1);
    x3.push(minx3 - minx1);
    y3.push(miny3 - miny1);
    ogx2 = minx2 - minx1;
    ogy2 = miny2 - miny1;
    ogx3 = minx3 - minx1;
    ogy3 = miny3 - miny1;
    //cout << checkstate(x2.front(), y2.front() + 1, x3.front(), y3.front());
    moves.push(0);
    bool notdone = true;
    int dx[4] = {0, 1, 0, -1};
    int dy[4] = {1, 0, -1, 0};
    //cout << checkifdone(ogx2 + 3,ogy2 + 1, ogx3 + 4,ogy3);
    while (notdone && x2.empty() == false){
        if (checkifdone(x2.front(), y2.front(), x3.front(), y3.front())){
            notdone = false;
            cout << moves.front();
        }
        else if (x2.front() >= 25 || x2.front() <= -25 || y2.front() >= 25 || y2.front() <= - 25){
            cout << -1;
            notdone = false;
        }
        else{
            for (int x = 0; x < 4; x++){
                int nx2 = x2.front() + dx[x];
                int ny2 = y2.front() + dy[x];
                if (checkstate(nx2, ny2, x3.front(),  y3.front())){
                    if (mark[nx2 + 25][ny2 + 25][x3.front() + 25][y3.front() + 25] == 1){
                        x2.push(nx2);
                        y2.push(ny2);
                        x3.push(x3.front());
                        y3.push(y3.front());
                        moves.push(moves.front() + 1);
                        mark[nx2 + 25][ny2 + 25][x3.front() + 25][y3.front() + 25] = 2;
                    }
                }
            }
            for (int x = 0; x < 4; x++){
                int nx3 = x3.front() + dx[x];
                int ny3 = y3.front() + dy[x];
                if (checkstate(x2.front(), y2.front(), nx3,  ny3)){
                    if (mark[x2.front() + 25][y2.front() + 25][nx3 + 25][ny3 + 25] == 1){
                        x2.push(x2.front());
                        y2.push(y2.front());
                        x3.push(nx3);
                        y3.push(ny3);
                        moves.push(moves.front() + 1);
                        mark[x2.front() + 25][y2.front() + 25][nx3 + 25][ny3 + 25] = 2;
                    }
                }
            }
            for (int x = 0; x < 4; x++){
                int nx2 = x2.front() + dx[x];
                int ny2 = y2.front() + dy[x];
                int nx3 = x3.front() + dx[x];
                int ny3 = y3.front() + dy[x];
                if (checkstate(nx2, ny2, nx3,  ny3)){
                    if (mark[nx2 + 25][ny2 + 25][nx3 + 25][ny3 + 25] == 1){
                        x2.push(nx2);
                        y2.push(ny2);
                        x3.push(nx3);
                        y3.push(ny3);
                        moves.push(moves.front() + 1);
                        mark[nx2 + 25][ny2 + 25][nx3 + 25][ny3 + 25] = 2;
                    }
                }
            }
            x2.pop();
            y2.pop();
            x3.pop();
            y3.pop();
            moves.pop();
        }
    }
    if (notdone){
        cout << -1;
    }

}
