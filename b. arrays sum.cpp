#include <fstream>
#include <string>
#include <iostream>
#include <math.h>
#include <algorithm>
#include<bits/stdc++.h>
#include <vector>
using namespace std;

int t;
int n, k;
int main(){
    cin >> t;
    for (int z = 0; z < t; z++){
        cin >> n >> k;
        int arr[n];
        for (int x = 0; x < n; x++){
            cin >> arr[x];
        }
        int c = 0;
        for (int x = 1; x < n; x++){
            if (arr[x - 1] != arr[x]){
                c++;
            }
        }
        int answer = 0;
        if (c + 1 == k){
            answer = 1;
        }
        else if (k == 1){
            answer = -1;
        }
        else{
            answer = (c + k-2)/(k - 1);
        }
        if (answer == 0){
            answer = 1;
        }
        cout << answer << "\n";
    }
}
