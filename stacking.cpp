#include <fstream>
#include <string>
#include <iostream>
#include <math.h>
#include <algorithm>
#include<bits/stdc++.h>
#include <vector>
using namespace std;
long long n, m;
int main(){
    ifstream in("in.txt");

    //ofstream out("meetings.out");
    in >> n >> m;
    vector<int> arr;
    vector<int> mark;

    for (int x = 0; x < n + 1; x++){
        arr.push_back(0);
    }
    for (int x = 0; x < n + 1; x++){
        mark.push_back(0);
    }

    int one, two;
    for (int x = 0; x < m; x++){
        in >> one >> two;
        mark[one - 1] ++;
        mark[two] --;
    }
    int cur = 0;
    for (int x = 0; x < n; x++){
        cur += mark[x];
        arr[x] = cur;
    }
    sort(arr.begin(), arr.end());
    cout << arr[n/2] << "\n";

}
