#include <fstream>
#include <string>
#include <iostream>
#include <math.h>
#include <algorithm>
#include<bits/stdc++.h>
#include <vector>
using namespace std;
long long n, d, m;
int main(){
    cin >> n >> d >> m;
    vector<long long> bad;
    vector<long long> good;
    long long temp;
    for (int x  = 0; x < n; x++){
        cin >> temp;
        if (temp > m){
            bad.push_back(temp);
        }
        else{
            good.push_back(temp);
        }
    }
    vector<long long> badindex;
    vector<long long> goodindex;
    sort(bad.rbegin(), bad.rend());
    sort(good.rbegin(), good.rend());
    if (bad.size() > 0){
        badindex.push_back(bad[0]);
    }
    if (good.size() > 0){
        goodindex.push_back(good[0]);
    }
    for (int x = 1; x < bad.size(); x++){
        badindex.push_back(badindex[x - 1] + bad[x]);
        //cout << badindex[x] << " ";
    }
    for (int x = 1; x < good.size(); x++){
        goodindex.push_back(goodindex[x - 1] + good[x]);
        //cout << goodindex[x] << " ";
    }
    long long answer = 0;
    if (good.size() > 0){
        answer += goodindex[good.size() - 1];
    }
    if (badindex.size() > 0){
        answer += badindex[0];
    }
    for (int x = 0; x < bad.size(); x++){
        long long numtaken = ((x) * (d + 1)) + 1;
        long long remaining = n - numtaken;
        if (good.size() > 0){
            if (remaining - 1 < good.size() && remaining - 1 >= 0){
                answer = max(answer, goodindex[remaining - 1] + badindex[x]);
            }
            else if (remaining - 1 >= good.size()){
                answer = max(answer, goodindex[good.size() - 1] + badindex[x]);
            }
        }
        else if (remaining > 0){
            answer = max(answer, badindex[x]);
        }
        if (remaining == 0){
            answer = max(answer, badindex[x]);
        }
    }
    cout << answer << "\n";
}
