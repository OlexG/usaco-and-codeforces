#include <fstream>
#include <string>
#include <iostream>
#include <math.h>
#include <algorithm>
#include<bits/stdc++.h>
#include <vector>
using namespace std;

int n;
long long fac(long long n){
    long long answer = 1;
    for (int x = 0; x < n; x++){
        answer *= (n - x);
    }
    return answer;
}
long long nck(long long n, long long k){
    return (fac(n)/(fac(k) * fac(n - k)));
}
int main(){
    cin >> n;

    long long answer  = 0;
    answer = nck(n, n/2);
    answer *= fac(n/2 - 1);
    answer *= fac(n/2 - 1);
    cout << answer/2 << "\n";
}
