#pragma GCC optimize("O2")
#include <fstream>
#include <string>
#include <iostream>
#include <bitset>
#include <math.h>
#include <string>
#include <algorithm>
#include <assert.h>
#include<bits/stdc++.h>
#include <vector>
#include <queue>
#include<stdio.h>
#include<ctype.h>
#define ll long long
using namespace std;

int p1 = 1;
int p2;
string s;
int answers[1000];
int main(){
    cin >> s;
    for (int x = 0; x < s.size(); x++){
        answers[x] = 0;
    }

    while(true){
        bool once = false;
        int np = -1;
        int sp = -1;
        for (int x = p1; x < s.size(); x++){
            if (s[0] == 'b' && s[x] == 'a' && (x == s.size() - 1 || s[x + 1] == 'b')){
                np = x + 1;
                answers[x] = 1;
                once = true;
                break;
            }
            if (s[0] == 'a' && s[x] == 'a' && (x == s.size() - 1 || s[x + 1] == 'b')){
                np = x + 1;
                if (sp == -1){
                    sp = x - 1;
                    answers[x - 1] = 1;
                    answers[x] = 1;
                }
                else{
                    answers[x] = 1;
                    answers[sp] = 1;
                }
                break;
            }
            else if (s[0] == 'a' && x < s.size() - 1 && s[x + 1] == 'a' && sp == -1){
                sp = x;
            }
        }
        if (np == s.size() + 1 || np == -1){
            break;
        }
        if (once){
            string ns = "";
            for (int x = np - 1; x >= 0; x--){
                ns += s[x];
            }
            for (int x = 0; x < np; x++){
                s[x] = ns[x];
            }
        }
        else{
            string ns = "";
            for (int x = 0; x < sp; x++){
                ns += s[x];
            }
            s[0] = 'a';
            for (int x = 1; x < np; x++){
                s[x] = ns[x - 1];
            }
        }
        p1 = np;
        //cout << s << "\n";
    }
    for (int x = 0; x < s.size(); x++){
        cout << answers[x] << " ";
    }
    cout << "\n";
}
