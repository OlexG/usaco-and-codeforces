#pragma GCC optimize("O2")
#include <fstream>
#include <string>
#include <iostream>
#include <bitset>
#include <math.h>
#include <string>
#include <algorithm>
#include <assert.h>
#include<bits/stdc++.h>
#include <vector>
#include <queue>
#include<stdio.h>
#include<ctype.h>
#define ll long long
using namespace std;

vector<int> faces;
vector<int> cnts;

int n;

vector<pair<int, int>> arr;

int one, two;
int main(){
    cin >> n;
    for (int x = 0; x < n; x++){
        cin >> one >> two;
        arr.push_back({one, two});
    }
    sort(arr.rbegin(), arr.rend());
    int answer = 1;
    for (int x = 0; x < n; x++){
        int pos = lower_bound(faces.begin(), faces.end(), arr[x].second) - faces.begin();
        if (pos == faces.size()){
            faces.push_back(arr[x].second);
            cnts.push_back(1);
        }
        else{
            faces[pos] = arr[x].second;
            cnts[pos] += 1;
            answer = max(answer, cnts[pos]);
        }
    }
    cout << faces.size() << "\n";
}
