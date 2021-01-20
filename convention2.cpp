#include <fstream>
#include <string>
#include <iostream>
#include <math.h>
#include <queue>
#include <algorithm>
#include <bits/stdc++.h>
#include <set>
#include <vector>
using namespace std;
int n;
priority_queue<pair<int, pair<int, int>>> curcows;
vector<pair<int, pair<int, int>>> cows;
bool csort(pair<int, pair<int, int> > a, pair<int, pair<int, int> > b){
    return a.second.first > b.second.first;
}
int main(){
    ifstream in("convention2.in");
    ofstream out("convention2.out");
    in >> n;
    int one, two;
    for (int x = 0; x < n; x++){
        in >> one >> two;
        cows.push_back(make_pair(n - x, make_pair(one, two)));
    }
    sort(cows.begin(), cows.end(), csort);

    //cout << "\n\n";
    int curtime = cows[cows.size()-1].second.first;

    int answer = 0;
    while (true){
        bool process = true;
        if (cows.empty() == false){
            if (cows[cows.size()-1].second.first > curtime){
                curtime = cows[cows.size()-1].second.first;
                continue;
            }
            while(cows[cows.size()-1].second.first <= curtime){
                curcows.push(cows[cows.size()-1]);
                cows.pop_back();
                if (cows.empty()){
                    break;
                }
            }
        }
        if (cows.empty()){
            process = true;
        }

        if (process){
            while(curcows.empty() == false){
                pair<int, pair<int, int>> curcow = curcows.top();
                //cout << curcow.second.first << " " << curcow.second.second << " " << curtime << "\n";
                answer = max(answer, curtime - curcow.second.first);
                curtime = curtime + curcow.second.second;
                curcows.pop();
                if (cows.empty() == false){
                while(cows[cows.size()-1].second.first <= curtime){
                    curcows.push(cows[cows.size()-1]);
                    cows.pop_back();
                    if (cows.empty()){
                        break;
                    }
                }
                }
            }
        }
        if (cows.empty()){
            break;
        }
    }

    out << answer << "\n";
}
