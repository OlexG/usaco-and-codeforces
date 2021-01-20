#include <fstream>
#include <string>
#include <iostream>
#include <math.h>
#include <algorithm>
#include <cstdlib>
using namespace std;
#include <vector>

int main(){
    ifstream in("sort.in");
    ofstream out("sort.out");
    int n;
    in >> n;
    vector<pair<long long, long long>> arr;
    int first;
    for (int x = 0; x < n; x ++){
        in >> first;
        arr.push_back(make_pair(first, x));
    }
    sort(arr.begin(),arr.end());
    long long answer = 0;
    for (int x = 0; x < n; x ++){
        answer = max(answer, arr[x].second - x);
    }
    out << answer + 1 << "\n";
}
