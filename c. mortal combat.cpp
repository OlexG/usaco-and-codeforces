#include <fstream>
#include <string>
#include <iostream>
#include <math.h>
#include <algorithm>
#include<bits/stdc++.h>
#include <vector>
using namespace std;

int t, n;

int main(){
    cin >> t;
    for (int z = 0; z < t; z++){
        int n;
        cin >> n;

        int arr[n];
        for (int x = 0; x < n; x++){
            cin >> arr[x];
        }
        int answer = 0;
        int s = 0;
        int start = true;
        for (int x = 0; x < n; x++){
            if (arr[x] == 0 || x == n - 1){
                if (x == 0 && arr[x] == 0){
                    start = false;
                }
                if (x == n - 1 && arr[x] == 1){
                    s++;
                }
                if (start){
                    answer += ((s - 1)/3 + 1);
                }
                else{
                    answer += (s/3);
                }
                s = 0;
                start = false;
            }
            else{
                s++;
            }
        }
        cout << answer << "\n";
    }
}
