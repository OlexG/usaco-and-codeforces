/*
ID: alex.go2
LANG: C++11
PROB: concom
*/
#include <fstream>
#include <string>
#include <iostream>
#include <math.h>
#include <algorithm>
#include<bits/stdc++.h>
#include <vector>
using namespace std;

vector<pair<int, int>> answers;
vector<pair<int,int>> cons[101];
int n;
int used[101];
int amount[101];

bool csort(pair<int ,int> a, pair<int ,int> b){
    if (a.first == b.first){
        return a.second <= b.second;
    }
    else{
        return a.first <= b.first;
    }
}
int main(){
    ifstream in("concom.in");
    ofstream out("concom.out");
    in >> n;
    int a, b, c;
    for (int x = 0; x <  n; x++){
        in >> a >> b >> c;
        cons[a - 1].push_back(make_pair(b - 1, c));
    }
    for (int x = 0; x <= 100; x++){
        for (int y = 0; y <= 100; y++){
            amount[y] = 0;
            used[y] = 2;
        }
        queue<int> q;
        q.push(x);
        while(q.empty() == false){
            int cur = q.front();
            used[cur] = 1;
            for (int z = 0; z < cons[cur].size(); z++){
                amount[cons[cur][z].first] += cons[cur][z].second;
                if (amount[cons[cur][z].first] >= 50 && used[cons[cur][z].first] == 2){
                    q.push(cons[cur][z].first);
                }
            }
            q.pop();
        }
        for (int y = 0; y <= 100; y++){
            if (amount[y] >= 50 && y != x){
                answers.push_back(make_pair(x + 1, y + 1));
            }
        }
    }
    sort(answers.begin(), answers.end(), csort);
    for (int x = 0; x < answers.size(); x++){
        out << answers[x].first << " " << answers[x].second << "\n";
    }

}
