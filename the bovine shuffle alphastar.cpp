#include <fstream>
#include <string>
#include <iostream>
#include <math.h>
#include <algorithm>
#include <stdio.h>
#include <vector>
using namespace std;
int n;


int main(){
    cin >> n;
    int arr[n];
    int fr[n];
    for (int x = 0; x < n; x++){
        fr[x] = 1;
    }
    for (int x = 0; x < n; x++){
        cin >> arr[x];
        arr[x]--;
        fr[x]--;
        fr[arr[x]]++;
    }
    int answer = n;
    vector<int> q;
    for (int x = 0; x < n; x++){
        if (fr[x] == 0){
            answer--;
            q.push_back(arr[x]);
        }
    }
    while(q.size() > 0){
        int cur = fr[q[q.size() - 1]] - 1;
        fr[q[q.size() - 1]] = fr[q[q.size() - 1]] - 1;;
        int curindex = arr[q[q.size() - 1]];
        q.pop_back();
        if (cur == 0){
            answer--;
            q.push_back(curindex);
        }

    }
    getchar();
    cout << answer;
}
