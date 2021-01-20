#include <fstream>
#include <string>
#include <iostream>
#include <math.h>
#include <algorithm>
#include<bits/stdc++.h>
#include <vector>
using namespace std;


int n;
string s;
int perm[200001];
long long answer = 0;
vector<int> start;
vector<int> ending;
vector<int> fin;
void merges(int p1, int p2){
    if (p1 >= p2){
        return;
    }
    else{
        merges(p1, (p1 + p2)/2);
        merges((p1 + p2)/2 + 1, p2);
    }
    start.clear();
    ending.clear();
    fin.clear();
    for (int x = p1; x <= (p1 + p2)/2; x++){
        start.push_back(perm[x]);
    }
    for (int x = (p1 + p2)/2 + 1; x <= p2; x++){
        ending.push_back(perm[x]);
    }
    int s1 = 0;
    int s2 = 0;
    while(s1 < start.size() || s2 < ending.size()){
        if (s1 >= start.size()){
            fin.push_back(ending[s2]);
            s2++;
        }
        else if (s2 >= ending.size()){
            fin.push_back(start[s1]);
            s1++;
        }
        else{
            if (start[s1] <= ending[s2]){
                fin.push_back(start[s1]);
                s1++;
            }
            else{
                answer += start.size() - s1;
                fin.push_back(ending[s2]);
                s2++;
            }
        }
    }
    for (int x = p1; x <= p2; x++){
        perm[x] = fin[x - p1];
    }
}
int main(){
    cin >> n;
    cin >> s;
    string rev = "";
    vector<int> arr[100];
    for (int x = n - 1; x >= 0; x--){
        rev += s[x];
        int ind = s[x] - '0';
        arr[ind].push_back(x);
    }
    for (int x = 0; x < n; x++){
        perm[arr[rev[x] - '0'][arr[rev[x] - '0'].size() - 1]] = x;
        int ind = rev[x] - '0';
        arr[ind].pop_back();
    }
    merges(0, n - 1);
    cout << answer << "\n";

}
