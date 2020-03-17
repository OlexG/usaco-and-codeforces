#include <fstream>
#include <string>
#include <iostream>
#include <math.h>
#include <vector>
#include <bitset>
#include <algorithm>
using namespace std;

int n, m;

string answer = "1";
int c[100001];
vector<int> mn[100001];
void dfs(int cur, int mark){
    if (!c[cur]){
        c[cur] = mark;
        for (int x = 0; x < mn[cur].size(); x ++){
            dfs(mn[cur][x], mark);

        }
    }
}
int main(){

    ifstream in("revegetate.in");
    ofstream out("revegetate.out");
    in >> n >> m;
    char one;
    int two;
    int three;



    for (int x =0; x < m; x ++){
        in >> one >> two >> three;
        mn[two - 1].push_back(three - 1);
        mn[three - 1].push_back(two - 1);

    }
    for (int x = 0; x < n; x++){
        dfs(x, x + 1);
    }
    int cur = 0;
    sort(c, c+n);
    for (int x = 0; x < n; x++){

        if (cur != c[x]){
            cur = c[x];
            answer = answer + "0";
        }
    }







    out <<answer<< "\n";





}
