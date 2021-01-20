/*
ID: alex.go2
LANG: C++11
PROB: holstein
*/
#include <fstream>
#include <string>
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;


int v, g;
int arr[15][25];
int needed[25];
int curnums[25];

bool valid(){
    for (int x = 0; x < v; x++){
        if (curnums[x] < needed[x]){
            return false;
        }
    }
    return true;
}
vector<int> pos;
vector<int> cur;
void rec(int which){
    if (valid() && cur.size() < pos.size()){
        pos = cur;
    }
    else if (which < g){
        for (int x = 0; x < v; x++){
            curnums[x] += arr[which][x];
        }
        cur.push_back(which);
        rec(which + 1);
        for (int x = 0; x < v; x++){
            curnums[x] -= arr[which][x];
        }
        cur.pop_back();
        rec(which + 1);

    }
}
int main(){
    ifstream in("holstein.in");
    ofstream out("holstein.out");
    in >> v;
    for (int x = 0; x < v; x++){
        in >> needed[x];
        curnums[x] = 0;
    }
     cout << "worked so far";
    in >> g;

    for (int x = 0; x < g; x++){

        pos.push_back(x);
        for (int y = 0; y < v; y++){
            in >> arr[x][y];
        }
    }
    vector<int> temp;
    rec(0);


    sort(pos.begin(), pos.end());
    out << pos.size() << " ";
    for (int x = 0; x < pos.size(); x++){
        out << pos[x] + 1;
        if (x < pos.size() - 1){
            out << " ";
        }
    }
    out << "\n";
}
