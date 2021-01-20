#include <fstream>
#include <string>
#include <iostream>
#include <math.h>
#include <algorithm>
#include<bits/stdc++.h>
#include <vector>
using namespace std;
int n, p;

int main(){
    cin >> n >> p;
    vector<int> arr;
    int temp;
    int m = 0;
    for (int x = 0; x < n;x++){
        cin >> temp;
        arr.push_back(temp);
        m = max(m, temp);
    }
    sort(arr.begin(), arr.end());

    vector<int> answer;
    for (int x = 0; x <= m; x++){
        vector<int> perms;
        int combs[n];
        for (int y = 0; y < n; y++){
            perms.push_back(x + y);
            combs[y] = 0;
        }

        int counter1 = 0;
        int counter2 = 0;
        while(counter1 < n && counter2 < n){
            if (arr[counter1] <= perms[counter2]){
                combs[counter2] ++;
                counter1++;
            }
            else{
                counter2++;
                if (counter2 < n){
                    combs[counter2] = combs[counter2 - 1];
                }
            }
        }
        for (int y = counter2 + 1; y < n; y++){
            combs[y] = combs[y - 1];
        }
        for (int y = 0; y < n; y++){
            combs[y] = max(0, combs[y] - y);
        }
        int works = true;
        for (int y = 0; y < n; y++){
            if (combs[y] % p == 0){
                works = false;
                break;
            }
        }
        if (works){
            answer.push_back(x);
        }
    }
    cout << answer.size() << "\n";
    for (int x = 0; x < answer.size(); x++){
        cout << answer[x] << " ";
    }
    cout << "\n";
}
