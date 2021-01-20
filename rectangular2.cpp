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
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
#define ll long long
using namespace std;
using namespace __gnu_pbds;
/*
4
0 2
1 0
2 3
3 5
*/
int n;
vector<pair<int, int>> recs;



bool csort(pair<int, int> a, pair<int, int> b){
    if (a.second == b.second){
        return a.first < b.first;
    }
    else{
        return a.second < b.second;
    }
}
int camr[2501];
int caml[2501];
int main(){
    cin >> n;
    int one, two;
    for (int x = 0; x < n; x++){
        cin >> one >> two;
        recs.push_back(make_pair(one, two));
        camr[x] = 0;
        caml[x] = 0;
    }
    sort(recs.begin(), recs.end(), csort);

    ll answer = 0;
    for (int x = 0; x < n; x++){
        answer++;
        ll oaml = 0;
        ll oamr = 0;
        for (int y = x - 1; y >= 0; y--){
            if (recs[y].first > recs[x].first){
                oamr += 1;
            }
            if (recs[y].first < recs[x].first){
                oaml += 1;
            }

            if (y == x - 1 || recs[y].second != recs[y + 1].second){
                for (int z = y - 1; z >= 0; z--){
                    if (recs[z].second != recs[z + 1].second){
                        break;
                    }
                    if (recs[z].first > recs[x].first){
                        oamr += 1;
                    }
                    if (recs[z].first < recs[x].first){
                        oaml += 1;
                    }
                }
            }
            int aml;
            int amr;
            if (recs[y].first > recs[x].first){
                amr = camr[y];
                aml = oaml;
            }
            if (recs[y].first < recs[x].first){
                aml = caml[y];
                amr = oamr;
            }
            //cout << aml << " " << amr << "\n";
            answer += (aml * amr + aml + amr);
            answer += 1;
        }
        for (int y = x - 1; y >= 0; y--){
            if (recs[y].first > recs[x].first){
                caml[y] += 1;
            }
            if (recs[y].first < recs[x].first){
                camr[y] += 1;
            }
        }

        //cout << answer << "\n";
    }
    cout << answer + 1 << "\n";
}
