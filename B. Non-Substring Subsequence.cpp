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
int n, q;
int main(){
    cin >> t;
    for (int z = 0; z < t; z++){
        cin >> n >> q;
        string s;
        cin >> s;
        int one, two;
        for (int x = 0; x < q; x++){
            cin >> one >> two;
            string ns = "";
            for (int y = one - 1; y < two; y++){
                ns += s[y];
            }
            bool answer = false;
            for (int y = 0; y <= one - 2; y++){
                if (s[y] == s[one - 1]){
                    answer = true;
                }
            }
            for (int y = two; y < n; y++){
                if (s[y] == s[two - 1]){
                    answer = true;
                }
            }
            if (answer){
                cout << "YES\n";
            }
            else{
                cout << "NO\n";
            }
        }
    }
}
