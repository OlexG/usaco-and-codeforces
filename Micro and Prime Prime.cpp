#include <fstream>
#include <string>
#include <iostream>
#include <math.h>
#include <algorithm>
#include<bits/stdc++.h>
#include <vector>
using namespace std;

int t;
int num[1000001];
int c[1000001];
int isprime[1000001];
int main(){

    isprime[2] = true;
    for (int x = 0; x < 1000001; x++){
        isprime[x] = true;
    }
    isprime[1] = false;
    isprime[0] = false;
    for (int x = 1; x <= 1000; x++){
        if (isprime[x]){
            for (int y = x * x; y <= 1000000; y+=x){
                isprime[y] = false;
            }
        }
    }
    num[0] = 0;
    c[0] = 0;
    for (int x = 1; x <= 1000000; x++){
        if (isprime[x]){
            c[x] = c[x - 1] + 1;
        }
        else{
            c[x] = c[x - 1];
        }
        if (isprime[c[x]]){
            num[x] = num[x - 1] + 1;
        }
        else{
            num[x] = num[x - 1];
        }
    }
    //cout << c[10] << "\n";
    cin >> t;
    int one, two;
    for (int x = 0; x < t; x++){
        cin >> one >> two;
        cout << num[two] - num[one - 1] << "\n";
    }
}
