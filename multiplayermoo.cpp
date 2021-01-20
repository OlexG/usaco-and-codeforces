#include <fstream>
#include <string>
#include <iostream>
#include <math.h>
#include <algorithm>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

int n;
int rtoc[70000];
set<int> rusedc[70000];
int rtos[70000];
set<int> rtor[70000];

int used[250][250];
int arr[250][250];
int r[250][250];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int counter = 0;
int amount = 0;
void dfs(int x, int y){
    amount += 1;
    used[x][y] = 2;
    r[x][y] = counter;
    for (int z = 0; z < 4; z++){
        int curx = x + dx[z];
        int cury = y + dy[z];
        if (curx < n && curx >= 0 && cury < n && cury >= 0){
            if (used[curx][cury] == 1 && arr[curx][cury] == arr[x][y]){
                dfs(curx, cury);
            }
        }
    }
}
int answer2 = 0;
int answer1 = 0;

void dfs2(int curr, int one, int two){
    amount += rtos[curr];
    if (rtoc[curr] == one){
        rusedc[curr].insert(two);
    }
    else{
        rusedc[curr].insert(one);
    }
    for (auto it:rtor[curr]){
        if (rtoc[it] == one){
            if (rusedc[it].count(two) == 0){
                dfs2(it, one, two);
            }
        }
        else if (rtoc[it] == two){
            if (rusedc[it].count(one) == 0){
                dfs2(it, one, two);
            }
        }
    }
}
int main(){
    ifstream in("multimoo.in");
    ofstream out("multimoo.out");
    in >> n;
    for (int x = 0; x < n; x++){
        for (int y = 0; y < n; y++){
            in >> arr[x][y];
            used[x][y] = 1;
        }
    }
    for (int x = 0; x < n; x++){
        for (int y = 0; y < n; y++){
            if (used[x][y] == 1){
                amount = 0;
                dfs(x, y);
                rtos[r[x][y]] = amount;
                answer1 = max(answer1, amount);
                counter++;
            }
        }
    }
    for (int x = 0; x < n; x++){
        for (int y = 0; y < n; y++){
            rtoc[r[x][y]] = arr[x][y];
        }
    }
    for (int x = 0; x < n; x++){
        for (int y = 0; y < n; y++){
            for (int z = 0; z < 4; z++){
                int curx = x + dx[z];
                int cury = y + dy[z];
                if (curx >= 0 && curx < n && cury >= 0 && cury < n){
                    if (r[curx][cury] != r[x][y]){
                        rtor[r[x][y]].insert(r[curx][cury]);
                    }
                }
            }
        }
    }
    /*for (int x = 0; x < n; x++){
        for (int y = 0; y < n; y++){
            cout << r[x][y];
        }
        cout << "\n";
    }
    for (int x = 0; x < counter; x++){
        cout << rtos[x] << " ";
    }*/
    for (int x = 0; x < counter; x++){
        for (auto it:rtor[x]){
            //cout << rusedc[x].count(rtoc[it]) << "\n";
            amount = 0;
            if (rusedc[x].count(rtoc[it]) == 0 && rusedc[it].count(rtoc[x]) == 0){
                //rusedc[x].insert(rtoc[it]);
                //rusedc[it].insert(rtoc[x]);
                dfs2(x, rtoc[it], rtoc[x]);
            }
            answer2 = max(answer2, amount);
        }
    }
    out << answer1 << "\n";
    out << answer2 << "\n";


}
