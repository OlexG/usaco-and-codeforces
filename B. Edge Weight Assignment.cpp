#pragma GCC optimize("O2")
#include <fstream>
#include <string>
#include <iostream>
#include <bitset>
#include <math.h>
#include <string>
#include <algorithm>
#include<bits/stdc++.h>
#include <vector>
#include <queue>
using namespace std;

int n;
vector<int> cons[100001];
int odd[100001];
int even[100001];
int used[100001];
bool works = true;
void dfs(int cur){
    used[cur] = 1;
    for (int x = 0; x < cons[cur].size(); x++){
        if (used[cons[cur][x]] == 2){
            dfs(cons[cur][x]);
            even[cur] += odd[cons[cur][x]];
            odd[cur] += even[cons[cur][x]];
        }
    }
    if (cons[cur].size() == 1){
        even[cur] = 1;
        odd[cur] = 0;
    }
    //cout << cur << " " << even[cur] << " " << odd[cur] << "\n";
    if (!(even[cur] == 0 || odd[cur] == 0)){
        works = false;
    }
}
int main(){
    cin >> n;
    int one, two;
    for (int x = 0; x < n - 1; x++){
        cin >> one >> two;
        cons[two - 1].push_back(one - 1);
        cons[one - 1].push_back(two - 1);
    }
    int m = n - 1;

    for (int x = 0; x < n; x++){
        used[x] = 2;
    }
    for (int x = 0; x < n; x++){
        if (used[x] == 2 && cons[x].size() == 1){
            int valid = 0;
            int parent = cons[x][0];
            used[parent] = 1;
            int counter = cons[parent].size();
            for (int z = 0; z < cons[parent].size(); z++){
                if (cons[cons[parent][z]].size() == 1){
                    valid++;
                    used[cons[parent][z]] = 1;
                }
            }
            m -= (valid - 1);
        }
    }
    if (n == 3){
        m = 1;
    }
    for (int x = 0; x < n; x++){
        even[x] = 0;
        odd[x] = 0;
        used[x] = 2;
    }
    for (int x = 0; x < n; x++){
        if (cons[x].size() >= 2){
            dfs(x);
            break;
        }
    }
    cout << (works?1:3) << " " << m << "\n";

}
