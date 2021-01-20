#pragma GCC optimize("O2")
#include <fstream>
#include <string>
#include <iostream>
#include <bitset>
#include <math.h>
#include <string>
#include <algorithm>
#include<bits/stdc++.h>
#include <vector>
using namespace std;

long long n;

struct Time
{
    long long start;
    long long finish;
    long long y;
};

Time times[500001];
bool csort(Time a, Time b){
    return a.y < b.y;
}
int main(){
    ifstream in("stampede.in");
    ofstream out("stampede.out");
    in >> n;
    long long a, b, c;

    for (int x = 0; x < n; x++){
        in >> a >> b >> c;
        Time n;
        n.start = (a + 1) * c * -1;
        n.finish = (a) * c * -1;
        n.y = b;
        times[x] = n;
    }
    multiset<pair<long long, long long>> past;
    int answer = 1;
    sort(times, times + n, csort);

    past.insert(make_pair(times[0].start, times[0].finish));

    for (int x = 1; x < n; x++){
        pair<long long, long long> cur = make_pair(times[x].start, times[x].finish);
        bool st = false;
        auto it = past.upper_bound(make_pair(cur.first, 1000000000000));
        if (it == past.end()){
            if ((*(prev(it))).second < cur.first){
                past.insert(cur);
                answer++;
                continue;
            }
        }
        if (it == past.begin()){
            if ((*(it)).first > cur.second){
                past.insert(cur);
                answer++;
                continue;
            }
            else{
                st = true;
            }
        }
        else{
            it = prev(it);
        }
        pair<long long, long long> start = *(it);
        if (start.first <= cur.first && start.second >= cur.second){
            continue;
        }
        answer++;
        long long nstart;
        long long nfinish;
        auto sit = it;
        if (cur.first > start.second){
            nstart = cur.first;
            nfinish = cur.second;
            cout << "yes\n";
            sit = next(it, 1);
        }
        else{
            nstart = start.first;
            nfinish = max(cur.second, start.second);
        }
        if (st){
            nstart = cur.first;
        }
        auto fit = past.end();
        while(true){
            it = next(it, 1);
            if (it == past.end()){
                break;
            }
            pair<int, int> next = *(it);
            if (nfinish < next.first){
                break;
            }
            else if (nfinish > next.second){
                fit = it;
            }
            else if (nfinish <= next.second){
                nfinish = next.second;
                fit = it;
                break;
            }
        }
        if (fit != past.end()){
            past.erase(sit, next(fit));
        }
        else{
            pair<int, int> cur = *(sit);
            if (cur.second > nstart && cur.first < nfinish){
                past.erase(sit);
            }
        }
        past.insert(make_pair(nstart, nfinish));
    }
    out << answer << "\n";

}
