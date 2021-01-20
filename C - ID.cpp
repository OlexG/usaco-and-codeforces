#include <fstream>
#include <string>
#include <iostream>
#include <bitset>
#include <math.h>
#include <algorithm>
#include<bits/stdc++.h>
#include <string>
#include <vector>
using namespace std;

int n, m;
vector<int> cities[100002];

vector<pair<int, int>> st;
int main(){
    cin >> m >> n;
    int one, two;
    for (int x = 0; x < n; x++){
        cin >> one >> two;
        st.push_back(make_pair(one, two));
        cities[one].push_back(two);
    }
    for (int x = 0; x <= m; x++){
        sort(cities[x].begin(), cities[x].end());
    }
    for (int x = 0; x < n; x++){
        int one = st[x].first;
        auto low = lower_bound(cities[one].begin(), cities[one].end(), st[x].second);
        int two =  low - cities[one].begin() + 1;

        //cout << one << " " << two << "\n";
        string s1 = to_string(one);
        string s2 = to_string(two);
        int si1 = s1.size();
        int si2 = s2.size();
        for (int y = 6; y > si1; y--){
            s1 = '0' + s1;
        }
        for (int y = 6; y > si2; y--){
            s2 = '0' + s2;
        }
        cout << s1 << s2 << "\n";
    }
}
