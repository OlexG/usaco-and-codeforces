#include <fstream>
#include <string>
#include <iostream>
#include <math.h>
#include <algorithm>
#include<bits/stdc++.h>
#include <vector>
using namespace std;
int n;
set<long long> sums;
int main(){
    long long cursum = 0;
    cin >> n;
    long long temp = 0;
    int answer = 0;
    sums.insert(0);
    for (int x = 0; x < n; x++){
        cin >> temp;
        cursum += temp;
        if (sums.find(cursum) == sums.end()){
            sums.insert(cursum);
        }
        else{
            answer++;
            sums.clear();
            sums.insert(0);
            sums.insert(temp);
            cursum = temp;
        }
    }
    cout << answer << "\n";
}
