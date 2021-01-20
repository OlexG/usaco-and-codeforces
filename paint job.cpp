#include <fstream>
#include <string>
#include <iostream>
#include <math.h>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
int a, b, n, p;
queue <pair<int , int>> q;
int main(){
    cin >> a >> b >> n >> p;
    int visited[p];
    int arr[n];
    for (int x = 0; x < p; x++){
        visited[x] = 1;
    }
    for (int x = 0; x < n; x++){
        cin >> arr[x];
    }
    q.push(make_pair(a, 0));
    int answer = -1;
    while (q.empty() == false){
        if (q.front().first == b){
            answer = q.front().second;
            break;
        }
        else{
            for (int x = 0; x < n; x++){
                int cur = (arr[x] * q.front().first) % p;
                if (visited[cur] == 1){
                    visited[cur] = 0;
                    q.push(make_pair(cur, q.front().second + 1));
                }
            }
            q.pop();
        }
    }
    cout << answer;

}


