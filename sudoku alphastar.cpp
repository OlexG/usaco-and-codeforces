#include <fstream>
#include <string>
#include <iostream>
#include <algorithm>
#include <queue>
#include <math.h>
#include <vector>
using namespace std;

int arr[9][9];
bool solution = true;
vector<pair<int, int>> backtrack;

bool checkrow(int x, int y, int want){
    for (int z = 0; z < 9; z++){
        if (arr[x][z] == want && z != y){
            return false;
        }
    }
    return true;
}
bool checkcol(int x, int y, int  want){
    for (int z = 0; z < 9; z++){
        if (arr[z][y] == want && z != x){
            return false;
        }
    }
    return true;
}
bool checksquare(int x, int y, int want){
    int cx = 3  * floor((x)/3);
    int cy = 3 * floor((y)/3);
    for (int z = cx; z < cx + 3; z++){
        for (int c = cy; c < cy + 3; c++){
            if (arr[z][c] == want){
                if (z != x || c != y){
                    return false;
                }
            }
        }
    }
    return true;
}
int rec(int curx, int cury){

    if (arr[curx][cury] == 9){
        if (backtrack.size() == 0){
            if (solution){
                cout << "NO SOLUTION";
            }
            solution = false;
            return 0;
        }
        arr[curx][cury] = 0;
        int newx = backtrack[backtrack.size() - 1].first;
        int newy = backtrack[backtrack.size() - 1].second;
        backtrack.pop_back();
        return rec(newx, newy);
    }
    else{
        int cur = arr[curx][cury] + 1;
        arr[curx][cury] = arr[curx][cury] + 1;
        while(true){
            if (cur == 10){
                arr[curx][cury] = 0;
                if (backtrack.size() == 0){
                    if (solution){
                        cout << "NO SOLUTION";
                    }
                    solution = false;
                    return 0;
                }
                int newx = backtrack[backtrack.size() - 1].first;
                int newy = backtrack[backtrack.size() - 1].second;
                backtrack.pop_back();
                return rec(newx, newy);
            }
            if (checkrow(curx, cury, cur) && checkcol(curx, cury, cur) && checksquare(curx, cury, cur)){
                arr[curx][cury] = cur;
                break;
            }
            else{
                cur++;
            }
        }
        backtrack.push_back(make_pair(curx, cury));
        for (int x = 0; x < 9; x++){
            for (int y = 0; y < 9; y++){
                if (arr[x][y] == 0){
                    return rec(x,y);
                }
            }
        }
    }
}
int main(){
    for (int x = 0; x < 9; x++){
        for(int y = 0; y < 9; y++){
            cin >> arr[x][y];
        }
    }
    for (int x = 0; x < 9; x++){
        for (int y = 0; y < 9; y++){
            if (arr[x][y] == 0){
                rec(x,y);
                break;
            }
        }
    }
    if (solution){
        for (int x = 0; x < 9; x++){
            for (int y = 0; y < 9; y++){
                cout << arr[x][y] << " ";
            }
            cout << "\n";
        }
    }
}
