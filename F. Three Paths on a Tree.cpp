#include <fstream>
#include <string>
#include <iostream>
#include <math.h>
#include <algorithm>
#include<bits/stdc++.h>
#include <vector>
using namespace std;

int n;
int used[200001];
int marks[200001];
vector<int> arr[200001];
int fpoint= -1;
int fdist = 0;

void dfs(int cur, int dist){
    if (dist > fdist){
        fdist = dist;
        fpoint = cur;
    }
    used[cur] = 2;
    for (int x = 0; x < arr[cur].size(); x++){
        if (used[arr[cur][x]] == 1){
            dfs(arr[cur][x], dist + 1);
        }
    }

}
int main(){
    cin >> n;
    int one, two;
    for (int x = 0; x < n; x++){
        cin >> one >> two;
        arr[one - 1].push_back(two - 1);
        arr[two - 1].push_back(one - 1);
    }
    int p1 = 0;
    int p2 = 0;
    dfs(0,0);
    p1 = fpoint;
    fpoint = -1;
    fdist = 0;
    dfs(p1, 0);
    p2 = fpoint;
    cout << p1 << " " << p2 << "\n";

}
