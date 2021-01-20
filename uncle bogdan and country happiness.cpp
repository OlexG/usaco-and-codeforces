#include <fstream>
#include <string>
#include <iostream>
#include <math.h>
#include <algorithm>
#include <vector>
using namespace std;
int t;
int n, m;
int  p[100000];
int h[100000];
int total[100000];
int used[100000];
int happyp[100000];
int happyptest[100000];
vector<int> arr[100000];
vector<int> order;
void dfs1(int x){
    used[x] = 2;
    total[x] = p[x];
    for (int z = 0; z < arr[x].size(); z++){
        if (used[arr[x][z]] == 1){
            dfs1(arr[x][z]);
            total[x] += total[arr[x][z]];
        }
    }
    order.push_back(x);
}

int main(){
    cin >> t;
    for (int x = 0; x < t; x++){
        order.clear();
        cin >> n >> m;
        for (int x = 0; x < n; x++){
            cin >> p[x];
            used[x] = 1;
        }
        for (int x = 0; x < n; x++){
            cin >> h[x];
            arr[x].clear();
        }
        int one, two;
        for (int x = 0; x < n - 1; x++){
            cin >> one >> two;
            arr[one - 1].push_back(two - 1);
            arr[two - 1].push_back(one - 1);
        }
        dfs1(0);
        bool answer = true;
        for (int x = 0; x < n; x++){
            if (total[x] > m){
                answer = false;
            }
            happyptest[x] = 0;
            if ((h[x] + total[x]) % 2 != 0){
                answer = false;
            }
            happyp[x] = (h[x] + total[x])/2;
            if (happyp[x] < 0 || happyp[x] > total[x]){
                answer = false;
            }
            //cout << happyp[x] << " ";
        }
        for (int x = 0; x < n; x++){
            int cur = order[x];
            used[cur] = 3;
            if (happyptest[cur] <= 0){
                happyptest[cur] = happyp[cur];
            }
            for (int z = 0; z < arr[cur].size(); z++){
                if (used[arr[cur][z]] == 2){
                    happyptest[arr[cur][z]] += happyp[cur];
                }
            }
        }
        /*for (int x = 0; x < n; x++){
            cout << happyptest[x] << " ";
        }*/
        for (int x = 0; x < n; x++){
            if (happyptest[x] > happyp[x]){
                answer = false;
            }
        }
        if (answer){
            cout << "YES\n";
        }
        else{
            cout << "NO\n";
        }
    }
}
