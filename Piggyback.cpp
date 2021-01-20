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

long long b, e, p ,n,m;
vector<long long> cons[40001];
long long disttoone[40001];
long long disttotwo[40001];
long long distton[40001];
long long used[40001];


int main(){
    ifstream in("piggyback.in");
    ofstream out("piggyback.out");
    in >> b >> e >> p >> n >> m;
    long long one, two;
    for (int x = 0; x < m; x++){
        in >> one >> two;
        cons[one - 1].push_back(two - 1);
        cons[two - 1].push_back(one - 1);
    }
    //for one;
    for (int x = 0; x < n; x++){
        used[x] = 2;
        disttoone[x] = 100000000000000;
        disttotwo[x] = 100000000000000;
        distton[x] = 10000000000000;
    }
    queue<pair<long long, long long>> q;
    disttoone[0] = 0;
    q.push({0,0});
    while(q.empty() == false){
        pair<long long, long long> cur = q.front();
        used[cur.first] = 1;
        for (int x = 0; x < cons[cur.first].size(); x++){
            if (used[cons[cur.first][x]] == 2){
                disttoone[cons[cur.first][x]] = cur.second + 1;
                used[cons[cur.first][x]] = 1;
                q.push({cons[cur.first][x], cur.second + 1});
            }
        }
        q.pop();
    }
    //for two;
    for (int x = 0; x < n; x++){
        used[x] = 2;
    }
    disttotwo[1] = 0;
    q.push({1,0});
    while(q.empty() == false){
        pair<long long, long long> cur = q.front();
        used[cur.first] = 1;
        for (int x = 0; x < cons[cur.first].size(); x++){
            if (used[cons[cur.first][x]] == 2){
                disttotwo[cons[cur.first][x]] = cur.second + 1;
                used[cons[cur.first][x]] = 1;
                q.push({cons[cur.first][x], cur.second + 1});
            }
        }
        q.pop();
    }
    //for n
    for (int x = 0; x < n; x++){
        used[x] = 2;
    }
    distton[n - 1] = 0;
    q.push({n - 1,0});
    while(q.empty() == false){
        pair<long long, long long> cur = q.front();
        used[cur.first] = 1;
        for (int x = 0; x < cons[cur.first].size(); x++){
            if (used[cons[cur.first][x]] == 2){
                distton[cons[cur.first][x]] = cur.second + 1;
                used[cons[cur.first][x]] = 1;
                q.push({cons[cur.first][x], cur.second + 1});
            }
        }
        q.pop();
    }
    long long answer = 1000000000000000;
    for (int x = 0; x < n; x++){
        answer = min(answer, disttoone[x] * b + disttotwo[x] * e + distton[x] * p);
    }
    out << answer << "\n";

}
