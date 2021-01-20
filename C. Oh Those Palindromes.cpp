#pragma GCC optimize("O2")
#include <fstream>
#include <string>
#include <iostream>
#include <bitset>
#include <math.h>
#include <string>
#include <algorithm>
#include<bits/stdc++.h>
#include <vector>
#include <queue>
using namespace std;

int n;

int main(){
    cin >> n;
    vector<char> st;
    char temp;
    for (int x = 0; x < n; x++){
        cin >> temp;
        st.push_back(temp);
    }
    sort(st.begin(), st.end());
    for (int x = 0; x < st.size(); x++){
        cout << st[x];
    }
}
