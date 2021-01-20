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
#include <queue>
using namespace std;

int main(){
    ifstream in("in.txt");
    ofstream out("output.txt");
    string needed[7] = {"byr:","iyr:","eyr:","hgt:","hcl:","ecl:","pid:"};
    string curline;
    string cur = "";
    int answer = 0;
    for (int x = 0; x < 1168; x++){
        getline(in, curline);
        if (curline.size() > 0){
            cur += curline + " ";
        }
        else{
            bool works = true;
            for (int z = 0; z < 7; z++){
                if(cur.find(needed[z]) == string::npos){
                    works = false;
                }
            }
            if (works){
                out << cur << "\n";
                answer += 1;
            }
            cur = "";

        }
        if (x == 1167){
            bool works = true;
            for (int z = 0; z < 7; z++){
                if(cur.find(needed[z]) == string::npos){
                    works = false;
                }
            }
            out << cur << "\n";
            cur = "";
            if (works){
                answer += 1;
            }
        }
    }
    cout << answer << "\n";
}
