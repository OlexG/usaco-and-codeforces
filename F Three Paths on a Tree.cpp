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
int p1 = 0;
int p2 = 0;
int p3 = 1;
int answer = 0;
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
bool tomark[200001];
void dfsm(int cur){
    if (cur == p2){
        tomark[cur] = true;
    }
    used[cur] = 2;
    for (int x = 0; x < arr[cur].size(); x++){
        if (used[arr[cur][x]] == 1){
            dfsm(arr[cur][x]);
            tomark[cur] = (tomark[cur] || tomark[arr[cur][x]]);
        }
    }
}

void dfs3(int cur, int dist){
    if (dist > fdist && cur != p2 && cur != p1){
        fdist = dist;
        p3 = cur;
    }
    used[cur] = 2;
    for (int x = 0; x < arr[cur].size(); x++){
        if (used[arr[cur][x]] == 1){
            if (tomark[arr[cur][x]]){
                dfs3(arr[cur][x], dist);
            }
            else{
                dfs3(arr[cur][x], dist + 1);
            }
        }
    }

}

int main(){
    cin >> n;
    int one, two;
    for (int x = 0; x < n - 1; x++){
        cin >> one >> two;
        arr[one - 1].push_back(two - 1);
        arr[two - 1].push_back(one - 1);
    }
    for (int x = 0; x < n; x++){
        used[x] = 1;
    }
    dfs(0,0);
    for (int x = 0; x < n; x++){
        used[x] = 1;
    }
    p1 = fpoint;
    fpoint = -1;
    fdist = 0;
    dfs(p1, 0);
    p2 = fpoint;
    //cout << p1 << " " << p2 << "\n";
    for (int x = 0; x < n; x++){
        tomark[x] = false;
        used[x] = 1;
    }
    dfsm(p1);
    for (int x = 0; x < n; x++){
        if (tomark[x]){
            answer++;
        }
    }
    answer -= 1;
    for (int x = 0; x < n; x++){
        used[x] = 1;
    }
    fdist = 0;
    dfs3(p1, 0);
    answer += fdist;
    if (p3 == p2 || p3 == p1){
        for (int x = 0; x < n; x++){
            if (x != p1 && x != p2){
                p3 = x;
                break;
            }
        }
    }
    cout << answer << "\n";
    cout << p1 + 1 << " " << p2 + 1 << " " << p3 + 1 << "\n";



}
