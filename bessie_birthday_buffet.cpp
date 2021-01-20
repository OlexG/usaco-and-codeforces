#include <fstream>
#include <string>
#include <iostream>
#include <bitset>
#include <math.h>
#include <string>
#include <algorithm>
#include<bits/stdc++.h>
#include <vector>
using namespace std;

vector<int> cons[1001];
pair<int,int> arr[1001];
int dist[1001][1001];
int n, k;

int main(){
    ifstream in("buffet.in");
    ofstream out("buffet.out");
    in >> n >> k;
    for (int x = 0; x < n; x++){
        int one;
        in >> one;
        arr[x] = make_pair(one, x);
        int two;
        in >> two;
        for (int y = 0; y < two; y++){
            int temp;
            in >> temp;
            cons[x].push_back(temp - 1);
        }
    }
    for (int x = 0; x < n; x++){
        for (int y = 0; y < n; y++){
            dist[x][y] = -1;
        }
    }
    for (int x = 0; x < n; x++){
        queue<pair<int, int>> q;
        q.push(make_pair(x, 0));
        int used[n];
        for (int y = 0; y < n; y++){
            used[y] = 2;
        }
        while(q.empty() == false){
            int top = q.front().first;
            int cdist = q.front().second;
            used[top] = 1;
            for (int y = 0; y < cons[top].size(); y++){
                if (used[cons[top][y]] == 2){
                    dist[x][cons[top][y]] = cdist + 1;
                    used[cons[top][y]] = 1;
                    q.push(make_pair(cons[top][y], cdist + 1));
                }
            }
            q.pop();
        }
    }
    sort(arr, arr + n);
    int answer = arr[0].first;
    int best[n];
    best[arr[0].second] = arr[0].first;
    for (int x = 1; x < n; x++){
        best[arr[x].second] = arr[x].first;
        for (int y = 0; y < x; y++){
            if (dist[arr[x].second][arr[y].second] != -1){
                best[arr[x].second] = max(best[arr[x].second], arr[x].first + best[arr[y].second] - (dist[arr[x].second][arr[y].second] * k));
            }
        }
        answer = max(answer, best[arr[x].second]);
    }
    out << answer << "\n";
}

