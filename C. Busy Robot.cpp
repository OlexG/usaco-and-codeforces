#pragma GCC optimize("O2")
#include <fstream>
#include <string>
#include <iostream>
#include <bitset>
#include <math.h>
#include <string>
#include <algorithm>
#include <assert.h>
#include<bits/stdc++.h>
#include <vector>
#include <queue>
#include<stdio.h>
#include<ctype.h>
#define ll long long
using namespace std;

int t;
int n;
vector<pair<int, int>> coms;
int main(){
    cin >> t;
    for (int z = 0; z < t; z++){
        cin >> n;
        coms.clear();
        int one, two;
        for (int x = 0; x < n; x++){
            cin >> one >> two;
            coms.push_back({one, two});
        }
        int answer = 0;
        int curpos = 0;
        int curtime = 0;
        int curdes = 0;
        bool last = true;
        bool going = false;
        for (int x = 0; x < n; x++){
            if (!going){
                curtime = coms[x].first;
                curdes = coms[x].second;
                going = true;
            }
            else{
                bool res = false;
                int lpos = curpos;
                if (curpos < curdes){
                    if (curdes - curpos <= coms[x].first - curtime){
                        res = true;
                        curpos = curdes;
                    }
                    else{
                        curpos += (coms[x].first - curtime);
                        curtime += (coms[x].first - curtime);
                    }
                }
                else{
                    if (curpos - curdes <= coms[x].first - curtime){
                        res = true;
                        curpos = curdes;
                    }
                    else{
                        curpos -= (coms[x].first - curtime);
                        curtime += (coms[x].first - curtime);
                    }
                }
                if (coms[x - 1].second >= min(lpos, curpos) && coms[x - 1].second <= max(lpos, curpos)){
                    answer++;
                }
                if (res){
                    if (x == n - 1){
                        answer++;
                        last = false;
                    }
                    curtime = coms[x].first;
                    curdes = coms[x].second;
                }
            }
            //cout << curpos << " " << curtime << " " << curdes << "\n";
        }
        if (coms[n - 1].second >= min(curpos, curdes) && coms[n - 1].second <= max(curpos, curdes) && last){
            answer++;
        }
        cout << answer << "\n";
    }
}
