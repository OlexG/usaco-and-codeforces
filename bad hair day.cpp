#include <fstream>
#include <string>
#include <iostream>
#include <math.h>
#include <algorithm>
#include <vector>
using namespace std;
int n;
int arr[80000];

vector<pair<int, int>> curstack;
int main(){
    cin >> n;
    int answers[n];
    for (int x = 0; x < n; x++){
        cin >> arr[x];
        answers[x] = 0;
    }
    curstack.push_back(make_pair(arr[n - 1], n-1));
    for (int x = n - 2; x >= 0; x--){
        while (arr[x] > curstack[curstack.size() - 1].first && curstack.size() >= 1){
            answers[x] += answers[curstack[curstack.size() - 1].second];
            answers[x] += 1;
            curstack.pop_back();
        }
        curstack.push_back(make_pair(arr[x], x));
    }
    long long answer = 0;
    for (int x = 0; x < n; x++){
        answer += answers[x];
    }
    cout << answer;

}
