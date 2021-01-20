#include <fstream>
#include <string>
#include <iostream>
#include <math.h>
#include <algorithm>
#include<bits/stdc++.h>
#include <vector>
using namespace std;

int n;
int ocounter[2500];
int counter[2500];
int used[2500];
vector<int> c[2500];

void dfs(int cur, int prev){
    counter[cur]++;
    used[cur] = 2;
    /*cout << cur << " " << counter[cur] << "\n";
    if (prev != -1){
        cout << prev << " " << counter[prev] << " this is the previous\n";
    }*/
    for (int x = 0; x < c[cur].size(); x++){
        if (used[c[cur][x]] == 1){
            dfs(c[cur][x], cur);
        }
    }
    if (prev != -1){
        int add = 12 - counter[cur];
        counter[cur] += add;
        counter[prev] += (add + 1);
        if (counter[prev] > 12){
            counter[prev] = 1 + counter[prev] - 13;
        }
    }

}
int main(){
    ifstream in("clocktree.in");
    ofstream out("clocktree.out");
    in >> n;
    for (int x = 0; x < n; x++){
        in >> ocounter[x];
        counter[x] = ocounter[x];
        used[x] = 1;
    }
    int one, two;
    for (int x = 0; x < n - 1; x++){
        in >> one >> two;
        c[one - 1].push_back(two - 1);
        c[two - 1].push_back(one - 1);
    }
    int answer = 0;
    for (int x = 0; x < n; x++){
        for (int y = 0; y < n; y++){
            counter[y] = ocounter[y];
            used[y] = 1;
        }
        counter[x] -= 1;
        dfs(x, -1);
        /*for (int x = 0; x < n; x++){
            cout << counter[x] << " ";
        }
        cout << "\n";*/
        if (counter[x] == 12 || counter[x] == 1){
            answer += 1;
        }
    }
    out << answer << "\n";

}
