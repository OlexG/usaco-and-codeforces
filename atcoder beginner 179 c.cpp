#include <fstream>
#include <string>
#include <iostream>
#include <math.h>
#include <algorithm>
#include<bits/stdc++.h>
#include <vector>
using namespace std;

int n;

int main(){
    cin >> n;
    int answer = 0;
    for (int x = 1; x <= n - 1; x++){
        if (n % x == 0){
            answer += (n/x - 1);
        }
        else{
            answer += n/x;
        }
    }
    cout << answer << "\n";
}
