#include <fstream>
#include <string>
#include <iostream>
#include <math.h>
#include <algorithm>
#include<bits/stdc++.h>
#include <vector>
using namespace std;

int n;
set<int> curcards;
int used[100002];
vector<int> bes;
int main(){
    cin >> n;
    int one;
    for (int x = 1; x <= 2 * n; x++){
        used[x] = 2;
    }
    for (int x = 0; x < n; x++){
        cin >> one;
        bes.push_back(one);
        used[one] = 1;
    }
    for (int x = 0; x < n; x++){

    }
}
