#include <fstream>
#include <string>
#include <iostream>
#include <math.h>
#include <algorithm>
#include<bits/stdc++.h>
#include <vector>
using namespace std;


int t;

int main(){
    cin >> t;
    for (int z = 0; z < t; z++){
        int n;
        cin >> n;
        int arr[n];
        for (int x = 0; x < n; x++){
            cin >> arr[x];
        }
        vector<int> inc;
        int c = 0;
        inc.push_back(1);

        for (int x = 1; x < n; x++){
            if (arr[x] > arr[x - 1]){
                c++;
            }
            if (arr[x] < arr[x - 1] || x == n - 1){
                inc.push_back(c);
                c = 1;
            }
            if (x == n - 1 && arr[x] < arr[x - 1]){
                inc.push_back(1);
            }
        }
        int nc = 0;
        int curc = 1;
        int answer = 0;
        for (int x = 1; x < inc.size(); x++){
            curc--;
            nc += inc[x];
            if (curc == 0){
                answer++;
                curc = nc;
                nc = 0;
            }
            if (x == inc.size() - 1){
                if (nc != 0){
                    answer++;
                }
            }
        }
        cout << answer << "\n";
    }
}
