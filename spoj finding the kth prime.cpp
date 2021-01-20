#include <fstream>
#include <string>
#include <iostream>
#include <math.h>
#include <algorithm>
#include<bits/stdc++.h>
#include <vector>
using namespace std;


vector<int> primes;

int q;
bool isprime[90000000];
int main(){
    cin >> q;
    for (int x = 0; x < 90000000; x++){
        isprime[x] = true;
    }
    isprime[0] = false;
    isprime[1] = false;
    for (int x = 2; x * x < 900000000; x++){
        if (isprime[x]){
            for (int y = x * x; y < 90000000; y += x){
                isprime[y] = false;
            }
        }
    }
    for (int x = 0; x < 90000000; x++){
    	if (isprime[x]){
    		primes.push_back(x);
    	}
    }
    int temp;
    for (int x = 0; x < q; x++){
        cin >> temp;
        cout << primes[temp - 1] << "\n";
    }

}

