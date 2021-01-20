#include <fstream>
#include <string>
#include <iostream>
#include <bitset>
#include <math.h>
#include <string>
#include <algorithm>
#include<bits/stdc++.h>
#include <vector>
using namespace std;

int n;

/*
b 0
e 1
s 2
i 3
g 4
o 5
m 6
*/

long long vals[8][8];
long long answer = 0;
int main(){
    ifstream in("bgm.in");
    ofstream out("bgm.out");
    in >> n;
    char a;
    long long one;
    for (int x = 0; x < 8; x++){
        for (int y = 0; y < 8; y++){
            vals[x][y] = 0;
        }
    }
    for (int x = 0; x < n; x++){
        in >> a >> one;
        if (a == 'B'){
            vals[0][(one % 7 + 7) % 7] += 1;
        }
        if (a == 'E'){
            vals[1][(one % 7 + 7) % 7] += 1;
        }
        if (a == 'S'){
            vals[2][(one % 7 + 7) % 7] += 1;
        }
        if (a == 'I'){
            vals[3][(one % 7 + 7) % 7] += 1;
        }
        if (a == 'G'){
            vals[4][(one % 7 + 7) % 7] += 1;
        }
        if (a == 'O'){
            vals[5][(one % 7 + 7) % 7] += 1;
        }
        if (a == 'M'){
            vals[6][(one % 7 + 7) % 7] += 1;
        }
    }
    for (long long b = 0; b < 7; b++){
        for (long long e = 0; e < 7; e++){
            for (long long s = 0; s < 7; s++){
                for (long long i = 0; i < 7; i++){
                    for (long long g = 0; g < 7; g++){
                        for (long long o = 0; o < 7; o++){
                            for (long long m = 0; m < 7; m++){
                                long long cur = (b + e + s + s + i + e) * (g + o + e + s) * (m + o + o);
                                //cout << cur << "\n";
                                if (cur % 7 == 0){
                                    answer += (vals[0][b] * vals[1][e] * vals[2][s] * vals[3][i] * vals[4][g] * vals[5][o] * vals[6][m]);
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    out << answer << "\n";

}

