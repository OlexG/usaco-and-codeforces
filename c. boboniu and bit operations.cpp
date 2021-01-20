#include <fstream>
#include <string>
#include <iostream>
#include <math.h>
#include <algorithm>
#include<bits/stdc++.h>
#include <vector>
using namespace std;

int n, m;
int a[201];
int b[201];

int main(){
    cin >> n >> m;
    for (int x = 0; x < n; x++){
        cin >> a[x];
    }
    for (int x = 0; x < m; x++){
        cin >> b[x];
    }
    for (int x = 0; x < 512; x++){
        bool af = true;
        int cur = 0;
        for (int z = 0; z < n; z++){
            bool f = true;
            for (int y = 0; y < m; y++){
                if (((a[z] & b[y]) | x) == x){
                    if (cur | (a[z] & b[y]) > cur){
                        cur = cur | (a[z] & b[y]);
                    }
                    f = false;
                }
            }
            if (f){
                af = false;
            }
        }
        if (af){
            if (cur == x){
                cout << x << "\n";
                break;
            }
        }
    }

}
