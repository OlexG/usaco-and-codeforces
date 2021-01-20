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

string arr[323];


int main(){
    ifstream in("in.txt");
    for (int x = 0; x < 323; x++){
        in >> arr[x];
    }

    int dx[5] = {1,1,1,1,2};
    int dy[5] = {1,3,5,7,1};
    long long answer = 1;
    for (int z = 0; z < 5; z++){
        long long counter = 0;
        int sx = 0;
        int sy = 0;
        while(sx < 323){
            if (arr[sx][sy] == '#'){
                counter++;
            }
            sx += dx[z];
            sy += dy[z];
            sy %= arr[0].size();
        }
        answer *= counter;
    }
    cout << answer << "\n";
}
