#include <fstream>
#include <string>
#include <iostream>
#include <math.h>
#include <algorithm>
#include<bits/stdc++.h>
#include <vector>
using namespace std;

int t;
int n;
int main(){
    cin >> t;
    for (int z = 0; z < t; z++){
        string s;
        cin >> n;
        cin >> s;
        int n1 = 0;
        int n0 = 0;
        for (int x = 1; x < n; x++){
            if (s[x - 1] == s[x]){
                if (s[x] == '1'){
                    n1++;
                }
                if (s[x] == '0'){
                    n0++;
                }
            }
        }
        cout << max(n1, n0) << "\n";
    }
}
