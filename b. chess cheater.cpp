#include <fstream>
#include <string>
#include <iostream>
#include <math.h>
#include <algorithm>
#include<bits/stdc++.h>
#include <vector>
using namespace std;

int t, n, k;

struct Edge {
    int w;
    int s,e;
    bool operator<(const Edge& y) const { return w < y.w; }
};

int main(){
    cin >> t;
    for (int z = 0; z < t; z++){
        cin >> n >> k;
        string s;
        cin >> s;
        multiset<Edge> cons;

        int curs = 0;
        int p1 = 0;
        int p2 = 0;
        bool ending = true;
        bool start = true;
        for (int x = 0; x < n; x++){
            if (s[x] == 'L'){
                if (start){
                    p1 = x;
                    p2 = x;
                    start = false;
                }

                curs++;
                p2 = x;
            }
            else{
                if (curs != 0){
                    if (p1 != 0 && p2 != n - 1){
                        Edge e;
                        e.s = p1;
                        e.e = p2;
                        e.w = p2 - p1;
                        cons.insert(e);
                    }
                }
                start = true;
                p1 = x;
                p2 = x;
                curs = 0;
            }
        }

        //cout << cons.size() << "\n";
        int av = k;
        if (cons.size() > 0){
            while(av > 0){

                Edge top = *cons.begin();
                //cout << top.s << " " << top.e << " " << top.w << "\n";
                if (av >= (top.e - top.s + 1)){
                    for (int x = top.s; x <= top.e; x++){
                        s[x] = 'W';
                    }
                    av -= (top.e - top.s + 1);
                    cons.erase(cons.begin());
                }
                else{
                    //cout << av << " " << top.s << " " << top.e << " " << top.w << "\n";
                    cons.erase(cons.begin());
                }
                if (cons.size() == 0){
                    break;
                }

            }
        }

        if (av > 0){
            for (int x = 0; x < n; x++){
                if (x >= 1){
                    if (s[x - 1] == 'W'){
                        if (s[x] == 'L'){
                            s[x] = 'W';
                            av--;
                            if (av == 0){
                                break;
                            }
                        }
                    }
                }
            }
        }
        if (av > 0){
            for (int x = n - 1; x >= 0; x--){
                if (x < n - 1){
                    if (s[x + 1] == 'W'){
                        if (s[x] == 'L'){
                            s[x] = 'W';
                            av--;
                            if (av == 0){
                                break;
                            }
                        }
                    }
                }
            }
        }
        if (av > 0){
            for (int x = 0; x < n; x++){
                if (s[x] == 'L'){
                    s[x] = 'W';
                    av--;
                    if (av == 0){
                        break;
                    }
                }
            }
        }


        int counter = 0;
        if (s[0] == 'W'){
            counter++;
        }

        for (int x = 1; x < n; x++){
            if (s[x] == 'W'){
                if (s[x - 1] == 'W'){
                    counter += 2;
                }
                else{
                    counter += 1;
                }
            }
        }
        cout << counter << "\n";

    }
}
