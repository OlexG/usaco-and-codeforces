#include <fstream>
#include <string>
#include <iostream>
#include <math.h>
#include <algorithm>
#include<bits/stdc++.h>
#include <vector>
using namespace std;
int t;
string s;

int main(){
    cin >> t;
    for (int z = 0; z < t; z++){
        cin >> s;
        int rc = 0;
        int pc = 0;
        int sc = 0;
        for (int x = 0; x < s.size(); x++){
            if (s[x] == 'R'){
                rc++;
            }
            else if (s[x] == 'S'){
                sc++;
            }
            else{
                pc++;
            }
        }
        char answer = 'P';
        if (pc >= rc && pc >= sc){
            answer = 'S';
        }
        if (sc >= pc && sc >= rc){
            answer = 'R';
        }
        string sanswer = "";
        for (int x = 0; x < s.size(); x++){
            sanswer += answer;
        }
        cout << sanswer << "\n";

    }
}
