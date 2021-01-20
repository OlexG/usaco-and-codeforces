#include <fstream>
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;
int n, m, k;
int arr[30][30];
vector<pair<int, int>> curmines;
int dirx[9] = {0, 1, 0, -1, 0, 1, 1, -1, -1};
int diry[9] = {0, 0, 1, 0, -1, 1, -1, 1, -1};
void addmine(int x, int y){
    for (int z = 0; z < 9; z++){
        int cx = x + dirx[z];
        int cy = y + diry[z];
        if (cx >= 0 && cx < n && cy >= 0 && cy < m){
            arr[cx][cy] --;
        }
    }
}
void removemine(int x, int y){
    for (int z = 0; z < 9; z++){
        int cx = x + dirx[z];
        int cy = y + diry[z];
        if (cx >= 0 && cx < n && cy >= 0 && cy < m){
            arr[cx][cy] ++;
        }
    }
}
bool checkmine(int x, int y){
    for (int z = 0; z < 9; z++){
        int cx = x + dirx[z];
        int cy = y + diry[z];
        if (cx >= 0 && cx < n && cy >= 0 && cy < m){
            if (arr[cx][cy] < 0){
                return false;
            }
        }
    }
    return true;
}
bool checkarr(){
    for (int x = 0; x < n; x++){
        for (int y = 0; y < m; y++){
            if (arr[x][y] != 0){
                return false;
            }
        }
    }
    return true;
}
/*

3 20 15
1 1 0 0 0 1 2 3 3 2 1 2 2 3 2 2 1 0 1 1
2 2 1 2 2 2 2 3 3 2 1 2 2 3 2 2 2 1 3 2
2 2 1 2 2 2 2 2 1 0 0 1 1 1 0 0 1 1 2 1

*/
bool done = true;
void rec(int x, int y, int curnum){
    if (done){
        if (curnum == k){
            if (checkarr()){
                done = false;
                sort(curmines.begin(), curmines.end());
                for (int z = 0; z < curmines.size(); z++){
                    cout << curmines[z].first + 1 << " " << curmines[z].second + 1 << "\n";
                }
                return;
            }
        }
        else if (x == n - 1 && y == m){
            return;
        }
        else{
            if (x >= 2){
                if (y >= 2){
                    if (arr[x - 2][y - 2] > 0){
                        return;
                    }
                }
                if (arr[x - 2][y] > 0){
                    return;
                }
            }
            if (x >= 1 && y >= 2){
                if (arr[x - 1][y - 2] > 0){
                    return;
                }
            }
            if (curmines.size() > k){
                return;
            }
            addmine(x, y);
            curmines.push_back(make_pair(x, y));
            if (checkmine(x, y)){
                if (y == m - 1){
                    rec(x + 1, 0, curnum + 1);
                }
                else{
                    rec(x, y + 1, curnum + 1);
                }
            }
            curmines.pop_back();
            removemine(x, y);
            if (y == m - 1){
                rec(x + 1, 0, curnum);
            }
            else{
                rec(x, y + 1, curnum);
            }
        }
    }
}
int main(){
    cin >> n >> m >> k;
    for (int x = 0; x < n; x++){
        for (int y = 0; y  < m; y++){
            cin >> arr[x][y];
        }
    }
    rec(0,0,0);
    if (done){
        cout << "NO SOLUTION" << "\n";
    }
}
