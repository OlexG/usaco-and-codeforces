#include <fstream>
#include <string>
#include <iostream>
#include <math.h>
#include <algorithm>
#include <vector>
#include <set>
using namespace std;

int t, n;
int arr[100000];
vector<pair<int, int>> check;
int cnt[100005];
bool ok(vector<pair<int, int>> check, int interval){
    int arr[n];
    set<pair<int, int>, greater<pair<int, int>>> ss;
    vector<int> b;
    for (int x = 0; x < check.size(); x++){
        cnt[check[x].second] = check[x].first;
        ss.insert(check[x]);
    }
    for (int x = 0; x < n; x++){
        if (x >= interval){
            if (cnt[b[x - interval]] > 0){
                ss.insert({cnt[b[x - interval]], b[x - interval]});
            }
        }
        if (ss.size() == 0){
            return false;
        }
        b.push_back(ss.begin() -> second);
        cnt[ss.begin() -> second]--;
        ss.erase(ss.begin());

    }
    return true;
}
int main(){
    cin >> t;
    for (int m = 0; m < t; m++){
        cin >> n;
        check.clear();
        for (int x = 0; x < n; x++){
            arr[x] = 0;
        }
        int temp;
        for (int x = 0; x < n; x++){
            cin >> temp;
            arr[temp - 1] = arr[temp - 1] + 1;
        }
        for (int x = 0; x < n; x++){
            if (arr[x] > 0){
                check.push_back(make_pair(arr[x], x + 1));
            }
        }
        sort(check.rbegin(), check.rend());
        int top = n;
        int bottom = 0;
        int middle;
        while(bottom < top){
            int middle = (top + bottom)/2 + 1;
            //cout << middle << "\n";
            if (ok(check, middle)){
                bottom = middle;
            }
            else{
                top = middle - 1;
            }
        }
        cout << bottom - 1 << "\n";

    }
}
