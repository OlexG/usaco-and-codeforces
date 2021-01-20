#include <fstream>
#include <string>
#include <iostream>
#include <bitset>
#include <math.h>
#include <algorithm>
#include<bits/stdc++.h>
#include <vector>
using namespace std;

long long n, a, b, c;
int arr[8];
long long answer = 10000000;

void rec(int cur, int cura, int curb, int curc, int curm){
    if (cur == n){
        if (cura != 0 && curb !=  0 && curc != 0){
            answer = min(answer, curm + abs(a - cura) + abs(b - curb) + abs(c - curc));
        }
    }
    else{
        if (cura == 0){
            rec(cur + 1, cura + arr[cur], curb, curc, curm);
        }
        else{
            rec(cur + 1, cura + arr[cur], curb, curc, curm + 10);
        }
        if (curb == 0){
            rec(cur + 1, cura, curb + arr[cur], curc, curm);
        }
        else{
            rec(cur + 1, cura, curb + arr[cur], curc, curm + 10);
        }
        if (curc == 0){
            rec(cur + 1, cura, curb, curc + arr[cur], curm);
        }
        else{
            rec(cur + 1, cura, curb, curc + arr[cur], curm + 10);
        }
        rec(cur + 1, cura, curb, curc, curm);
    }
}
int main(){
    cin >> n >> a >> b >> c;
    for (int x = 0; x < n; x++){
        cin >> arr[x];
    }
    rec(0,0,0,0,0);
    cout << answer << "\n";
}
