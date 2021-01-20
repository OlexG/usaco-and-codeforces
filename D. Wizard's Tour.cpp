#include <fstream>
#include <string>
#include <iostream>
#include <math.h>
#include <algorithm>
#include<bits/stdc++.h>
#include <vector>
using namespace std;
#define FOR(i,a,b) for (int i = (a); i < (b); ++i)

int n, m;
set<int> cons[200000];
int used[200000];
vector<int> order;
void topsort(int cur){
    used[cur] = 2;
    for (auto it: cons[cur]){
        if (used[it] == 1){
            topsort(it);
        }
    }
    order.push_back(cur);
}
int main(){
    cin >> n >> m;
    int one, two;
    FOR(x, 0, n){
        used[x] = 1;
    }
    FOR(x, 0, m){
        cin >> one >> two;
        cons[one - 1].insert(two - 1);
        cons[two - 1].insert(one - 1);
    }

    FOR(x, 0, n){
        if (used[x] == 1){
            topsort(x);
        }
    }
    int answer = 0;
    vector<int> a, b, c;
    for (int x = 0; x < n; x++){
        int cur = order[x];
        vector<pair<int, int>> curcons;
        if (cons[cur].size() >= 2){
            for (auto it: cons[cur]){
                curcons.push_back(make_pair(cons[it].size(), it));
            }
        }
        sort(curcons.begin(), curcons.end());
        for (int x = 0; x < curcons.size(); x += 2){
            if (x + 1 < curcons.size()){
                a.push_back(curcons[x].second + 1);
                b.push_back(cur + 1);
                c.push_back(curcons[x + 1].second + 1);
                answer += 1;
                cons[cur].erase(curcons[x + 1].second);
                cons[cur].erase(curcons[x].second);
                cons[curcons[x + 1].second].erase(cur);
                cons[curcons[x].second].erase(cur);

            }
        }
    }
    cout << answer << "\n";
    FOR(x, 0, answer){
        cout << a[x] << " " << b[x] << " " << c[x] << "\n";
    }

}
