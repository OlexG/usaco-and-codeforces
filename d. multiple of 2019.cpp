#include <fstream>
#include <string>
#include <iostream>
#include <math.h>
#include <algorithm>
#include<bits/stdc++.h>
#include <vector>
using namespace std;
string s;
int main(){
    cin >> s;
    int n = s.size();
    int pot = 1;
    int prevsuf = 0;
    int suf[n];
    map<int, int> sfx;
    long long answer = 0;
    for (int x = n - 1; x >= 0; x--){
        int digit = s[x] - '0';
        suf[x] = (digit * pot + prevsuf) % 2019;
        pot = (10 * pot) % 2019;
        auto it = sfx.find(suf[x]);
        if (it != sfx.end()){
            answer += it -> second;
            sfx[suf[x]] += 1;
        }
        else{
            sfx.insert(make_pair(suf[x], 1));
        }
        if (suf[x] == 0){
            answer += 1;
        }
        prevsuf = suf[x];
    }
    cout << answer << "\n";
}
