#include <fstream>
#include <string>
#include <iostream>
#include <math.h>
#include <algorithm>
#include<bits/stdc++.h>
#include <vector>
using namespace std;

int a[1000001];
int b[1000001];
int m[1000001];
int mindex[1000001];
int r, n;
int main(){
    cin >> r >> n;
    for (int x = 0; x < 1000001; x++){
        a[x] = -1;
        b[x] = -1;
        m[x] = -1000000;
    }
    int one, two, three;
    for(int x = 0; x < n; x++){
        cin >> one >> two >> three;
        a[one] = two;
        b[one] = three;
    }
    a[0] = 1;
    b[0] = 1;
    m[0] = 0;
    mindex[0] = 0;
    for (int x = 1; x < 1000001; x++){
        int curmax = -1000000;
        if (a[x] != -1){
            for (int y = x - 2 * r; y <= x - 1; y++){
                if (y >= 0){
                    if (a[y] != -1){
                        if (abs(a[x] - a[y]) + abs(b[x] - b[y]) <= x - y){
                            curmax = max(curmax, m[y] + 1);
                        }
                    }
                }
            }
            if (x - 2 * r >= 0){
                curmax = max(curmax, mindex[x - 2*r] + 1);
            }
        }
        if (x - 2*r >= 0){
            mindex[x - 2*r + 1] = max(mindex[x - 2*r], m[x - 2*r + 1]);
        }
        m[x] = curmax;
    }
    int answer = 0;
    for (int x = 0; x < 1000001; x++){
        answer = max(answer, m[x]);
    }
    cout << answer << "\n";


}
