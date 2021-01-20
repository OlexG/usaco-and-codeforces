#include <fstream>
#include <string>
#include <iostream>
#include <math.h>
#include <algorithm>
#include<bits/stdc++.h>
#include <vector>
using namespace std;
int n;
vector<pair<long long ,long long>> points;
long long smallesty[50005];
long long largesty[50005];
long long smallestyb[50005];
long long largestyb[50005];

long long smallestx[50005];
long long largestx[50005];
long long smallestxb[50005];
long long largestxb[50005];

bool csort(pair<int ,int> a, pair<int ,int> b){
    if (a.first == b.first){
        return a.second < b.second;
    }
    return a.first < b.first;
}
int main(){
    ifstream in("split.in");
    ofstream out("split.out");
    in >> n;
    long long one, two;
    for (int x = 0; x < n; x++){
        in >> one >> two;
        points.push_back(make_pair(one, two));
    }
    sort(points.begin(), points.end(), csort);
    for (int x = 0; x < points.size(); x++){
        if (x == 0){
            smallesty[x] = points[x].second;
            largesty[x] = points[x].second;
        }
        else{
            smallesty[x] = min(smallesty[x - 1], points[x].second);
            largesty[x] = max(largesty[x - 1], points[x].second);
        }
    }
    for (int x = points.size() - 1; x >= 0; x--){
        if (x == points.size() - 1){
            smallestyb[x] = points[x].second;
            largestyb[x] = points[x].second;
        }
        else{
            smallestyb[x] = min(smallestyb[x + 1], points[x].second);
            largestyb[x] = max(largestyb[x + 1], points[x].second);
        }
    }
    for (int x = 0; x < points.size() - 1; x++){
        if (points[x].first == points[x + 1].first){
            smallestyb[x + 1] = smallestyb[x] ;
        }
    }
    for (int x = points.size() - 1; x >= 1; x--){
        if (points[x - 1].first == points[x].first){
            largesty[x - 1] = largesty[x] ;
        }
    }

    long long smallesty_overall = 1000000001;
    long long biggesty_overall = -1;
    for (int x = 0; x < n; x++){
        smallesty_overall = min(smallesty_overall, points[x].second);
        biggesty_overall = max(biggesty_overall, points[x].second);
    }
    long long area = (points[n - 1].first - points[0].first) * (biggesty_overall - smallesty_overall);
    long long bestarea = area;
    for (int x = 1; x < n - 1; x++){
        if (x != n - 2){
            if (points[x].first != points[x + 1].first){
                long long curarea1 = (largesty[x] - smallesty[x]) * (points[x].first - points[0].first);
                long long curarea2 = (largestyb[x + 1] - smallestyb[x + 1]) * (points[n - 1].first - points[x + 1].first);
                //cout << curarea1 << " " << curarea2 << "\n";
                bestarea = min(bestarea, curarea1 + curarea2);
            }
        }
        else{
            if (points[x].first != points[x + 1].first){
                long long curarea1 = (largesty[x] - smallesty[x]) * (points[x].first - points[0].first);
                long long curarea2 = 0;
                //cout << curarea1 << " " << curarea2 << "\n";
                bestarea = min(bestarea, curarea1 + curarea2);
            }
        }
    }


    //flip points
    for (int x = 0; x < n; x++){
        long long temp = points[x].first;
        points[x].first = points[x].second;
        points[x].second = temp;
    }

    sort(points.begin(), points.end(), csort);
    for (int x = 0; x < points.size(); x++){
        if (x == 0){
            smallesty[x] = points[x].second;
            largesty[x] = points[x].second;
        }
        else{
            smallesty[x] = min(smallesty[x - 1], points[x].second);
            largesty[x] = max(largesty[x - 1], points[x].second);
        }
    }
    for (int x = points.size() - 1; x >= 0; x--){
        if (x == points.size() - 1){
            smallestyb[x] = points[x].second;
            largestyb[x] = points[x].second;
        }
        else{
            smallestyb[x] = min(smallestyb[x + 1], points[x].second);
            largestyb[x] = max(largestyb[x + 1], points[x].second);
        }
    }
    for (int x = 0; x < points.size() - 1; x++){
        if (points[x].first == points[x + 1].first){
            smallestyb[x + 1] = smallestyb[x] ;
        }
    }
    for (int x = points.size() - 1; x >= 1; x--){
        if (points[x - 1].first == points[x].first){
            largesty[x - 1] = largesty[x] ;
        }
    }
    for (int x = 1; x < n - 2; x++){
        if (points[x].first != points[x + 1].first){
            long long curarea1 = (largesty[x] - smallesty[x]) * (points[x].first - points[0].first);
            long long curarea2 = (largestyb[x + 1] - smallestyb[x + 1]) * (points[n - 1].first - points[x + 1].first);
            //cout << curarea1 << " " << curarea2 << "\n";
            bestarea = min(bestarea, curarea1 + curarea2);
        }
    }


    out << area - bestarea << "\n";

}
