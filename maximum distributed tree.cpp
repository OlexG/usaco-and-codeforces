#include <fstream>
#include <string>
#include <iostream>
#include <math.h>
#include <algorithm>
#include<bits/stdc++.h>
#include <vector>
using namespace std;
int t, n, m;
vector<long long> arr[200005];
vector<long long> order;
int used[200005];
void dfs(int x){
    used[x] = 2;
    for (int z = 0; z < arr[x].size(); z++){
        if (used[arr[x][z]] == 1){
            dfs(arr[x][z]);
        }
    }
    order.push_back(x);
}
int main(){
    cin >> t;
    for (int b = 0; b <t ; b++){
        cin >> n;
        pair<long long, long long> rightleft[n];
        order.clear();
        for (int x = 0; x < n; x++){
            used[x] = 1;
            arr[x].clear();
        }
        long long one, two;
        for (int x = 0; x < n - 1; x++){
            cin >> one >> two;
            arr[one - 1].push_back(two - 1);
            arr[two - 1].push_back(one - 1);
        }
        cin >> m;
        //prime nums
        vector<long long> primes;
        for (int x = 0; x < m; x++){
            cin >> one;
            primes.push_back(one);
        }
        sort(primes.rbegin(), primes.rend());
        vector<int> nprimes;
        if (m > n - 1){
            long long first = 1;
            for (int x = 0; x < m - n + 2; x++){
                //maybe modulo here
                first = first * primes[x] % 1000000007;;
            }
            nprimes.push_back(first);
            for (int x = m - n + 2; x < primes.size(); x++){
                nprimes.push_back(primes[x]);
            }
        }
        else{
            for (int x = 0; x < primes.size(); x++){
                nprimes.push_back(primes[x]);
            }
            for (int x = 0; x < n - 1 - m; x++){
                nprimes.push_back(1);
            }
        }
        dfs(0);
        /*for (int x = 0; x < n; x++){
            cout << order[x] << " ";
        }*/
        long long pos[n];
        for (int x = 0; x < n; x++){
            pos[order[x]] = x;
        }
        for (int x = 0; x < n - 1; x++){
            int cur = order[x];
            rightleft[cur].first = 1;
            for (int y = 0; y < arr[cur].size(); y++){
                if (pos[cur] > pos[arr[cur][y]]){
                    rightleft[cur].first += rightleft[arr[cur][y]].first;
                }
            }
            rightleft[cur].second = n - rightleft[cur].first;
        }
        vector<long long> totals;
        for (int x = 0; x < n - 1; x++){
            totals.push_back(rightleft[order[x]].first * rightleft[order[x]].second);
        }
        sort(totals.rbegin(), totals.rend());
        long long answer = 0;
        for (int x = 0; x < nprimes.size(); x++){
            answer = answer + (nprimes[x] * totals[x]) % 1000000007;
        }
        cout << answer % 1000000007 << "\n";
    }
}
