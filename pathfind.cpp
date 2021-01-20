#include <fstream>
#include <string>
#include <iostream>
#include <math.h>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
int m, n;

int main(){
    cin >> n >> m;
    vector<int> con[n];
    int visited[n];
    queue<pair<int, int>> q;
    int one;
    for (int x = 0; x < n; x++){
        visited[x] = 1;
        for (int y = 0; y < n; y++){
            cin >> one;
            if (one == 1){
                con[x].push_back(y);
            }
        }
    }
    vector<int> answers[n];
    q.push(make_pair(m - 1, 0));
    while(q.empty() == false){
        if (q.front().second > 0 && visited[q.front().first] == 1){
            answers[q.front().second - 1].push_back(q.front().first + 1);
        }
        visited[q.front().first] = 2;

        for (int x = 0; x < con[q.front().first].size(); x++){
            if (visited[con[q.front().first][x]] == 1){
                q.push(make_pair(con[q.front().first][x], q.front().second + 1));
            }
        }
        q.pop();
    }
    cout << m << "\n";
    for (int x = 0; x < n; x++){
        sort(answers[x].begin(), answers[x].end());
        for (int y = 0; y < answers[x].size(); y++){
            cout << answers[x][y] << " ";
        }
        cout << "\n";
    }
}

