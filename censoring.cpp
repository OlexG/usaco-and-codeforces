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
using namespace std;

string a, b;
int enc[26];
int main(){
    ifstream in("censor.in");
    ofstream out("censor.out");
    in >> a >> b;
    for (int x = 0; x < 26; x++){
        enc[x] = 0;
    }
    string ns = "";
    string ans = "";
    for (int x = 0; x < b.size(); x++){
        int ind = b[x] - 'a';
        enc[ind] += 1;
    }
    for (int x = 0; x < a.size(); x++){
        ns += a[x];
        ans += a[x];
        int ind = a[x] - 'a';
        if (enc[ind] == 0){
            ns = "";
        }
        if (ns.size() >= b.size() && ns[ns.size() - b.size()] == b[0] && ns[ns.size() - 1] == b[b.size() - 1]){
            if(ns.substr(ns.size() - b.size(), ns.size()) == b && ns.size() >= b.size()){
                ns.erase(ns.begin() + ns.size() - b.size(), ns.end());
                ans.erase(ans.begin() + ans.size() - b.size(), ans.end());
            }
        }
    }
    out << ans << "\n";
}
