#include <fstream>
#include <string>
#include <iostream>
#include <math.h>
#include <algorithm>
#include <vector>
#include <cstdio>
#include <bits/stdc++.h>
using namespace std;
/*
13 6 7
6 7 8
2 3 4
10 11 12
8 9 10
1 2 13
4 5 6
*/

int n, m, need;
vector<int> splits[5001];
int visited[5001];
bool notdone = true;
void rec(int cur, int distance, string curstring){

    if (notdone){
        if (cur == need - 1){
            notdone = false;
            cout << distance + 1 << "\n";
            cout << curstring;
            cout << cur + 1 << "\n";
        }
        else{
            visited[cur] = 0;

            if (splits[cur].size() != 0){
            if (visited[splits[cur][0]])
                {
                    rec(splits[cur][0], distance + 1, curstring + to_string(cur + 1) + "\n");
                }
            if (visited[splits[cur][1]])
                {
                    rec(splits[cur][1], distance + 1, curstring + to_string(cur + 1) + "\n");
                }
            }
        }
    }
}
int main(){

    cin >> n >> m >> need;
    int one, two, three;
    for (int x = 0; x < n; x ++){
        visited[x] = 1;
    }
    for (int x = 0; x < m; x ++){
        cin >> one >> two >> three;
        splits[one - 1].push_back(two - 1);
        splits[one - 1].push_back(three - 1);
    }
    rec(0, 0, "");



}

