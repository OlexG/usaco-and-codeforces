//created by Oleksandr Gorpynich
#pragma GCC optimize("O2")
#include <fstream>
#include <string>
#include <iostream>
#include <bitset>
#include <math.h>
#include <string>
#include <algorithm>
#include <assert.h>
#include <bits/stdc++.h>
#include <vector>
#include <queue>
#include<stdio.h>
#include<ctype.h>
#define ll long long
using namespace std;

int n, m;

string arr[] = {"abc", "acb", "bca", "bac", "cab", "cba"};
vector<int> cost[6];
int main(){
    cin >> n >> m;
    string s;
    cin >> s;
    int point = 0;
    for (int x = 0; x < s.size(); x++) {
        for (int y = 0; y < 6; y++) {
            int cst = 0;
            if (s[x] != arr[y][point]) {
                cst = 1;
            }
            if (cost[y].size() == 0) {
                cost[y].push_back(cst);
            } else {
                cost[y].push_back(cost[y][cost[y].size() - 1] + cst);
            }
        }
        point += 1;
        point %= 3;
    }
    for (int x = 0; x < m; x++) {
        int one, two;
        cin >> one >> two;
        one -= 2;
        two -= 1;
        int mi = 1e7;
        for (int y = 0; y < 6; y++) {
            if (one == -1) {
                mi = min(cost[y][two], mi);
            } else {
                mi = min(cost[y][two] - cost[y][one], mi);
            }
        }
        cout << mi << "\n";
    }
}
