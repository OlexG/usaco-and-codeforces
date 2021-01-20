#include <fstream>
#include <string>
#include <iostream>
#include <math.h>
#include <bitset>
#include <algorithm>
#include<bits/stdc++.h>
#include <vector>
using namespace std;
string s;
int main(){
    cin >> s;
    int nz = 0;
    int no = 0;
    for (int x = 0; x < s.size(); x++){
        nz += (s[x] == '1');
        no += (s[x] == '0');
    }
    cout << min(nz, no) * 2;

}
