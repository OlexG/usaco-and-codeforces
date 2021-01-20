#include <fstream>
#include <string>
#include <iostream>
#include <math.h>
#include <algorithm>
#include<bits/stdc++.h>
#include <vector>
using namespace std;


int n;

int arr[200001];
int gcd[1000001];

int main(){
    for (int x = 0; x <= 1000000; x++){
        gcd[x] = 0;
    }
    cin >> n;
    for (int x = 0; x < n; x++){
        cin >> arr[x];
    }
    for (int x = 0; x < n; x++){
        for (int y = 1; y * y < arr[x]; y++){
            if (arr[x] % y == 0){
                gcd[y]++;
                gcd[arr[x]/y]++;
            }
        }
    }
    int answer;
    for (int x = 1000000; x >= 1; x--){
        if (gcd[x] >= 2){
            answer = x;
            break;
        }
    }
    cout << answer << "\n";
}
