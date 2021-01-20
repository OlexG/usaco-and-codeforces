#include <fstream>
#include <string>
#include <iostream>
#include <math.h>
#include <vector>
#include <bitset>
#include <algorithm>
using namespace std;

int n, m;

vector<pair<int, char>> cons[100001];
int paints[100001];
int used[100001];
bool answer = true;
void dfs(int cur, int mark){
    used[cur] = 2;
    paints[cur] = mark;

    for (int x = 0; x < cons[cur].size(); x++){
        if (cons[cur][x].second == 'D' && mark == paints[cons[cur][x].first] && paints[cons[cur][x].first] != -1){
            answer = false;
        }
        if (cons[cur][x].second == 'S' && mark != paints[cons[cur][x].first] && paints[cons[cur][x].first] != -1){
            answer = false;
        }
        if (paints[cons[cur][x].first] == -1 && used[cons[cur][x].first] == 1){
            if (cons[cur][x].second == 'D'){
                dfs(cons[cur][x].first, (mark + 1)%2);
            }
            else{
                dfs(cons[cur][x].first, mark);
            }
        }
    }
}
int main(){
    ifstream in("revegetate.in");
    ofstream out("revegetate.out");
    in >> n >> m;
    int coms = 0;
    char a;
    int b;
    int c;
    for (int x = 0; x < m; x++){
        in >> a >> b >> c;
        cons[b - 1].push_back(make_pair(c - 1, a));
        cons[c - 1].push_back(make_pair(b - 1, a));
    }
    for (int x = 0; x < n; x++){
        paints[x] = -1;
        used[x] = 1;
    }
    for (int x = 0; x < n; x++){
        if (used[x] == 1){
            coms++;
            dfs(x, 0);
        }
    }
    if (answer){
        out << "1";
        for (int x = 0; x < coms; x++){
            out << "0";
        }
        for (int x = 0; x < n; x++){
            if (used[x] == -1){
                out << "0";
            }
        }
        out << "\n";
    }
    else{
        out << "0\n";
    }

}
