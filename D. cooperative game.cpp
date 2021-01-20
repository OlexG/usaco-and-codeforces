#include <fstream>
#include <string>
#include <iostream>
#include <math.h>
#include <algorithm>
#include<bits/stdc++.h>
#include <vector>
using namespace std;
#define FOR(i,a,b) for (int i = (a); i < (b); ++i)

int main(){
    int stage = 1;
    while(true){
        if (stage == 1){
            cout << "next 1 2 3 4 5 6 7 8 9\n";
            cout.flush();


            int n;
            cin >> n;
            string temp;
            for (int x = 0; x < n; x++){
                cin >> temp;
            }


            cout << "next 6 7 8 9\n";
            cout.flush();
            cin >> n;
            if (n == 1){
                cout << "done\n";
                cout.flush();
                break;
            }
            vector<string> res;
            for (int x = 0; x < n; x++){
                cin >> temp;
                res.push_back(temp);
            }
            if (n == 2){
                if (res[0].size() == 1 || res[1].size() == 1){
                    stage = 2;
                }
            }
        }
        if (stage == 2){
            cout << "next 0 1 2 3 4 5 6 7 8 9\n";
            cout.flush();
            int n;
            cin >> n;
            string temp;
            for (int x = 0; x < n; x++){
                cin >> temp;
            }
            if (n == 1){
                cout << "done\n";
                cout.flush();
                break;
            }
        }
    }
}
