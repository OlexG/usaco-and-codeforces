#include <fstream>
#include <string>
#include <iostream>
#include <math.h>
#include <algorithm>
#include<bits/stdc++.h>
#include <vector>
using namespace std;

int n, k;
vector<int> arr;
int main(){
    ifstream in("berries.in");
    ofstream out("berries.out");
    in >> n >> k;
    int temp;
    for (int x = 0; x < n; x++){
        in >> temp;
        arr.push_back(temp);
    }
    sort(arr.begin(), arr.end());
    int answer = 0;
    for (int b = 0; b < 1000; b++){
        bool works = true;
        vector<int> c;
        for (int x = 0; x < n; x++){
            c.push_back(arr[x]);
        }

        for (int x = n - 1; x >= n - k/2; x--){
            if (n - k/2 < 0){
                works = false;
                break;
            }
            if (c[x] < b){
                works = false;
                break;
            }
            else{
                c[x] -= b;
            }
        }
        sort(c.begin(), c.end());
        if (works){
            int curanswer = 0;
            for (int x = n; x >= max(0, n - k/2); x--){
                curanswer += min(b, c[x]);
            }
            answer = max(answer, curanswer);
        }
    }
    out << answer << "\n";
}
