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

//long long MAXN = 200001;
vector<long long> cons[200001];
long long cycle[200001];
long long visited[200001];

long long scycle = 0;

long long n;
long long t;

void dfscf(long long cur, long long par){
    visited[cur] = 1;
    for (int x = 0; x < cons[cur].size(); x++){
        if (visited[cons[cur][x]] == 2){
            dfscf(cons[cur][x], cur);
        }
        else{
            if (cons[cur][x] != par){
                scycle = cons[cur][x];
            }
        }
    }
}

void dfsc(long long cur, long long par){
    visited[cur] = 1;
    for (int x = 0; x < cons[cur].size(); x++){
        if (visited[cons[cur][x]] == 2){
            dfsc(cons[cur][x], cur);
        }
        else{
            if (cons[cur][x] != par){
                cycle[cons[cur][x]] = 2;
            }
        }
        if (cycle[cons[cur][x]] == 2 && cons[cur][x] != par){
            cycle[cur] = 2;
        }
    }
}

long long total = 0;

void dfs(long long cur){
    total += 1;
    visited[cur] = 1;
    for (int x = 0; x < cons[cur].size(); x++){
        if (visited[cons[cur][x]] == 2){
            if ((cycle[cur] == 2 && cycle[cons[cur][x]] != 2) || (cycle[cur] != 2)){
                dfs(cons[cur][x]);
            }
        }
    }
}
int main() {
    cin >> t;
    for (int z = 0; z < t; z++){
        long long one, two;
        cin >> n;
        for (int x = 0; x < n; x++){
            cons[x].clear();
        }
        for (int x = 0; x < n; x++){
            cin >> one >> two;
            cons[one - 1].push_back(two - 1);
            cons[two - 1].push_back(one - 1);
            visited[x] = 2;
            cycle[x] = 0;
        }
        dfscf(0, -1);
        for (int x = 0; x < n; x++){
            visited[x] = 2;
        }
        dfsc(scycle, -1);
        long long cyclesize = 0;
        for (int x = 0; x < n; x++){
            visited[x] = 2;
            cyclesize += (cycle[x] == 2);
        }

        long long answer1 = 0;
        long long answer2 = 0;
        long long answer3 = 0;
        long long answer4 = 0;
        for (int x = 0; x < n; x++){
            if (visited[x] == 2 && cycle[x] != 2){
                total = 0;
                dfs(x);
                //cout << total << " " << cyclesize << "\n";
                answer1 += (total * (total-1))/2;
                answer2 += ((cyclesize - 1) * (total - 1) * 2);
                answer3 += ((n - total - cyclesize + 1) * 2 * (total - 1));
            }
        }
        answer3 /= 2;
        answer4 += ((cyclesize - 1) * cyclesize);
        cout << answer1 + answer2 + answer3 + answer4 << "\n";
    }
}
