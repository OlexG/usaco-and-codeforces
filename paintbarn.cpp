#include <fstream>
#include <string>
#include <iostream>
#include <math.h>
#include <algorithm>
using namespace std;
/*
3 2
1 1 5 5
4 4 7 6
3 3 8 7*/
int plane[1001][1001];

int main(){
    ifstream in("paintbarn.in");
    ofstream out("paintbarn.out");
    int n;
    int k;
    in >> n;
    in >> k;
    int a,b,c,d;
    for (int x = 0; x < 1001; x++){
         for (int y = 0; y < 1001; y++){
            plane[x][y] = 0;
         }
    }

    for (int x = 0; x < n; x ++){
        in >> a >> b >> c >> d;
        for (int i = a; i < c; i++){
            plane[i][b]++;
            plane[i][d]--;
        }
    }

    int curr = 0;
    int answer = 0;
    for (int x = 0; x < 1001; x++){
         for (int y = 0; y < 1001; y++){
            curr = curr + plane[x][y];
            if (curr == k){
                answer ++;
            }
         }
    }
    out << answer << "\n";
}
