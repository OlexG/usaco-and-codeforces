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
#include<stdio.h>
#include<ctype.h>
#define ll long long
using namespace std;

struct State{
    ll a, b, time;
};
int t;
ll a, b, c;
ll offset = 10000000;
int main(){
    cin >> t;
    for (int z = 0; z < t; z++){
        cin >> a >> b >> c;
        set<ll> vstates;
        queue<State> q;
        q.push({0,0,0});
        ll answer = -1;
        while(q.empty() == false){
            State top = q.front();
            q.pop();
            vstates.insert(top.a * offset + top.b);
            if (top.a == c || top.b == c){
                answer = top.time;
                break;
            }
            for (int x = 0; x < 6; x++){
                ll na = top.a;
                ll nb = top.b;
                if (x == 0){
                    na = a;
                }
                if (x == 1){
                    nb = b;
                }
                if (x == 2){
                    na = 0;
                }
                if (x == 3){
                    nb = 0;
                }
                if (x == 4){
                    int am = b - nb;
                    if (am < na){
                        na -= am;
                        nb = b;
                    }
                    else{
                        nb += na;
                        na = 0;
                    }
                }
                if (x == 5){
                    int am = a - na;
                    if (am < nb){
                        nb -= am;
                        na = a;
                    }
                    else{
                        na += nb;
                        nb = 0;
                    }
                }
                if (vstates.find(na * offset + nb) == vstates.end()){
                    q.push({na, nb, top.time + 1});
                    vstates.insert(na * offset + nb);
                }
            }

        }
        cout << answer << "\n";

    }
}


