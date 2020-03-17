#include <fstream>
#include <string>
#include <iostream>
#include <math.h>
#include <algorithm>
#include <bits/stdc++.h>
using namespace std;
int n;

int groups[100001];
/*void rec(int cur, int num){
    if (!groups[cur]){
        groups[cur] = num;
        for (int x = 0; x < arr[cur].size(); x ++){
            rec(arr[cur][x], num);
        }
    }
}*/
int main() {
    ifstream in("planting.in");
    ofstream out("planting.out");
    in >> n;
    int one, two;
    vector<int> arr[n];
    for (int x = 0; x < n - 1; x ++){
        in >> one >> two;
        arr[one - 1].push_back(two - 1);
        arr[two - 1].push_back(one  - 1);
    }
    /*for (int x = 0; x < n; x ++){
        rec(x, x + 1);
    }
    sort(groups, groups+n);
     for (int x = 0; x < n; x ++){
        cout << groups[x];
    }*/
    int answer = 1;
     for (int x = 0; x < n - 1; x ++){

        if (arr[x].size() > answer - 1){
            answer = arr[x].size() + 1;
        }
    }
    out << answer << "\n";



}
