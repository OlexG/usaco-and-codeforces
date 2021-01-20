#include <fstream>
#include <string>
#include <iostream>
#include <math.h>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
int n;
queue <pair<int, int>> q;
queue <int> dist;
int main(){
    cin >> n;
    bool notfound = true;
    int visited[n * 2 + 1];
    for (int x = 0; x < n * 2 + 1; x++){
        visited[x] = 1;
    }
    q.push(make_pair(1, 0));
    int answer = 0;
    while(q.empty() == false){
        if (q.front().first == n){
            answer = q.front().second;
            break;
        }
        else{
            int one = q.front().first * 3;
            int two = q.front().first + 1;
            int three = q.front().first - 1;
            int di = q.front().second + 1;
            if (one < n * 2 + 1){
                if (visited[one] == 1){
                    visited[one] = 0;
                    q.push(make_pair(one, di));
                }
            }
            if (two < n * 2 + 1 ){
                if (visited[two] == 1){
                    visited[two] = 0;
                    q.push(make_pair(two, di));
                }
            }
            if (three > 0){
                if (visited[three] == 1){
                    visited[three] = 0;
                    q.push(make_pair(three, di));
                }
            }
            q.pop();
        }
    }
    cout << answer;
}
