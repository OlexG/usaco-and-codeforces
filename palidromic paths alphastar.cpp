#include <fstream>
#include <string>
#include <iostream>
#include <algorithm>
#include<set>
#include <math.h>
using namespace std;
set<string> vis1;
set<string> vis;
int n;
char arr[18][18];


int dirx[2] = {0, 1};
int diry[2] = {1, 0};
int dirxt[2] = {0, -1};
int diryt[2] = {-1, 0};
char ran[18] = {'Q', 'W','E','R','T','Y','U','I','O','P','A','S','D','F','G','H','J', 'K'};
void rec(int x, int y, string cur){
    if (cur.size() == n){
        vis.insert(cur);
        cur += ran[x];
        vis1.insert(cur);

    }
    else{
        for (int z = 0; z < 2; z++){
            int cx = x + dirx[z];
            int cy = y + diry[z];
            if (cx < n && cy < n){
                rec(cx, cy, cur + arr[cx][cy]);
            }
        }
    }
}
int answer = 0;
void rec2(int x, int y, string cur){
    //cout << cur << "\n";
    if (cur.size() == n){
        const bool is_inagain = vis.find(cur) != vis.end();
        string newc = cur;
        cur += ran[x];
        const bool is_in = vis1.find(cur) != vis1.end();
        if (is_in && is_inagain){
            answer++;
            vis1.erase(cur);
            vis.erase(newc);
        }
    }
    else{
        for (int z = 0; z < 2; z++){
            int cx = x + dirxt[z];
            int cy = y + diryt[z];
            if (cx >= 0 && cy >= 0){
                rec2(cx, cy, cur + arr[cx][cy]);
            }
        }
    }
}
int main(){
    cin >> n;
    for (int x = 0; x < n; x++){
        for (int y = 0; y < n; y++){
            cin >> arr[x][y];
        }
    }
    string start = "";
    start += arr[0][0];
    rec(0, 0, start);
    start = "";
    start += arr[n-1][n-1];
    rec2(n - 1, n - 1, start);
    cout << answer;

}
