#include <fstream>
#include <string>
#include <iostream>
#include <math.h>
#include <algorithm>
#include <vector>
using namespace std;
int n;
int m;
struct edge {
  long long w;
  long long c;
};
int arr[100001];

vector<vector<edge>> tree;

void gencomps(int comps[], int used[], long long maxW, int counter, int curr){
    if (used[curr] != 1){
        used[curr] = 1;
        comps[curr] = counter;
        for (int x = 0; x < tree[curr].size(); x++){
            if (tree[curr][x].w >= maxW && used[tree[curr][x].c] != 1){
                gencomps(comps, used, maxW, counter, tree[curr][x].c);
            }
        }
    }
}
int main(){
    ifstream in("wormsort.in");
    ofstream out("wormsort.out");
    in >> n;
    in >> m;
    int temp;
    for (int x = 0; x < n; x ++){
        vector<edge> em;
        in >> temp;
        arr[x] = temp - 1;
        tree.push_back(em);
    }
    bool need = false;
    for (int x = 0; x < n; x ++){
        if (arr[x] != x){
            need = true;
        }
    }
    if (need){
    int one;
    int two;
    int three;
    edge cur;
    for (int x = 0; x < m; x++){
        in >> one;
        in >> two;
        in >> three;
        cur.w = three;
        cur.c = two - 1;
        tree[one - 1].push_back(cur);
        cur.c = one - 1;
        tree[two - 1].push_back(cur);
    }
    long long mi = 0;
    long long ma = 1000000001;
    long long w;
    while (mi < ma){
        w = (mi + ma + 1)/2;

        int comps[n];
        int used[n];
        for (int x = 0; x < n; x++){
            comps[x] = -1;
            used[x] = -1;
        }
        for(int x = 1; x < n + 1; x ++){

            if (used[x - 1] != 1){

                gencomps(comps, used,w , x, x - 1);
            }
        }
        bool worked = true;
        for (int x = 0; x < n; x++){
            if (comps[arr[x]] != comps[x]){
                worked = false;
            }
        }
        if (worked){
            mi = w;
        }
        else{
            ma = w - 1;
        }

    }
    out << mi << "\n";
    }
    else{
        out << -1 << "\n";
    }

}
