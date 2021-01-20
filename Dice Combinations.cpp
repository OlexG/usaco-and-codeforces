#include <fstream>
#include <string>
#include <iostream>
#include <math.h>
#include <algorithm>
#include<bits/stdc++.h>
#include <vector>
using namespace std;


int n;
int mod = 1000000007;
int numofways[1000001];

int main(){
    cin >> n;
    for (int x = 0; x <= n; x++){
        numofways[x] = 0;
    }
    numofways[0] = 1;
    for (int x = 0; x <= n; x++){
        for (int y = 1; y <= 6; y++){
            if (x - y >= 0){
                numofways[x] += numofways[x - y];
                numofways[x] %= mod;
            }
        }
    }
    cout << numofways[n] << "\n";
}
