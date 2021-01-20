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


int n,k;
int bestk[501][501];
int disttoone[501];
pair<int, int> points[501];

int main(){
    ifstream in("marathon.in");
    ofstream out("marathon.out");
    in >> n >> k;
    int one, two;
    for (int x = 0; x < n; x++){
        in >> one >> two;
        points[x] = make_pair(one, two);
    }
    for (int x = 0; x < 501; x++){
        for (int y = 0; y < 501; y++){
            bestk[x][y] = 10000000;
        }
    }
    disttoone[0] = 0;
    for (int x = 1; x < n; x++){
        disttoone[x] = disttoone[x - 1] + abs(points[x].first - points[x - 1].first) + abs(points[x].second - points[x - 1].second);
    }
    for (int x = 0; x <= k; x++){
        bestk[0][x] = 0;
    }
    for (int x = 1; x < n; x++){
        for (int y = 0; y <= k; y++){
            for (int z = 0; z < x; z++){
                int dist = disttoone[x] - disttoone[z];
                bestk[x][y] = min(bestk[x][y], bestk[z][y] + dist);
            }
        }
        //cout << bestk[x][0] << "\n";
        for (int z = 0; z <= min(x - 1, k); z++){
            int prev = x - z - 1;
            int dist = abs(points[x].first - points[prev].first) + abs(points[x].second - points[prev].second);
            for (int y = 0; y <= k - z; y++){
                bestk[x][z + y] = min(bestk[x][z + y], dist + bestk[prev][y]);
            }
        }


    }
    out << bestk[n - 1][k] << "\n";
}
