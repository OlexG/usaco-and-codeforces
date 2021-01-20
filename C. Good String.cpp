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
/*
3
95831
100120013
252525252525*/
int main(){
    cin >> t;
    for (int x = 0; x < t; x++){
        cin >> s;
        int banswer = s.size();
        for (char one = '0'; one <= '9'; one++){
            for (char two = '0'; two <= '9'; two++){
                bool lf = true;
                int curc = 0;
                for (int x = 0; x < s.size(); x++){
                    if (s[x] == one && lf){
                        lf = false;
                    }
                    else if (s[x] == two && !lf){
                        lf = true;
                    }
                    else{
                        curc++;
                    }
                }
                if (!lf && one != two){
                    curc++;
                }
                banswer = min(banswer, curc);
            }
        }
        cout << banswer << "\n";
    }
}

