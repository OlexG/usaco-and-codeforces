#include <fstream>
#include <string>
#include <iostream>
#include <math.h>
#include <algorithm>
#include<bits/stdc++.h>
#include <vector>
using namespace std;

int t;

int main(){
    cin >> t;
    for (int z = 0; z < t; z++){
        string s, c;
        cin >> s >> c;
        int ind = -1;
        if (s < c){
            cout << s << "\n";
            continue;
        }
        char minarr[s.size()];
        minarr[s.size() - 1] = s[s.size() - 1];
        for (int x = s.size() - 2; x >= 0; x--){
            minarr[x] = min(s[x], minarr[x + 1]);
        }
        for (int x = 0; x < min(s.size(), c.size()); x++){
            if (s[x] > c[x]){
                ind = x;
                break;
            }
            else if (s[x] == c[x] && c[x] > minarr[x]){
                ind = x;
                break;
            }
        }
        if (ind == -1){
            cout << "---\n";
            continue;
        }
        bool found = false;
        for (int x = ind + 1; x < s.size(); x++){
            char temp = s[x];
            s[x] = s[ind];
            s[ind] = temp;
            if (s < c){
                found = true;
                break;
            }
            temp = s[ind];
            s[ind] = s[x];
            s[x] = temp;
        }
        if (found){
            cout << s << "\n";
        }
        else{
            cout << "---\n";
        }
    }
}
