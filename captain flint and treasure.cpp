#include <fstream>
#include <string>
#include <iostream>
#include <math.h>
#include <algorithm>
#include <vector>
using namespace std;

long long n;
vector<long long> order;
vector<long long> arr;
vector<long long> pos;
vector<long long> edges[1000000];
vector<long long> used;
void dfs(long long x){
    used[x] = 2;
    for (int z = 0; z < edges[x].size(); z++){
        if (used[edges[x][z]] == 1){
            dfs(edges[x][z]);
        }
    }
    order.push_back(x);
}
int main(){
    cin >> n;
    long long temp;
    for (int x = 0; x < n; x++){
        cin >> temp;
        arr.push_back(temp);
    }
    for (int x = 0; x < n; x++){
        used.push_back(1);
        cin >> temp;
        pos.push_back(temp);
        if (temp != - 1){
            edges[x].push_back(temp - 1);
        }
    }
    long long usedorder[n];
    for (int x = 0; x < n; x++){
        if (used[x] == 1){
            dfs(x);
        }
        usedorder[x] = 1;
    }
    reverse(order.begin(), order.end());
    vector<long long> orderofanswer;
    vector<long long> negorders;
    for (int x = 0; x < order.size(); x++){
        if (pos[order[x]] != -1){
            if (arr[order[x]] > 0){
                arr[pos[order[x]] - 1] += arr[order[x]];
                orderofanswer.push_back(order[x] + 1);
                usedorder[order[x]] = 2;
            }
            else{
                negorders.push_back(order[x] + 1);
                usedorder[order[x]] = 2;
            }
        }
    }
    long long ans = 0;
    for (int x = 0; x < n; x++){
        ans += arr[x];
        if (usedorder[x] == 1){
            orderofanswer.push_back(x + 1);
        }
    }
    reverse(negorders.begin(), negorders.end());
    for (int x = 0; x < negorders.size(); x++){
        orderofanswer.push_back(negorders[x]);
    }
    cout << ans << "\n";
    for (int x = 0; x < n; x++){
        cout << orderofanswer[x] << " ";
    }
    cout << "\n";


}
