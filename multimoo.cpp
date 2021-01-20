#include <fstream>
#include <string>
#include <iostream>
#include <math.h>
#include <algorithm>
#include <vector>
using namespace std;
int arr[250][250];
int visited1[250][250];
int visited2[250][250];
int n;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int counter = 0;
int answer1 = 0;
int answer2 = 0;
int numvis = 2;
int curvis = 3;
void dfs1(int x, int y, int val, int curreg){
    visited1[x][y] = 1;
    counter++;
    for (int z = 0; z < 4; z++){
        int cx = x + dx[z];
        int cy = y + dy[z];

        if (cx >= 0 && cx < n && cy >= 0 && cy < n){
            if (visited1[cx][cy] == 2 && arr[cx][cy] == val){
                dfs1(cx, cy, val, curreg);
            }
        }
    }
}
void dfs2(int x, int y, int val1, int val2){
    visited2[x][y] = curvis;
    counter++;
    for (int z = 0; z < 4; z++){
        int cx = x + dx[z];
        int cy = y + dy[z];

        if (cx >= 0 && cx < n && cy >= 0 && cy < n){
            if (visited2[cx][cy] < curvis){
                if (arr[cx][cy] == val1 || arr[cx][cy] == val2){
                    dfs2(cx, cy, val1, val2);
                }
            }
        }
    }
}
int main(){
    ifstream in("multimoo.in");
    ofstream out("multimoo.out");
    int curnum = 1;
    in >> n;
    for (int x = 0; x < n; x++){
        for (int y = 0; y < n; y ++){
            in >> arr[x][y];
            visited1[x][y] = 2;
            visited2[x][y] = 2;
        }
    }
    int curreg = 0;
    for (int x = 0; x < n; x++){
        for (int y = 0; y < n; y++){
            if (visited1[x][y] == 2){
                counter = 0;
                dfs1(x,y,arr[x][y], curreg);
                answer1 = max(answer1, counter);
                curreg ++;
            }
        }
    }
    counter = 0;
    for (int x = 0; x < n; x++){
        if (n * n == curreg){
            answer2 = n * n;
            break;
        }
        for (int y = 0; y < n; y++){
            if (y < n - 1){
                if (arr[x][y] != arr[x][y + 1]){
                    counter = 0;
                    dfs2(x,y,arr[x][y], arr[x][y + 1]);
                    answer2 = max(answer2, counter);
                    curvis++;
                }
            }
        }
    }
    out << answer1 << "\n" << answer2 << "\n";








}
