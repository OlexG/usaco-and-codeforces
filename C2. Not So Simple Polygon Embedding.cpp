#include <fstream>
#include <string>
#include <iostream>
#include <math.h>
#include <algorithm>
#include<bits/stdc++.h>
#include <vector>

#define PI 3.14159265
using namespace std;

double n;
int t;
int main(){
    cin >> t;
    for (int z = 0; z < t; z++){
        cin >> n;
        n *= 2;
        double radius = 1;
        double div = 2 * sin(PI/n);
        radius /= div;

        double ktangle = 360/n;
        double crossa = sqrt(radius * radius * 2 - (2 * radius * radius * cos((ktangle * (floor(n/4) + 1) * PI / 180.0))));
        double pa = sqrt(crossa * crossa/2);
        double crossb = sqrt(radius * radius * 2 - (2 * radius * radius * cos((ktangle * floor(n/4) * PI / 180.0))));
        double pb = sqrt(crossb * crossb/2);

        cout << setprecision(20) << pa + pb << "\n";


    }
}

