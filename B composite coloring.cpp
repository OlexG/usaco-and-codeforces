#include <fstream>
#include <string>
#include <iostream>
#include <math.h>
#include <algorithm>
#include<bits/stdc++.h>
#include <vector>
using namespace std;


int t;
int n;
bool isprime(int n){
    if (n < 2){
        return false;
    }
    if (n == 2){
        return true;
    }
    for (int x = 2; x <= sqrt(n); x++){
        if (n % x == 0){
            return false;
        }
    }
    return true;
}
int main(){
    cin >> t;
    for (int z = 0 ;z < t; z++){
        cin >> n;
        int arr[n];
        int colors[n];
        for (int x = 0; x < n; x++){
            cin >> arr[x];
            colors[x] = -1;
        }
        vector<int> primes;
        for (int x = 0; x < 37; x++){
            if (isprime(x)){
                primes.push_back(x);
            }
        }
        int counter = 1;
        for (int y = 0; y < primes.size(); y++){
            bool f = false;
            for (int x = 0; x < n; x++){
                if (arr[x] % primes[y] == 0 && colors[x] == -1){
                    f = true;
                    colors[x] = counter;
                }
            }
            if (f){
                counter++;
            }
        }
        cout << counter - 1 << "\n";
        for (int x = 0; x < n; x++){
            cout << colors[x] << " ";
        }
    }
}
