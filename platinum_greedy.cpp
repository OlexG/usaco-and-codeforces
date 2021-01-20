#include <fstream>
#include <string>
#include <iostream>
#include <math.h>
#include <algorithm>
#include<bits/stdc++.h>
#include <vector>
using namespace std;

int n;
int arr[100000];
int ok(int index){
    vector<int> cs;
    for (int x = 0; x <= index; x++){
        cs.push_back(arr[x]);
    }
    sort(cs.rbegin(), cs.rend());
    for (int x = 0; x < cs.size(); x++){
        if (n - cs[x] - 1 < x + 1){
            //cout << x << " " << cs[x] << "\n";
            return true;
        }
    }
    return false;
}
int main(){
    ifstream in("greedy.in");
    ofstream out("greedy.out");
    in >> n;
    for (int x = 0; x < n; x++){
        in >> arr[x];
    }
    int mi = 0;
    int ma = n - 1;
    while(mi < ma){
        int cur = (mi + ma)/2;
        if (ok(cur)){
            ma = cur;
        }
        else{
            mi = cur + 1;
        }
    }
    out << n - ma - 1 << "\n";
}
