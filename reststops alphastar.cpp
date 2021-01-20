#include <fstream>
#include <string>
#include <iostream>
#include <math.h>
#include <algorithm>
#include <vector>
using namespace std;
long long l, n, rf, rb;

int main(){
    cin >> l >> n >> rf >> rb;
    pair<long long,long long> arr[n];
    long long one, two;
    for (int x = 0; x < n; x++){
        cin >> one >> two;
        arr[x] = make_pair(one, two);
    }
    sort(arr, arr + n);
    vector<pair<long long, long long>> needtovisit;
    needtovisit.push_back(arr[n - 1]);
    int m = arr[n - 1].second;
    for (int x = n - 2; x >= 0; x--){
        if (arr[x].second > m){
            m = arr[x].second;
            needtovisit.push_back(arr[x]);
        }
    }
    sort(needtovisit.begin(), needtovisit.end());
    long long cur = 0;
    long long answer = 0;
    for (int x = 0; x < needtovisit.size(); x++){
        long long time = (needtovisit[x].first - cur) * rf - (needtovisit[x].first - cur) * rb;
        answer += time * needtovisit[x].second;
        cur = needtovisit[x].first;
    }
    cout << answer;

}
