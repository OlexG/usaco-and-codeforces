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
    for (int b = 0; b < t; b++){
        string s;
        int dist;
        cin >> s >> dist;
        char arr[s.size()];
        for(int x = 0; x < s.size(); x++){
            arr[x] = '1';
        }
        for (int x = 0; x < s.size(); x++){
            if (s[x] == '0'){
                int findex = x - dist;
                int sindex = x + dist;
                if (findex >= 0){
                    arr[findex] = '0';
                }
                if (sindex < s.size()){
                    arr[sindex] = '0';
                }
            }
        }
        int answer = true;
        for (int x = 0; x < s.size(); x++){
            if (s[x] == '1'){
                int findex = x - dist;
                int sindex = x + dist;
                if (findex < 0){
                    if (sindex >= s.size()){
                        answer = false;
                    }
                    else if (arr[sindex] == '0'){
                        answer = false;
                    }
                }
                else if (arr[findex] == '0'){
                    if (sindex >= s.size()){
                        answer = false;
                    }
                    else if (arr[sindex] == '0'){
                        answer = false;
                    }
                }
            }
        }
        if (answer){
            for (int x = 0; x < s.size(); x++){
                cout << arr[x];
            }
            cout << "\n";
        }
        else{
            cout << "-1\n";
        }
    }
}
