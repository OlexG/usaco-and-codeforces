#include <fstream>
#include <string>
#include <iostream>
#include <math.h>
#include <algorithm>
#include<bits/stdc++.h>
#include <vector>
using namespace std;
/*
can we binary search
can we use sets
is this a dp question
two pointers - max segment
index sums
*/
long long n, l;
long long t = 0;
bool csort(pair<pair<long long, long long>, long long>a, pair<pair<long long, long long>, long long>b){
    return a.first.second < b.first.second;
}
int main(){
    ifstream in("meetings.in");
    ofstream out("meetings.out");
    in >> n;
    in >> l;
    vector<pair<pair<long long, long long>, long long>> arr;
    // weight position velocity
    long long one, two, three;
    for (int x = 0; x < n; x++){
        in >> one >> two >> three;
        arr.push_back(make_pair(make_pair(one, two), three));
    }
    sort(arr.begin(), arr.end(), csort);
    /*for (int x = 0; x < n; x++){
        cout << arr[x].first.first << " " << arr[x].first.second << " " << arr[x].second << "\n";
    }*/
    int numofones = 0;
    int numoftwos = 0;
    vector<pair<long long, long long>> results;
    //time weight
    int lcounter = 0;
    int rcounter  = n - 1;
    for (int x = 0; x < n; x++){
        if (arr[x].second == -1){
            results.push_back(make_pair(arr[x].first.second, arr[lcounter].first.first));
            lcounter++;
        }
    }
    for (int x = n - 1; x >= 0; x--){
        if (arr[x].second == 1){
            results.push_back(make_pair(l-arr[x].first.second, arr[rcounter].first.first));
            rcounter--;
        }
    }

    sort(results.begin(), results.end());
    /*for (int x = 0; x < results.size(); x++){
        cout << results[x].first << " " << results[x].second << "\n";
    }*/
    long long total = 0;
    for (int x = 0; x < n; x++){
        total += arr[x].first.first;
    }
    long long curtotal = 0;
    for (int x = 0; x < results.size(); x++){
        curtotal += results[x].second * 2;
        t = results[x].first;
        if (curtotal >= total){
            break;
        }
    }

    long long answer = 0;
    vector<long long> negs;
    vector<long long> poss;
    for (int x = 0; x < n; x++){
        if (arr[x].second == -1){
            negs.push_back(arr[x].first.second);
        }
        else{
            poss.push_back(arr[x].first.second);
        }
    }
    for (int x = 0; x < poss.size(); x++){
        answer += upper_bound(negs.begin(), negs.end(), poss[x] + 2 * t) - lower_bound(negs.begin(), negs.end(), poss[x]);
    }
    /*for (int x = 0; x < negs.size(); x++){
        answer += upper_bound(poss.begin(), poss.end(), negs[x]) - lower_bound(poss.begin(), poss.end(), negs[x] - t);
    }*/
    out << answer << "\n";


}
