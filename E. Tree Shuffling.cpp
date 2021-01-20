#include <fstream>
#include <string>
#include <iostream>
#include <math.h>
#include <algorithm>
#include<bits/stdc++.h>
#include <vector>
using namespace std;

int n;
long long answer;
long long done[200001];
vector<long long> cons[200001];
long long wzeros[200001];
long long wones[200001];
long long hzeros[200001];
long long hones[200001];
long long used[200001];
long long pos[200001];
pair<long long, long long> prices[200001];
vector<long long> torder;
void tsort(long long cur){
    used[cur] = 1;
    for (int x = 0; x < cons[cur].size(); x++){
        if (used[cons[cur][x]] == 2){
            tsort(cons[cur][x]);
        }
    }
    torder.push_back(cur);
}

void solve(long long cur){
    done[cur] = 1;
    for (int x = 0; x < cons[cur].size(); x++){
        if (done[cons[cur][x]] == 2 && pos[cons[cur][x]] > pos[cur]){
            solve(cons[cur][x]);
        }
        if (pos[cons[cur][x]] > pos[cur]){
            wzeros[cur] += wzeros[cons[cur][x]];
            wones[cur] += wones[cons[cur][x]];
            hzeros[cur] += hzeros[cons[cur][x]];
            hones[cur] += hones[cons[cur][x]];
        }
    }
}
int main(){
    cin >> n;
    long long one, two, three;
    long long num0 = 0;
    long long num1 = 0;
    long long w0 = 0;
    long long w1 = 0;
    for (int x = 0; x < n; x++){
        cin >> one >> two >> three;
        prices[x] = make_pair(one, x);
        done[x] = 2;
        used[x] = 2;
        if (two == three){
            wzeros[x] = 0;
            wones[x] = 0;
            hones[x] = 0;
            hzeros[x] = 0;
        }
        else if (two == 1){
            w0++;
            num1++;
            wzeros[x] = 1;
            wones[x] = 0;
            hones[x] = 1;
            hzeros[x] = 0;
        }
        else{
            w1++;
            num0++;
            wzeros[x] = 0;
            wones[x] = 1;
            hones[x] = 0;
            hzeros[x] = 1;
        }
    }

    for (int x = 0; x < n - 1; x++){
        cin >> one >> two;
        cons[one - 1].push_back(two - 1);
        cons[two - 1].push_back(one - 1);
    }
    if (num1 != w1 || w0 != num0){
        cout << -1 << "\n";
        return 0;
    }
    tsort(0);
    reverse(torder.begin(), torder.end());
    sort(prices, prices + n);
    for (int x = 0; x < torder.size(); x++){
        pos[torder[x]] = x;
        //cout << torder[x] << "\n";
    }
    for (int x = 0; x < n; x++){
        if (done[prices[x].second] == 2){
            solve(prices[x].second);
            answer += prices[x].first * min(wzeros[prices[x].second], hzeros[prices[x].second]);
            answer += prices[x].first * min(wones[prices[x].second], hones[prices[x].second]);
            //cout << wzeros[prices[x].second] << " " << wones[prices[x].second] << " " << hzeros[prices[x].second] << " " << hones[prices[x].second] << "\n";
            long long uzeros = min(wzeros[prices[x].second], hzeros[prices[x].second]);
            long long uones = min(wones[prices[x].second], hones[prices[x].second]);
            wzeros[prices[x].second] -= uzeros;
            hzeros[prices[x].second] -= uzeros;
            wones[prices[x].second] -= uones;
            hones[prices[x].second] -= uones;
        }
    }
    cout << answer << "\n";



}
