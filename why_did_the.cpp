/*
5 4
7
8
6
2
9
2 5
4 9
0 3
8 13
*/
#include <fstream>
#include <string>
#include <iostream>
#include <math.h>
#include <algorithm>
#include<bits/stdc++.h>
#include <vector>
using namespace std;
int c, n;

bool csort(pair<int, int> a, pair<int, int> b){
    if (a.second == b.second){
        return a.first < b.first;
    }
    return a.second < b.second;
}
int main(){
    ifstream in("helpcross.in");
    ofstream out("helpcross.out");
    in >> c >> n;
    vector<int> chicken;
    int temp;
    for (int x = 0; x < c; x++){
        in >> temp;
        chicken.push_back(temp);
    }
    int one, two;
    vector<pair<int, int>> ranges;
    for (int x = 0; x < n; x++){
        in >> one >> two;
        ranges.push_back(make_pair(one, two));
    }
    int pointer1 = 0;
    int pointer2 = 0;
    int answer = 0;
    sort(ranges.begin(), ranges.end(), csort);
    multiset<int> chicks;
    for (int x = 0; x < c; x++){
        chicks.insert(chicken[x]);
    }
    while(pointer2 < n){
        if (chicks.lower_bound(ranges[pointer2].first) != chicks.end()){
            if (*chicks.lower_bound(ranges[pointer2].first) <= ranges[pointer2].second){
                chicks.erase(chicks.find(*chicks.lower_bound(ranges[pointer2].first)));
                answer++;
            }
        }
        pointer2++;
    }
    out << answer << "\n";
}
