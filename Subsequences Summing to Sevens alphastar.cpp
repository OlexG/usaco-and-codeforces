#include <fstream>
#include <string>
#include <iostream>
#include <math.h>
#include <algorithm>
#include <vector>
using namespace std;
int n;
int arr[50000];
pair<int,int> intervals[50000];
int main(){
    cin >> n;
    for (int x = 0; x < n; x++){
        cin >> arr[x];
    }
    arr[0] = arr[0] % 7;

    for (int x = 1; x < n; x++){
        arr[x] = (arr[x] + arr[x - 1]) % 7;

    }
    for (int x = 0; x < n; x++){
        intervals[x].first = -1;
    }
    for (int x = 0; x < n; x++){
        if (intervals[arr[x]].first == -1){
            intervals[arr[x]].first = x;
        }
        else{
            intervals[arr[x]].second = x;
        }
    }

    int answer = 0;
    for (int x = 0; x < n; x++){
        if (intervals[x].first != - 1){
            answer = max(answer, intervals[x].second - intervals[x].first);
        }
    }
    cout << answer;

}
