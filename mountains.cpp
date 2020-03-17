#include <fstream>
#include <string>
#include <iostream>
#include <math.h>
#include <algorithm>
#include <vector>
#include <bits/stdc++.h>
using namespace std;
bool compare(const pair<int, int>&i, const pair<int, int>&j)
{
    return i.second < j.second;
}
vector<pair <long long,long long>> points;
int n;
int main() {
    ifstream in("mountains.in");
    ofstream out("mountains.out");
    in >> n;
    long long one, two;
    for (int x = 0; x < n; x++){
        in >> one >> two;
        points.push_back(make_pair(one - two, one + two));
    }
    sort(points.begin(),points.end());
    int answer = 1;
    long long curx = points[0].first;
    long long cury = points[0].second;
    for (int x = 1; x < n; x ++){
        if (points[x].second > cury){
            answer = answer + 1;
            cury = points[x].second;
            curx = points[x].first;
        }
    }
    out << answer << "\n";


}
