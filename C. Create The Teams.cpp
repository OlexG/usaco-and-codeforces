#include <fstream>
#include <string>
#include <iostream>
#include <math.h>
#include <algorithm>
#include<bits/stdc++.h>
#include <vector>
using namespace std;

int t;
long long n, c;
vector<long long> st;
int main(){
    cin >> t;
    for (int z = 0; z < t; z++){
        cin >> n >> c;
        st.clear();
        long long one;
        for (int x = 0; x < n; x++){
            cin >> one;
            st.push_back(one);
        }
        sort(st.rbegin(), st.rend());
        long long sf = 1;
        int answer = 0;
        for (int x = 0; x < n; x++){
            if (sf * st[x] >= c){
                answer++;
                sf = 1;
            }
            else{
                sf++;
            }
        }
        cout << answer << "\n";
    }
}
