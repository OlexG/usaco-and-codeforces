#include <fstream>
#include <string>
#include <iostream>
#include <math.h>
#include <algorithm>
using namespace std;
#include <vector>
int n, m;
vector<pair<long long, long long>> cows;
long long arr[20000];
template<typename P> struct Cmp
{
    bool operator()(const P &p1, const P &p2)
    {
        return max(p1.first, p1.second) < max(p2.first, p2.second);
    }
};
int main(){
    ifstream in("helpcross.in");
    ofstream out("helpcross.out");
    in >> n >> m;
    for (int x = 0; x < n; x ++){
        in >> arr[x];
    }
    int first, second;
    for (int y = 0; y < m; y ++){
        in >> first >> second;
        cows.push_back(make_pair(first, second));
    }

    int answer = 0;
    sort(arr, arr + n);
    sort(cows.begin(), cows.end(), Cmp<pair<int, int> >());
    int cur = 0;
    bool notdone;
    for (int x = 0; x < n; x++){
        cur = 0;
        notdone = true;
        while(cur < m && notdone){
            if (arr[x] >= cows[cur].first && arr[x] <= cows[cur].second && cows[cur].first != -1){
                cows[cur].first = -1;
                notdone = false;
                answer++;
            }
            else{
                cur ++;
            }
        }
    }
    out << answer << "\n";



}
