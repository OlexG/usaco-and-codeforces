#include <fstream>
#include <string>
#include <iostream>
#include <math.h>
#include <algorithm>
#include <vector>
#include <utility>
using namespace std;
vector<pair<int, int>> dedges;
vector<pair<int ,int >> edges;
vector<int> arr[200001];
int visited[200001];
vector<int> order;
vector<int> test;
int pos[200001];
int t, n, m;
void dfs(int x){
    visited[x] = 2;
    for (int z = 0; z < arr[x].size(); z++){
        if (visited[arr[x][z]] == 1){
            dfs(arr[x][z]);
        }
    }
    order.push_back(x);
}
int main(){
    cin >> t;
    for (int z = 0; z < t; z++){
        cin >> n >> m;
        for (int x = 0; x < n; x++){
            arr[x].clear();
            visited[x] = 1;
            pos[x] = 0;
        }
        order.clear();
        dedges.clear();
        edges.clear();
        test.clear();
        int one, two, three;
        for (int x = 0; x < m; x++){
            cin >> one >> two >> three;
            if (one){
                dedges.push_back(make_pair(two - 1, three - 1));
                arr[two - 1].push_back(three - 1);
                test.push_back(2);
            }
            else{
                test.push_back(1);
            }
            edges.push_back(make_pair(two - 1, three - 1));
        }
        for (int x = 0; x < n; x++){
            if (visited[x] == 1){
                dfs(x);
            }
        }
        reverse(order.begin(), order.end());
        for (int x = 0; x < order.size(); x++){
            //cout << order[x] << " ";
            pos[order[x]] = x;
        }
        bool works = true;
        for (int x = 0; x < dedges.size(); x++){
             if (pos[dedges[x].first] > pos[dedges[x].second]){
                works = false;
             }
        }
        if (works){
            cout << "YES\n";
            for (int x = 0; x < edges.size(); x++){
                if (test[x] == 2){
                    cout << edges[x].first + 1 << " " << edges[x].second + 1 << "\n";
                }
                else{
                    if (pos[edges[x].first] < pos[edges[x].second]){
                        cout << edges[x].first + 1 << " " << edges[x].second + 1 << "\n";
                    }
                    else{
                        cout << edges[x].second + 1 << " " << edges[x].first + 1 << "\n";
                    }
                }
            }
        }
        else{
            cout << "NO\n";
        }
    }
}
