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
    vector<int> st;
    vector<int> answer;
    int cur = 2;
    int curdiv = 1;
    for (int x = 1; x <= n; x++){
        st.push_back(x);
    }
    while(true){
        vector<int> nst;
        int counter = 0;
        for (int x = 0; x < st.size(); x++){
            if (st[x] % cur != 0){
                counter += 1;
            }
        }
        if (st.size() - counter <= 1){
            for (int x = 0; x < st.size() - 1; x++){
                answer.push_back(curdiv);
            }
            answer.push_back(st[st.size() - 1]);
            break;
        }
        else{
            for (int x = 0; x < st.size(); x++){
                if (st[x] % cur != 0){
                    answer.push_back(curdiv);
                }
                else{
                    nst.push_back(st[x]);
                }
            }
            st.clear();
            for (int x = 0; x < nst.size(); x++){
                st.push_back(nst[x]);
            }
            curdiv *= 2;
            cur *= 2;
        }
    }
    for (int x = 0; x < answer.size(); x++){
        cout << answer[x] << " ";
    }
}
