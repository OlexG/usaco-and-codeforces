#include <fstream>
#include <string>
#include <iostream>
#include <math.h>
#include <algorithm>
#include<bits/stdc++.h>
#include <vector>
using namespace std;

int n, k;
int mat[9][9];
int answer = 0;
int used[9];
void rec(int cur, int cursum, int total){
    //cout << cur << " " << cursum << "\n";
    if (total >= n - 1){
        if (cursum + mat[cur][0] == k){
            answer++;
        }
    }
    else{
        for (int x = 0; x < n; x++){
            if (used[x] == 1){
                used[x] = 2;
                rec(x, cursum + mat[cur][x], total + 1);
                used[x] = 1;
            }
        }
    }
}
int main(){
    cin >> n >> k;
    for (int x = 0; x < n; x++){
        used[x] = 1;
        for (int y = 0; y < n; y++){
            cin >> mat[x][y];
        }
    }
    used[0] = 2;
    rec(0, 0, 0);
    cout << answer << "\n";
}

