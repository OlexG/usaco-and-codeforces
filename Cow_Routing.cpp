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

long long n;
long long s;
long long f;

struct Edge {
    long long finish;
    long long price;
    long long distance;
    bool operator<(const Edge& y) const { return finish < y.finish; }
};
vector<Edge> cons[1001];
pair<long long, long long> ds[1001];
priority_queue<pair<long long,long long>> todo;


set<Edge> fcons[1001];

int main(){
    ifstream in("cowroute.in");
    ofstream out("cowroute.out");
    in >> s >> f >> n;
    for (int x = 0; x < n; x++){
        long long a, b;
        in >> a >> b;
        vector<long long> cur;
        long long temp;
        for (int y = 0; y < b; y++){
            in >> temp;
            cur.push_back(temp - 1);
        }
        for (int y = 0; y < b; y++){
            for (int z = y + 1; z < b; z++){
                long long start = cur[y];
                long long finish = cur[z];
                Edge th = {finish, a, z - y};

                auto it = fcons[start].lower_bound(th);
                if (it == fcons[start].end()){
                    fcons[start].insert(th);
                }
                else{
                    if ((*(it)).finish == finish){
                        if ((*(it)).price > a){
                            fcons[start].erase(it);
                            fcons[start].insert(th);
                        }
                        else if ((*(it)).price == a && (*(it)).distance > th.distance){
                            fcons[start].erase(it);
                            fcons[start].insert(th);
                        }
                    }
                    else{
                        fcons[start].insert(th);
                    }
                }
            }
        }
    }
    for (int x = 0; x < 1001; x++){
        for (auto it:fcons[x]){
            cons[x].push_back(it);
        }
    }
    for (int x = 0; x < 1001; x++){
        ds[x] = make_pair(1000000000000000, 100000000000000);
    }
    ds[s - 1] = make_pair(0,0);
    todo.push({s - 1, 0});
    while(todo.size() > 0){
        pair<long long, long long> cur = todo.top();
        todo.pop();
        for (int x = 0; x < cons[cur.first].size(); x++){
            long long finish = cons[cur.first][x].finish;
            if (ds[finish].first > ds[cur.first].first + cons[cur.first][x].price){
                ds[finish].first = ds[cur.first].first + cons[cur.first][x].price;
                ds[finish].second = ds[cur.first].second + cons[cur.first][x].distance;
                todo.push({cons[cur.first][x].finish, ds[finish].second});
            }
            else if (ds[finish].first == ds[cur.first].first + cons[cur.first][x].price){
                if (ds[finish].second > ds[cur.first].second + cons[cur.first][x].distance){
                    ds[finish].second = ds[cur.first].second + cons[cur.first][x].distance;
                    todo.push({cons[cur.first][x].finish, ds[finish].second});
                    //cout << ds[finish].first << " ";
                }
            }
        }
    }
    if (ds[f - 1].first == 1000000000000000){
        out << "-1 -1\n";
    }
    else{
        out << ds[f - 1].first << " " << ds[f - 1].second << "\n";
    }
}
