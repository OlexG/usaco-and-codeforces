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
#include <assert.h>
#include <queue>
#include<stdio.h>
#include<ctype.h>
#define ll long long
using namespace std;

int n;
vector<pair<long double, long double>> points;

long double calcSlope(pair<long double, long double> a, pair<long double, long double> b){
    long double slope = ((a.first == b.first)?-10000000000.0:((a.second - b.second)/(a.first - b.first)));
    return slope;
}
long double points3(int index){
    map<long double, int> mp;
    for (int x = 0; x < points.size(); x++){
        if (x != index){
            long double slope = calcSlope(points[index], points[x]);
            /*if (points[0].first == 138063){
                cout << slope << "\n";
            }*/
            if (mp.find(slope) == mp.end()){
                mp[slope] = 1;
            }
            else{
                mp[slope] += 1;
                if (mp[slope] >= 2){
                    return slope;

                }
            }
        }
    }
    return -2000000000.0;
}
int main(){
    cin >> n;
    if (n == 1 || n == 2 || n == 3 || n == 4){
        cout << "YES\n";
        return 0;
    }
    ll one, two;
    for (int x = 0; x < n; x++){
        cin >> one >> two;
        points.push_back(make_pair(one, two));
    }
    bool ftry = true;
    long double slope = calcSlope(points[0], points[1]);
    for (int x = 2; x < n; x++){
        long double cslope = calcSlope(points[0], points[x]);
        if (cslope != slope){
            ftry = false;
        }
    }
    if (ftry){
        cout << "YES\n";
        return 0;
    }
    bool works = false;
    long double lslope;
    int ind = -3;
    for (int x = 0; x < 3; x++){
        lslope = points3(x);
        if (lslope != -2000000000){
            ind = x;
            break;
        }
    }
    if (ind == -3){
        cout << "NO\n";
        return 0;
    }
    vector<pair<long double, long double>> npoints;
    for (int x = 0; x < n; x++){
        if (x != ind){
            long double cslope = calcSlope(points[ind], points[x]);
            if (cslope != lslope){
                npoints.push_back(points[x]);
            }
        }
    }
    if (npoints.size() == 0 || npoints.size() == 1 || npoints.size() == 2){
        cout << "YES\n";
        return 0;
    }
    for (int x = 1; x < npoints.size(); x++){
        if (calcSlope(npoints[0], npoints[x]) != calcSlope(npoints[0], npoints[1])){
            cout << "NO\n";
            return 0;
        }
    }
    cout << "YES\n";

}
