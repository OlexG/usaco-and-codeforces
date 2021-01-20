#include <fstream>
#include <string>
#include <iostream>
#include <math.h>
#include <algorithm>
#include<bits/stdc++.h>
#include <vector>
using namespace std;

int n;
set<int> curcards;
int used[100002];
vector<int> bes;
int main(){
    ifstream in("highcard.in");
    ofstream out("highcard.out");
    in >> n;
    int one;
    for (int x = 1; x <= 2 * n; x++){
        used[x] = 2;
    }
    for (int x = 0; x < n; x++){
        in >> one;
        bes.push_back(one);
        used[one] = 1;
    }
    for (int x = 1; x <= 2 * n; x++){
        if (used[x] == 2){
            curcards.insert(x);
        }
    }
    long long answer = 0;
    for (int x = 0; x < n; x++){
        auto it = curcards.lower_bound(bes[x]);
        if (it != curcards.end()){
            answer++;
            curcards.erase(it);
        }
    }
    out << answer << "\n";
}
