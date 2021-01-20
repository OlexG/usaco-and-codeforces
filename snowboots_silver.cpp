#include <fstream>
#include <string>
#include <iostream>
#include <math.h>
#include <algorithm>
#include<bits/stdc++.h>
#include <vector>
using namespace std;
int n, m;
int arr[250];
int used[250][250];
bool answer = false;
vector<pair<int , int>> boots;
void dfs(int curboot, int curx){
    //cout << curboot << " " << curx << "\n";
    if (curx >= n - 1){
        answer = true;
        return;
    }
    used[curx][curboot] = 2;
    for (int x = curx + 1; x <= min(n - 1,curx + boots[curboot].second); x++){
        if (used[x][curboot] == 1 && arr[x] <= boots[curboot].first){
            used[x][curboot] = 2;
            dfs(curboot, x);
        }
    }
    for (int x = curboot + 1; x < boots.size(); x++){
        if (used[curx][x] == 1 && boots[x].first >= arr[curx]){
            used[curx][x] = 2;
            dfs(x, curx);
        }
    }

}
int main(){
    ifstream in("snowboots.in");
    ofstream out("snowboots.out");
    in >> n >> m;
    for (int x = 0; x < n; x++){
        in >> arr[x];
    }
    int one, two;
    int manswer = 250;
    for (int x = 0; x < m; x++){
        for (int y = 0; y < 250; y++){
            for (int z = 0; z < 250; z++){
                used[y][z] = 1;
            }
        }
        in >> one >> two;
        boots.push_back(make_pair(one ,two));
        dfs(0,0);
        if (answer == true){
            manswer = min(manswer, x);
        }
    }
    out << manswer << "\n";

}

