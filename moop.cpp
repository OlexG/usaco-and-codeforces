#include <fstream>
#include <string>
#include <iostream>
#include <math.h>
#include <algorithm>
#include <bits/stdc++.h>
using namespace std;

int n;
bool srt(pair<int, int> a, pair<int, int> b){
    if (a.first == b.first){
        return a.second < b.second;
    }
    else{
        return a.first < b.first;
    }
}
int main(){
    ifstream in("moop.in");
    ofstream out("moop.out");
    in >> n;
    pair<int, int> arr[n];
    int answer = 1;
    int one, two;
    for (int x = 0; x < n; x++){
        in >> one >> two;
        arr[x] = make_pair(one, two);
    }
    sort(arr, arr + n, srt);

    int lowest[n];
    for (int x = 0; x < n; x++){
        if (x == 0){
            lowest[x] = arr[x].second;
        }
        else{
            lowest[x] = min(lowest[x - 1], arr[x].second);
        }
    }
    int highest[n];
    for (int x = n - 1; x >= 0; x--){
        if (x == n - 1){
            highest[x] = arr[x].second;
        }
        else{
            highest[x] = max(highest[x + 1], arr[x].second);
        }
    }
    for (int x = 0; x < n - 1; x++){
        if (lowest[x] > highest[x + 1]){
            answer++;
        }
    }
    out << answer << "\n";



}
