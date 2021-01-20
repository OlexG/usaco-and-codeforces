#include <fstream>
#include <string>
#include <iostream>
#include <math.h>
#include <queue>
#include <algorithm>
#include <bits/stdc++.h>
#include <set>
#include <vector>
using namespace std;

int n, b;
vector<pair <int, pair<int, int>>> boots;
vector<pair<int, int>> tiles;
bool tsort(pair<int, int> a, pair<int, int> b){
    return a.second < b.second;
}
bool bsort(pair<int, pair<int, int>> a, pair<int, pair<int, int>> b){
    return a.second.first < b.second.first;
}
int main(){
    ifstream in("snowboots.in");
    ofstream out("snowboots.out");
    in >> n >> b;
    int temp;
    for (int x = 0; x < n; x++){
        in >> temp;
        tiles.push_back(make_pair(x, temp));
    }
    int one, two;
    set<pair<int, int>> used;
    for (int x = 0; x < b; x++){
        cin >> one >> two;
        boots.push_back(make_pair(x, make_pair(one, two)));
    }
    sort(tiles.begin(), tiles.end(), tsort);
    sort(boots.begin(), boots.end(), bsort);
    for (int x = 0; x < n; x++){
        used.insert(tiles[x]);
    }
    int maxdist = 1;
    int answers[b];
    /*cout << "\n\n";
    for (int x = 0; x < b; x++){
        cout << boots[x].second.first << " " << boots[x].second.second << "\n";
    }
    cout << "\n";*/
    while (boots.size() > 0){
        while(boots[boots.size() - 1].second.first < tiles[tiles.size() - 1].second){
            if (used.find(tiles[tiles.size() - 1]) == used.begin()){
                maxdist = max(maxdist, tiles[tiles.size() - 1].first - 1);
            }
            else if (used.find(tiles[tiles.size() - 1]) == --used.end()){
                maxdist = max(maxdist, n - tiles[tiles.size() - 1].first);
            }
            else{
                maxdist = max(maxdist, (*++used.find(tiles[tiles.size() - 1])).first - (*--used.find(tiles[tiles.size() - 1])).first);
            }
            used.erase(tiles[tiles.size() - 1]);
            tiles.pop_back();
        }
        if (boots[boots.size() - 1].second.second >= maxdist){
            answers[boots[boots.size() - 1].first] = 1;
        }
        else{
            answers[boots[boots.size() - 1].first] = 0;
        }
        boots.pop_back();
    }
    for (int x = 0; x < b; x++){
        out << answers[x] << "\n";
    }
}
