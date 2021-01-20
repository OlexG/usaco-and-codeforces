#include <fstream>
#include <string>
#include <iostream>
#include <math.h>
#include <algorithm>
#include<bits/stdc++.h>
#include <vector>
using namespace std;
#define FOR(i,a,b) for (int i = (a); i < (b); ++i)

vector<int> rev[200000];
int dfsused[200000];
int tsizes[200000];
int ntol[200000];
int ntol2[200000];
int vis[200000];
int dfs2used[200000];
int n;
void dfs(int cur, int amount, int l){
    dfsused[cur] = 2;
    ntol2[cur] = l;
    for (int x = 0; x < rev[cur].size(); x++){
        if (dfsused[rev[cur][x]] == 1 && ntol[rev[cur][x]] == -1){
            tsizes[rev[cur][x]] = amount + 1;
            dfs(rev[cur][x], amount + 1, l);
        }
    }
}
void dfs2(int cur){
    vis[cur] = 2;
    dfs2used[cur] = 2;
    for (int x = 0; x < rev[cur].size(); x++){
        if (dfs2used[rev[cur][x]] == 1){
            dfs2(rev[cur][x]);
        }
    }
}
int main(){
    //ifstream in("in.txt");
    //ofstream out("out.txt");
    cin >> n;
    int dir[n + 1];
    int used[n + 1];
    int amount[n + 1];


    for (int x = 0; x < n; x++){
        used[x] = 0;
        dfsused[x] = 1;
        dfs2used[x] = 1;
        vis[x] = 1;
        amount[x] = 0;
    }
    int temp;
    for (int x = 0; x < n; x++){
        cin >> temp;
        dir[x] = temp - 1;
        rev[temp - 1].push_back(x);
        amount[temp - 1] += 1;
    }
    int lcount = 0;
    int lsize[n];
    for (int x = 0; x < n; x++){
        ntol[x] = -1;
    }
    int ccounter = 0;
    for (int x = 0; x < n; x++){
        if (vis[x] == 1){
            int cur = x;
            vis[cur] = 2;
            bool works = true;
            while(vis[dir[cur]] == 1){
                vis[dir[cur]] = 2;
                cur = dir[cur];
            }
            if (vis[dir[cur]] == 2){
                int original = dir[cur];
                cur = dir[cur];
                dfs2(cur);
                int counter = 1;
                ntol[cur] = lcount;
                while(dir[cur] != original){
                    cur = dir[cur];
                    ntol[cur] = lcount;
                    counter++;
                }
                lsize[lcount] = counter;
                lcount++;
            }
            ccounter++;
        }
    }

    for (int x = 0; x < n; x++){
        tsizes[x] = -1;
    }
    for (int x = 0; x < n; x++){
        if (ntol[x] != -1 && dfsused[x] == 1){
            dfs(x, 0, ntol[x]);
        }
    }

    int answers[n];
    for (int x = 0; x < n; x++){
        if (tsizes[x] == -1){
            answers[x] = lsize[ntol[x]];
        }
        else{
            answers[x] = lsize[ntol2[x]] + tsizes[x];
        }
    }
    for (int x = 0; x < n; x++){
        cout << answers[x] << " ";
    }


}
