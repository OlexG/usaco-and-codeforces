#include <fstream>
#include <string>
#include <iostream>
#include <math.h>
#include <algorithm>
#include <vector>
using namespace std;
int l, n, rf, rb;
bool compare(const pair<int, int>&i, const pair<int, int>&j)
{
    return i.second < j.second;
}
int main(){
    ifstream in("reststops.in");
    ofstream out("reststops.out");
    in >> l >> n >> rf >> rb;
    vector<pair<int ,int>> arr;
    int one, two;
    for (int x = 0; x < n; x ++){
        in >> one >> two;
        arr.push_back(make_pair(one, two));
    }
    sort(arr.rbegin(), arr.rend(), compare);
    long long tone, ttwo;
    long long answer = 0;
    long long prevd = 0;
    for (int x = 0; x < n; x ++){
        if (arr[x].first > prevd){
            tone = rb * (arr[x].first - prevd);
            ttwo = rf * (arr[x].first - prevd);
            prevd = arr[x].first;
            answer = answer + (ttwo - tone) * arr[x].second;
        }
    }
    out << answer << "\n";
}
