#include <fstream>
#include <string>
#include <iostream>
#include <math.h>
#include <algorithm>
#include<bits/stdc++.h>
#include <vector>
#include <map>
using namespace std;


int n, m, k;
map<long long, int> ct;
vector<pair<long long, long long>> all;
int main(){
    cin >> n >> m >> k;
    cout << n << " " << m << " " << k << "\n";
    int one, two, three;
    for (int x = 0; x < k; x++){
        cin >> one >> two >> three;
        cout << one << " " << two << " " << three << "\n";
        ct[(long long)(one * 1000000) + (long long)two] = three;
        all.push_back(make_pair(one, two));
    }
    bool answer = true;
    int nk = k;
    for (int x = 0; x < k; x++){
        long long below = (all[x].first + 1) * 1000000 + all[x].second;
        long long left =  (all[x].first) * 1000000 + all[x].second + 1;
        long long diag = (all[x].first + 1) * 1000000 + all[x].second + 1;
        long long here = (all[x].first) * 1000000 + all[x].second;
        int ones = 0;
        int zeroes = 0;
        if (ct.count(below) > 0){
            if (ct[below] == 1){
                ones++;
            }
            else{
                zeroes++;
            }
        }
        if (ct.count(left) > 0){
            if (ct[left] == 1){
                ones++;
            }
            else{
                zeroes++;
            }
        }
        if (ct.count(diag) > 0){
            if (ct[diag] == 1){
                ones++;
            }
            else{
                zeroes++;
            }
        }
        if (ct.count(here) > 0){
            if (ct[here] == 1){
                ones++;
            }
            else{
                zeroes++;
            }
        }
        if (ones + zeroes == 4){
            if (ones % 2 == 0 && zeroes % 2 == 0){
                answer = false;
            }
            else{
                nk--;
            }
        }
    }
    if (answer){
        long long nanswer = 8;
        for (int x = 0; x < n + m - nk - 4; x++){
            nanswer = (nanswer * 2) % 1000000000;
        }
        if (nk > n + m - 4){
            for (int x = n + m - 4; x < nk; x++){
                nanswer /= 2;
            }
        }
        cout << nanswer << "\n";
    }
    else{
        cout << "0\n";
    }
}
