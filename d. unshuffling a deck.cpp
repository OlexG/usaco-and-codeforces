#include <fstream>
#include <string>
#include <iostream>
#include <math.h>
#include <algorithm>
#include<bits/stdc++.h>
#include <vector>
using namespace std;

struct interval{
    int s, a, b;
};
bool csort(interval a, interval b){
    return a.s < b.s;
}
int n;
int arr[52];
int main(){
    cin >> n;
    for (int x = 0; x < n; x++){
        cin >> arr[x];
    }
    vector<vector<int>> answers;
    while(true){
        vector<interval> invs;
        int counter = 0;
        bool nf = true;
        for (int x = 0; x < n; x++){
            if (x == n - 1){
                invs.push_back({arr[x - counter], x - counter, x});
                nf = false;
                counter = 0;
            }
            else{
                if (arr[x + 1] != arr[x] + 1){
                    invs.push_back({arr[x - counter], x - counter, x});
                    nf = false;
                    counter = 0;
                }
            }
            if (nf){
                counter++;
            }
            else{
                nf = true;
            }
        }
        if (invs.size() == 1){
            break;
        }
        int labels[invs.size()];
        vector<interval> cp;
        for (int x = 0; x < invs.size(); x++){
            cp.push_back(invs[x]);
        }
        sort(cp.begin(), cp.end(), csort);
        for (int x = 0; x < invs.size(); x++){
            for (int y = 0; y < invs.size(); y++){
                if (invs[x].s == cp[y].s){
                    labels[x] = y;
                }
            }
        }

        if (labels[0] != 0){
            for (int x = 0; x < invs.size(); x++){
                if (labels[x] == labels[0] - 1){
                    vector<int> temp{invs[x].a, invs[x].b - invs[x].a + 1, n - invs[x].b - 1};
                    if (n - invs[x].b - 1 == 0){
                        temp.pop_back();
                    }
                    answers.push_back(temp);
                }
            }
        }
        else{
            for (int x = 1; x < invs.size(); x++){
                if (labels[x] == labels[1] - 1){
                    vector<int> temp{invs[0].b + 1, invs[x].a - invs[1].a, invs[x].b - invs[x].a + 1, n - invs[x].b - 1};
                    if (n - invs[x].b - 1 == 0){
                        temp.pop_back();
                    }
                    answers.push_back(temp);
                }
            }
        }
        int narr[n];
        int p1 = n;
        int p2 = 0;
        for (int x = 0; x < answers[answers.size() - 1].size(); x++){
            p1 = p1 - answers[answers.size() - 1][x];
            for (int y = 0; y < answers[answers.size() - 1][x]; y++){
                narr[p1] = arr[p2];
                p1++;
                p2++;
            }
            p1 = p1 - answers[answers.size() - 1][x];
        }
        for (int x = 0; x < n; x++){
            arr[x] = narr[x];
        }
    }
    cout << answers.size() << "\n";
    for (int x = 0; x < answers.size(); x++){
        cout << answers[x].size() << " ";
        for (int y = 0; y < answers[x].size(); y++){
            cout << answers[x][y] << " ";
        }
        cout << "\n";
    }
}
