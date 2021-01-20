/*
ID: alex.go2
LANG: C++11
PROB: zerosum
*/
#include <fstream>
#include <string>
#include <iostream>
#include <math.h>
#include <algorithm>
#include<bits/stdc++.h>
#include <vector>
using namespace std;

int n;

char op[9];
vector<string> s;
void csearch(int cur){
    if (cur >= n - 1){
        char co = '+';
        int cur = 0;
        long long curelem = 1;
        long long sum = 0;

        for (int x = 0; x < n - 1; x++){
            if (op[x] == ' '){
                curelem *= 10;
                curelem += (x + 2);
            }
            else{
                if (co == '+'){
                    sum += curelem;
                }
                else{
                    sum -= curelem;
                }
                co = op[x];
                curelem = x + 2;
            }
        }
        if (co == '+'){
            sum += curelem;
        }
        else{
            sum -= curelem;
        }
        if (sum == 0){
            string curstring = "";
            curstring += '1';
            for (int x = 0; x < n - 1; x++){
                curstring += op[x];
                char n = ((x + 2) + '0');
                curstring += n;
            }
            s.push_back(curstring);
        }

    }
    else{
        op[cur] = '+';
        csearch(cur + 1);
        op[cur] = '-';
        csearch(cur + 1);
        op[cur] = ' ';
        csearch(cur + 1);
    }
}
int main(){
    ifstream in("zerosum.in");
    ofstream out("zerosum.out");
    in >> n;
    csearch(0);
    sort(s.begin(), s.end());
    for (int x = 0; x < s.size(); x++){
        out << s[x] << "\n";
    }
}
