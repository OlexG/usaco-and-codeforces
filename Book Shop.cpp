#include <fstream>
#include <string>
#include <iostream>
#include <math.h>
#include <algorithm>
#include<bits/stdc++.h>
#include <vector>
using namespace std;

int n, m;

int main(){
    cin >> n >> m;
    int a[n];
    int b[n];
    for (int x = 0; x < n; x++){
        cin >> a[x];
    }
    for (int x = 0; x < n; x++){
        cin >> b[x];
    }
    int p[m + 1][n + 2];
    for (int x = 0; x <= m; x++){
        for (int y = 0; y <= n; y++){
            p[x][y] = 0;
        }
    }
    for (int y = 0; y < n; y++){
        for (int x = 1; x <= m; x++){
            if (x - a[y] >= 0){
                p[x][y + 1] = max(p[x][y + 1], p[x - a[y]][y] + b[y]);
            }
            p[x][y + 1] = max(p[x][y + 1], p[x - 1][y + 1]);
            p[x][y + 1] = max(p[x][y + 1], p[x][y]);
        }
    }
    cout << p[m][n] << "\n";
}
