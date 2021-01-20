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

int t;
double X1,Y1,U1,V1,X2,Y2,U2,V2;
const double PI  =3.141592653589793238463;

double angleDist(double angle1, double angle2){
    return min((360) - abs(angle1 - angle2), abs(angle1 - angle2));
}
int main(){
    cin >> t;
    for (int z = 0; z < t; z++){
        cin >> X1 >> Y1 >> U1 >> V1 >> X2 >> Y2 >> U2 >> V2;
        double rot1 = atan2(Y1 - V1, X1 - U1) * 180/ PI;
        double rot2 = atan2(Y2 - V2, X2 - U2) * 180/ PI;
        if (rot1 < 0){
            rot1 += 360;
        }
        if (rot2 < 0){
            rot2 += 360;
        }
        double frot1 = atan2(Y1 - Y2, X1 - X2) * 180/ PI;
        double frot2 = atan2(Y2 - Y1, X2 - X1) * 180/ PI;
        if (frot1 < 0){
            frot1 += 360;
        }
        if (frot2 < 0){
            frot2 += 360;
        }
        //cout << rot1 << " " << rot2 << " " << frot1 << " " << frot2 << "\n";
        double d1 = angleDist(rot1, frot1);
        double d2 = angleDist(rot2, frot2);
        //cout << d1 << " " << d2 << "\n";
        if (d2 - d1 > 0.0000000000001){
            //cout << d1 - d2 << "\n";
            cout << "Hero\n";
        }
        else if (d1 - d2 > 0.0000000000001){
            //cout << d1 - d2 << "\n";
            cout << "Heroine\n";
        }
        else{
            cout << "0\n";
        }
    }
}
