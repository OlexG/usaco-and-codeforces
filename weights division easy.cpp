#include <fstream>
#include <string>
#include <iostream>
#include <math.h>
#include <algorithm>
#include <vector>
#include <set>
#include <queue>
using namespace std;

long long t, n, s;
vector<pair<long long, long long>> arr[200005];
long long cnt[200005];
long long weight[200005];
vector<long long> order;
long long used[200000];
void dfs(int x){
    used[x] = 2;
    if (arr[x].size() == 1){
        weight[x] = arr[x][0].second;
        cnt[x] = 1;
    }
    for (int z = 0; z < arr[x].size(); z++){
        if (used[arr[x][z].first] == 1){
            dfs(arr[x][z].first);
            weight[arr[x][z].first] = arr[x][z].second;
            cnt[x] += cnt[arr[x][z].first];
        }
    }
}
int main(){
    cin >> t;
    for (int z = 0; z < t; z++){
        cin >> n >> s;
        long long one, two, three;
        for (int x = 0; x < n; x++){
            arr[x].clear();
            used[x] = 1;
            cnt[x] = 0;
        }
        order.clear();
        for (int x = 0; x < n - 1; x++){
            cin >> one >> two >> three;
            arr[one - 1].push_back(make_pair(two - 1, three));
            arr[two - 1].push_back(make_pair(one - 1, three));
        }
        dfs(0);
        priority_queue<pair<long long ,pair<long long , long long>>> q;
        long long t = 0;
        for (int x = 1; x < n; x++){
            q.push(make_pair((weight[x] - floor((weight[x])/2)) * cnt[x] , make_pair(weight[x], x)));
            t += cnt[x] * weight[x];
        }
        long long moves = 0;
        while(t > s){
            //cout << t << "\n";
            auto cur = q.top();
            q.pop();
            t -= cur.first;
            cur.second.first = floor(cur.second.first/2);
            cur.first = (cur.second.first - floor((cur.second.first)/2)) * cnt[cur.second.second];
            q.push(cur);
            moves++;
        }
        cout << moves << "\n";
    }

}
