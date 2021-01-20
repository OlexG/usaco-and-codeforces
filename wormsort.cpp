#include <fstream>
#include <string>
#include <iostream>
#include <math.h>
#include <algorithm>
#include <vector>
using namespace std;
int n;
int m;
int arr[100001];
int groups[100001];
int used[100001];
vector<int> con[100001];
bool custsort(pair<pair<int, int>, long long> a, pair<pair<int, int>, long long> b){
    return a.second > b.second;
}

void dfs(int cur, int gr){
    groups[cur] = gr;
    used[cur] = 2;
    for (int x = 0; x < con[cur].size(); x++){
        if (used[con[cur][x]] == 1){
            dfs(con[cur][x], gr);
        }
    }
}

int main(){
    ifstream in("wormsort.in");
    ofstream out("wormsort.out");
    in >> n;
    in >> m;
    vector<pair<pair<int , int>, long long>> wormholes;
    int temp;
    for (int x = 0; x < n; x++){
        in >> temp;
        arr[x] = temp - 1;
    }

    int one, two;
    long long three;
    for (int x = 0; x < m; x++){
        in >> one >> two >> three;
        wormholes.push_back(make_pair(make_pair(one - 1, two - 1), three));
    }

    long long small = 0;
    long long large = 1000000001;
    while(small < large){
        long long cur = (small + large + 1)/2;
        for (int x = 0; x < n; x++){
            used[x] = 1;
            groups[x] = -1;
            con[x].clear();
        }
        for (int x = 0; x < m; x++){
            if (wormholes[x].second >= cur){
                con[wormholes[x].first.first].push_back(wormholes[x].first.second);
                con[wormholes[x].first.second].push_back(wormholes[x].first.first);
            }
        }
        int gr = 1;
        for (int x = 0; x < n; x++){
            if (used[x] == 1){
                dfs(x, gr);
                gr++;
            }
        }
        bool answer = true;
        for (int x = 0; x < n; x++){
            //cout << groups[x] << " ";
            if (arr[x] != x){
                if (groups[arr[x]] != groups[x]){
                    answer = false;
                }
            }
        }
        if (answer){
            small = cur;
        }
        else{
            large = cur - 1;
        }
    }
    if (small == 1000000001){
        out << "-1\n";
    }
    else{
        out << small << endl;
    }


}
