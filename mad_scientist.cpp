#include <fstream>
#include <string>
#include <iostream>
#include <math.h>
#include <algorithm>
#include<bits/stdc++.h>
#include <vector>
using namespace std;
int n;

int main(){
    ifstream in("breedflip.in");
    ofstream out("breedflip.out");
    in >> n;
    string s1, s2;
    in >> s1 >> s2;
    string s3 = "";
    int cnt = 0;
    for (int x = 0; x < n; x++){
        if (x != 0){
            if ((s1[x] == s2[x]) && (s1[x - 1] != s2[x - 1])){
                cnt++;
            }
            if (x == n - 1 && (s1[x] != s2[x])){
                cnt++;
            }
        }
    }
    out << cnt << "\n";
}
