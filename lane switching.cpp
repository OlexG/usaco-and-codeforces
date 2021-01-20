#include <fstream>
#include <string>
#include <iostream>
#include <math.h>
#include <algorithm>
#include<bits/stdc++.h>
#include <vector>
using namespace std;

int n, m, r;
vector<pair<int, int>> cars[100];
//length, distance from sensor
vector<pair<int, int>> spaces[100];
//bottoy, topy
vector<pair<pair<int, int>, int>> cons[100][200];
//lane, number and size
int used[100][200];
bool answer = false;
void dfs(int cl, int cn, int mdist){
    if (cl == n - 1){
        answer = true;
        return;
    }
    used[cl][cn] = 2;
    for (int x = 0; x < cons[cl][cn].size(); x++){
        if (used[cons[cl][cn][x].first.first][cons[cl][cn][x].first.second] == 1 && mdist <= cons[cl][cn][x].second){
            dfs(cons[cl][cn][x].first.first, cons[cl][cn][x].first.second, mdist);
        }
    }
}
bool csort(pair<int, int> a, pair<int, int> b){
    return a.second < b.second;
}
int main(){
    cin >> n >> m >> r;
    int one, two, three;

    for (int x = 0; x < n; x++){
        cars[x].push_back(make_pair(0,0));
    }
    pair<int, pair<int, int>> ocar;
    for (int x = 0; x < m; x++){
        cin >> one >> two >> three;
        if (x > 0){
            cars[one].push_back(make_pair(two, three));
        }
        else{
            ocar = make_pair(one, make_pair(two, three));
        }
    }
    for (int x = 0; x < n; x++){
        cars[x].push_back(make_pair(0,r));
    }
    for (int x = 0; x < n; x++){
        sort(cars[x].begin(), cars[x].end(), csort);
    }


    for (int x = 0; x < n; x++){
        for (int y = 1; y < cars[x].size(); y++){
            spaces[x].push_back(make_pair(cars[x][y - 1].second + cars[x][y - 1].first, cars[x][y].second));
        }
    }

    /*for (int x = 0; x < n; x++){
        cout << "\n";
        for (int y = 0; y < spaces[x].size(); y++){
            cout << spaces[x][y].first << " " << spaces[x][y].second << "\n";
        }
        cout << "\n";
    }*/

    for (int x = 0; x < n - 1; x++){
        int p1 = 0;
        int p2 = 0;
        while(p1 < spaces[x].size() && p2 < spaces[x + 1].size()){
            if (spaces[x + 1][p2].second <= spaces[x][p1].first){
                p2++;
                continue;
            }
            if (spaces[x + 1][p2].first >= spaces[x][p1].second){
                p1++;
                continue;
            }
            cons[x][p1].push_back(make_pair(make_pair(x + 1, p2), min(spaces[x][p1].second, spaces[x + 1][p2].second) - max(spaces[x][p1].first, spaces[x + 1][p2].first)));
            cons[x + 1][p2].push_back(make_pair(make_pair(x, p1), min(spaces[x][p1].second, spaces[x + 1][p2].second) - max(spaces[x][p1].first, spaces[x + 1][p2].first)));
            if (spaces[x + 1][p2].second > spaces[x][p1].second){
                p1++;
            }
            else{
                p2++;
            }
        }
    }
    for (int x = 0; x < 100; x++){
        for (int y = 0; y < 200; y++){
            used[x][y] = 1;
        }
    }
    int mi = 0;
    int ma = r;
    int start = 0;
    for (int x = 0; x < spaces[0].size(); x++){
        if (ocar.second.second >= spaces[0][x].first && ocar.second.second + ocar.second.first <= spaces[0][x].second){
            start = x;
            break;
        }
    }
    while(mi < ma){
        int cur = (mi + ma + 1)/2;
        for (int x = 0; x < 100; x++){
            for (int y = 0; y < 200; y++){
                used[x][y] = 1;
            }
        }
        answer = false;
        dfs(0, start, cur);
        if (cur > spaces[0][start].second - spaces[0][start].first){
            answer = false;
        }
        if (answer){
            mi = cur;
        }
        else{
            ma = cur - 1;
        }
    }

    for (int x = 0; x < 100; x++){
        for (int y = 0; y < 200; y++){
            used[x][y] = 1;
        }
    }
    answer = false;
    dfs(0,0,11);
    //cout << answer << "\n";

    if (mi < ocar.second.first){
        cout << "Impossible\n";
    }
    else{
        double answer = ((double)mi - (double)ocar.second.first)/(2.0);
        answer = min(min(answer, (double)ocar.second.second - spaces[0][start].first),(double)spaces[0][start].second - (ocar.second.second + ocar.second.first));
        printf("%.15g", answer);
    }



}
