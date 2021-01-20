#include <fstream>
#include <string>
#include <iostream>
#include <math.h>
#include <algorithm>
#include<bits/stdc++.h>
#include <vector>
#include <set>
using namespace std;

int n, k;
bool csort(pair<int ,int> a, pair<int ,int> b){
    return a.second < b.second;
}
int main(){
    cin >> n >> k;
    vector<pair<int ,int>> m;
    int one, two;
    for (int x = 0; x < n; x++){
        cin >> one >> two;
        m.push_back(make_pair(one, two));
    }
    sort(m.begin(), m.end(), csort);
    multiset<int> endings;
    set<int> avendings;
    int answer = 0;
    //cout << "\n\n";
    for (int x = 0; x < n; x++){
        if (endings.size() == 0){
            endings.insert(m[x].second);
            avendings.insert(m[x].second);
            k--;
            answer++;
            continue;
        }
        auto it = avendings.lower_bound(m[x].first);
        if (it == avendings.begin()){
            it++;
        }
        //cout << *prev(it) << " " << m[x].first << "\n";
        if (*prev(it) <= m[x].first){
            int cur = *prev(it);
            endings.erase(endings.find(cur));
            if (endings.find(cur) == endings.end()){
                avendings.erase(cur);
            }
            endings.insert(m[x].second);
            avendings.insert(m[x].second);
            answer++;
            continue;
        }
        if (k > 0){
            k--;
            endings.insert(m[x].second);
            avendings.insert(m[x].second);
            answer++;
            continue;
        }
    }
    cout << answer << "\n";
}

