#include <fstream>
#include <string>
#include <iostream>
#include <bitset>
#include <math.h>
#include <algorithm>
#include<bits/stdc++.h>
#include <vector>
using namespace std;

int t;
int n, k;

int main(){
    cin >> t;
    for (int z = 0; z < t; z++){
        cin >> n >> k;
        string s;
        cin >> s;
        int banswer = 1000000;
        int tones = 0;
        int tzeros = 0;
        for (int x = 0; x < n; x++){
            if (s[x] == '0'){
                tzeros++;
            }
            else{
                tones++;
            }
        }

        for (int x = 0; x < k; x++){
            int nones = 0;
            int nzeros = 0;
            int start = n;
            int ending = -1;
            int curanswer = 0;
            vector<char> stuff;
            for (int y = x; y < n; y+=k){
                if (s[y] == '1'){
                    nones++;
                    if (start == n){
                        start = y;
                    }
                    ending = y;
                }
            }
            if (start > ending){
                curanswer = tones;
                banswer = min(banswer, curanswer);
                continue;
            }
            for (int y = start; y <= ending; y+= k){
                stuff.push_back(s[y]);
            }
            curanswer = tones - nones;
            int diff = 0;
            for (int y = 0; y < stuff.size(); y++){
                if (stuff[y] == '0'){
                   diff--;
                }
                else if (stuff[y] == '1'){
                    diff++;
                }
                diff = max(diff, 0);
                banswer = min(banswer, tones - diff);
            }
        }


        cout << banswer << "\n";





    }
}
