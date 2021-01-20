#include <fstream>
#include <string>
#include <iostream>
#include <math.h>
#include <algorithm>
#include <vector>
#include <set>
#include <bits/stdc++.h>
using namespace std;
void display(const set<pair<int, int>>& s)
{
    bool found = false;

    // range-based for loop
    for (auto const &x : s) {
        found = true;
        cout << "(" << x.first << ", "
             << x.second << ")"
             << " ";
    }

    if (not found) {
        cout << "No valid pair\n";
    }
}

int dirx[4] = {1, 0, -1, 0};
int diry[4] = {0, 1, 0, -1};
string temp;

int curdir = 0;
pair<int, int> arr[100001];
int dirs[1000001];
int main(){
    cin >> temp;
    arr[0] = make_pair(0,0);
    for (int x = 0; x < temp.size(); x++){
        dirs[x] = curdir;
        if (temp[x] == 'F'){
            pair<int, int> temp = make_pair(arr[x].first + dirx[curdir], arr[x].second + diry[curdir]);
            arr[x + 1] = temp;

        }
        else if (temp[x] == 'R'){
            curdir++;
            if (curdir > 3){
                curdir = 0;
            }
            pair<int, int> temp = make_pair(arr[x].first, arr[x].second);
            arr[x + 1] = temp;
        }
        else{
            curdir--;
            if (curdir < 0){
                curdir = 3;
            }
            pair<int, int> temp = make_pair(arr[x].first, arr[x].second);
            arr[x + 1] = temp;
        }

    }

    int cur = temp.size();
    set<pair<int, int>> pos;
    /*
LLFFLRLRLRLFFLLRRFFR*/
    while(cur > 0){
        if (temp[cur - 1] == 'F'){
            int dir = dirs[cur - 1];
            int changex = arr[temp.size()].first - arr[cur - 1].first;
            int changey = arr[temp.size()].second - arr[cur - 1].second;
            changex -= dirx[dir];
            changey -= diry[dir];
            pos.insert(make_pair(arr[cur - 1].first + changey, arr[cur - 1].second - changex));
            pos.insert(make_pair(arr[cur - 1].first - changey, arr[cur - 1].second + changex));
            //cout << arr[cur - 1].first + changey << " " << arr[cur - 1].second - changex << "\n" << arr[cur - 1].first - changey << " " << arr[cur].second + changex << "\n";

        }
        else if (temp[cur - 1] == 'R'){
            int dir = dirs[cur - 1];
            int changex = arr[temp.size()].first - arr[cur - 1].first;
            int changey = arr[temp.size()].second - arr[cur - 1].second;
            pos.insert(make_pair(arr[cur - 1].first + changey + dirx[dir], arr[cur - 1].second - changex + diry[dir]));
            pos.insert(make_pair(arr[cur - 1].first - changex , arr[cur - 1].second - changey));
        }
        else{
            int dir = dirs[cur - 1];
            int changex = arr[temp.size()].first - arr[cur - 1].first;
            int changey = arr[temp.size()].second - arr[cur - 1].second;
            /*if (cur - 1 == 1){
                cout << changex << " " << changey << "\n";
                cout << dirx[dir] << " " << diry[dir] << "\n";
            }*/
            pos.insert(make_pair(arr[cur - 1].first - changey + dirx[dir], arr[cur - 1].second + changex + diry[dir]));
            pos.insert(make_pair(arr[cur - 1].first - changex, arr[cur - 1].second - changey));
        }
        cur--;
    }
    //display(pos);
    cout << pos.size();
}
