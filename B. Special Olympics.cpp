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
#define ll long long
using namespace std;

double x1, y1, r1, r2;
double x2, y2, r3, r4;

double circles[4][3];
double dist(double x1, double y1, double x2 ,double y2){
    return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
}
int main(){
    cin >> x1 >> y1 >> r1 >> r2;
    cin >> x2 >> y2 >> r3 >> r4;
    circles[0][0] = x1;
    circles[0][1] = y1;
    circles[0][2] = r1;
    circles[1][0] = x1;
    circles[1][1] = y1;
    circles[1][2] = r2;
    circles[2][0] = x2;
    circles[2][1] = y2;
    circles[2][2] = r3;
    circles[3][0] = x2;
    circles[3][1] = y2;
    circles[3][2] = r4;
    int answer = 0;
    for (int x = 0; x < 4; x++){
        bool works = true;
        int cnt1 = 0;
        int cnt2 = 0;
        for (int y = 0; y < 4; y++){
            if (x != y){
                double d = dist(circles[x][0], circles[x][1], circles[y][0], circles[y][1]);
                if (d < circles[x][2] + circles[y][2] && d + circles[x][2] > circles[y][2] && d + circles[y][2] > circles[x][2]){
                    works = false;
                }
                if (d + circles[x][2] <= circles[y][2] && d < circles[x][2] + circles[y][2]){
                    cnt1++;
                }
                if (d + circles[y][2] <= circles[x][2] && d < circles[x][2] + circles[y][2]){
                    cnt2++;
                }
            }
        }
        //cout << x << " " << cnt1 << " " << cnt2 << "\n";
        if (x == 1 && cnt2 == 2 && cnt1 == 1){
            works = false;
        }
        if (x == 0 && cnt2 == 1 && cnt1 == 2){
            works = false;
        }
        if (x == 3 && cnt2 == 2 && cnt1 == 1){
            works = false;
        }
        if (x == 2 && cnt2 == 1 && cnt1 == 2){
            works = false;
        }
        if (x == 0){
            ll d = dist(circles[x][0], circles[x][1], circles[2][0], circles[2][1]);
            ll d2 = dist(circles[x][0], circles[x][1], circles[3][0], circles[3][1]);
            if (d >= circles[x][2] + circles[2][2] && d2 < circles[x][2] + circles[3][2]){
                works = false;
            }
        }
        if (x == 1){
            ll d = dist(circles[x][0], circles[x][1], circles[2][0], circles[2][1]);
            ll d2 = dist(circles[x][0], circles[x][1], circles[3][0], circles[3][1]);
            if (d >= circles[x][2] + circles[2][2] && d2 < circles[x][2] + circles[3][2]){
                works = false;
            }
        }
        if (x == 2){
            ll d = dist(circles[x][0], circles[x][1], circles[0][0], circles[0][1]);
            ll d2 = dist(circles[x][0], circles[x][1], circles[1][0], circles[1][1]);
            if (d >= circles[x][2] + circles[0][2] && d2 < circles[x][2] + circles[1][2]){
                works = false;
            }
        }
        if (x == 3){
            ll d = dist(circles[x][0], circles[x][1], circles[0][0], circles[0][1]);
            ll d2 = dist(circles[x][0], circles[x][1], circles[1][0], circles[1][1]);
            if (d >= circles[x][2] + circles[0][2] && d2 < circles[x][2] + circles[1][2]){
                works = false;
            }
        }
        if (works){
            answer++;
        }
    }
    cout << answer << "\n";

}
