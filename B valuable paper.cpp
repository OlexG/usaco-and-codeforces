#include <fstream>
#include <string>
#include <iostream>
#include <math.h>
#include <algorithm>
#include<bits/stdc++.h>
#include <vector>
using namespace std;


int n, m;

vector<pair<int, pair<int, int>>> cs;
bool ok(int d){
    vector<pair<int, int>> cur;
    for (int x = 0; x < cs.size(); x++){
        if (cs[x].first > d){
            break;
        }
        cur.push_back(cs[x].second);
    }


}
int main(){
    cin >> n >> m;
    int one, two, three;;
    for (int x = 0; x < m; x++){
        cin >> one >> two >> three;
        cs.push_back(make_pair(three, make_pair(one, two)));
    }
    sort(cs.begin(), cs.end());
    int small = 0;
    int large = 1000000000;
    //cout << ok(9) << "\n";
    while(small < large){
        int mid = (small + large)/2;
        if (ok(mid)){
            large = mid;
        }
        else{
            small = mid + 1;
        }
    }
    if (large == 1000000000){
        cout << -1 << "\n";
        return 0;
    }
    cout << large << "\n";

}
