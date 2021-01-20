#include <fstream>
#include <string>
#include <iostream>
#include <math.h>
#include <algorithm>
#include<bits/stdc++.h>
#include <vector>
using namespace std;

int x, n;
multiset<long long> divs;

int main(){
    cin >> x >> n;
    long long temp;
    for (int x = 0; x < n; x++){
        cin >> temp;
        divs.insert(temp);
    }
    long long answer = 0;
    while(divs.size() > 1){
        long long newone = *divs.begin() + *next(divs.begin(),1);
        divs.erase(divs.begin(), next(divs.begin(),2));
        answer += newone;
        divs.insert(newone);
    }
    cout << answer << "\n";

}
