#pragma GCC optimize("O2")
#include <fstream>
#include <string>
#include <iostream>
#include <bitset>
#include <math.h>
#include <string>
#include <algorithm>
#include <assert.h>
#include<bits/stdc++.h>
#include <vector>
#include <queue>
#include<stdio.h>
#include<ctype.h>
#define ll long long
using namespace std;


int n, m;

vector<int> cons[2501];
int dist[2501];

int main(){
    cin >> n >> m;
    int one, two;
    for (int x = 0; x < m; x++){
        cin >> one >> two;
        cons[one - 1].push_back(two - 1);
        cons[two - 1].push_back(one - 1);
    }
    int answer = -1;
    for (int x = 0; x < n; x++){
        for (int y = 0; y < cons[x].size(); y++){
            for (int z = 0; z < n; z++){
                dist[z] = -1;
            }
            queue<int> q;
            q.push(cons[x][y]);
            dist[cons[x][y]] = 1;
            while(q.size() > 0){
                int cur = q.front();
                q.pop();
                for (int z = 0; z < cons[cur].size(); z++){
                    if (cons[cur][z] != x && dist[cons[cur][z]] == -1){
                        dist[cons[cur][z]] = dist[cur] + 1;
                        q.push(cons[cur][z]);
                    }
                }
            }
            for (int z = 0; z < cons[x].size(); z++){
                if (z != y && dist[cons[x][z]] != -1){
                    answer = min(answer, dist[cons[x][z]] + 1);
                    if (answer == -1){
                        answer = dist[cons[x][z]] + 1;
                    }
                }
            }
        }
    }
    cout << answer << "\n";
}
