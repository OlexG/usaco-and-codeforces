#include <fstream>
#include <string>
#include <iostream>
#include <math.h>
#include <algorithm>
#include <vector>
using namespace std;


int n;

int main(){
    cin >> n;
    long long arr[n];
    long long pref[n];
    long long suf[n];
    for (int x = 0; x < n; x++){
        cin >> arr[x];
    }
    pref[0] = arr[0];
    pref[1] = arr[1];
    suf[n - 1] = arr[n - 1];
    suf[n - 2] = arr[n - 2];
    for (int x = 2; x < n; x++){
        pref[x] = arr[x] + pref[x - 2];
    }
    for (int x = n - 3; x >= 0; x--){
        suf[x] = arr[x] + suf[x + 2];
    }
    long long answer = 0;
    for (int x = 0; x < n; x++){
        if (x == 0){
            answer = max(answer, suf[x]);
        }
        else {
            answer = max(answer, suf[x] + pref[x - 1]);
        }
    }
    cout << answer << "\n";
}
