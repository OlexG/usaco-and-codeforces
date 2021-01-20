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
    string s;
    int arr[n];
    cin >> s;
    for (int x = 0; x < n; x++){
        arr[x] = 0;
    }
    long long ccounter = 0;
    for (int x = 0; x < n; x++){
        if (s[x] == 'C'){
            ccounter++;
        }
        if (s[x] == 'O'){
            arr[x] = ccounter;
        }
    }
    long long ocounter = 0;
    for (int x = 0; x < n; x++){
        if (s[x] == 'O'){
            ocounter += arr[x];
        }
        if (s[x] == 'W'){
            arr[x] = ocounter;
        }
    }
    long long answer = 0;
    for (int x = 0; x < n; x++){
        if (s[x] == 'W'){
            answer += arr[x];
        }
    }
    cout << answer;
}
