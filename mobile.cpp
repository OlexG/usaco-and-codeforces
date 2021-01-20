#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#define fast ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#include<bits/stdc++.h>
using namespace std;

long long n, l;
pair<int, int> points[1000000];

bool ok(double cur){
    double curmaxx = 0;
    for (long long x = 0; x < n; ++x){
        long long curx = points[x].first;
        long long cury = abs(points[x].second);
        if (cur >= cury){
            double xintervals = sqrt(cur * cur - cury * cury);
            double minx = curx - xintervals;
            double maxx = curx + xintervals;
            if (minx <= l && maxx >= 0 && cur >= cury){
                if (minx <= curmaxx){
                    curmaxx = max(curmaxx, maxx);
                    if ((curmaxx) >= l){
                        return true;
                    }
                }
            }
        }
    }
    return curmaxx >= l;
}
int main(){
    long long one, two;
    cin >> n >> l;
    for (int x = 0; x < n; ++x){
        cin >> one >> two;
        points[x] = make_pair(one, two);
    }
    double mi = 0.0;
    double ma = 10000000000;
    //cout << ok(658);
    while(ma > mi + 0.001){
        double cur = (mi + ma) / 2.0;
        if (ok(cur)){
            ma = cur;
        }
        else{
            mi = cur;
        }
    }
    printf("%.15g", ma);
}
