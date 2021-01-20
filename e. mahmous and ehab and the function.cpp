#include <fstream>
#include <string>
#include <iostream>
#include <math.h>
#include <algorithm>
#include<bits/stdc++.h>
#include <vector>
using namespace std;
struct query{
    long long a;
    long long b;
    long long c;
};
int n, m, q;
long long a[100000];
long long b[100000];
long long bsum[100000];
long long bdiff[100000];
multiset<long long> bset;
vector<query> queries;
int main(){
    cin >> n >> m >> q;
    for (int x = 0; x < n; x++){
        cin >> a[x];
    }
    for (int x = 0; x < m; x++){
        cin >> b[x];
    }
    query temp;
    temp.a = 0;
    temp.b = 0;
    temp.c = 0;
    queries.push_back(temp);
    for (int x = 0; x < q; x++){
        query temp;
        cin >> temp.a;
        cin >> temp.b;
        cin >> temp.c;
        queries.push_back(temp);
    }
    bsum[0] = b[0];
    if (m > 1){
        bsum[1] = b[1];
    }

    for (int x = 2; x < m; x ++){
        bsum[x] = bsum[x - 2] + b[x];
    }
    for (int x = 0; x <= m - n; x++){
        if (n % 2 == 0){
            if (x == 0){
                bset.insert(bsum[x + n - 2] - bsum[x + n - 1]);
            }
            else if (x == 1){
                bset.insert(bsum[x + n - 2] - (bsum[x + n - 1] - bsum[x - 1]));
            }
            else{
                bset.insert((bsum[x + n - 2] - bsum[x - 2])  - (bsum[x + n - 1] - bsum[x - 1]));
            }
        }
        else{
            if (x == 0){
                bset.insert(bsum[x + n - 1] - bsum[x + n - 2]);
            }
            else if (x == 1){
                bset.insert(bsum[x + n - 1] - (bsum[x + n - 2] - bsum[x - 1]));
            }
            else{
                bset.insert((bsum[x + n - 1] - bsum[x - 2])  - (bsum[x + n - 2] - bsum[x - 1]));
            }
        }
    }
    long long cursum = 0;
    for (int x = 0; x < n; x+=2){
        cursum += a[x];
    }
    for (int x = 1; x < n; x+=2){
        cursum -= a[x];
    }
    for (int x = 0; x < q + 1; x++){
        query cur = queries[x];
        if ((cur.a - cur.b) % 2 == 0){
            if (cur.a % 2 == 1){
                cursum += cur.c;
            }
            else{
                cursum -= cur.c;
            }
        }
        auto it = bset.upper_bound(cursum);
        if (it == bset.end()){
            it = prev(bset.end());
            if (*it > cursum){
                it = bset.begin();
            }
        }
        if (it == bset.begin()){
            cout << abs((*it) - cursum) << endl;
        }
        else{
            cout << min(abs((*it) - cursum), abs((*prev(it)) - cursum)) << endl;
        }
    }
}
