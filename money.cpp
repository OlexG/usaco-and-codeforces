/*
ID: alex.go2
LANG: C++11
PROB: money
*/
#include <fstream>
#include <string>
#include <iostream>
#include <math.h>
#include <algorithm>
#include<bits/stdc++.h>
#include <vector>
using namespace std;
long long v, n;
vector<long long> coins;
long long amount[10001][26];
vector<int> incl[10001];

/*
3 10
1 2 5
*/
int main(){
    ifstream in("money.in");
    ofstream out("money.out");
    in >> v >> n;
    long long one;
    for (int x = 0; x < v; x++){
        in >> one;
        coins.push_back(one);
    }
    sort(coins.begin(), coins.end());
    for (int x = 0; x <= n; x++){
        for (int y = 0; y <= v; y++){
            amount[x][y] = 0;
        }
    }
    for (int x = 0; x <= v; x++){
        amount[0][x] = 1;
    }

    for (int x = 1; x <= n; x++){
        for (int y = 0; y < coins.size(); y++){
            if (x - coins[y] >= 0){
                amount[x][y + 1] += amount[x - coins[y]][y + 1];
            }
        }
        for (int y = 1; y <= coins.size(); y++){
            amount[x][y] += amount[x][y - 1];
        }
    }
    long long answer = 0;
    out << amount[n][v] << "\n";
}
