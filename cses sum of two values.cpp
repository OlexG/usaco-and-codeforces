#include <fstream>
#include <string>
#include <iostream>
#include <math.h>
#include <algorithm>
#include<bits/stdc++.h>
#include <vector>
using namespace std;

long long n, c;

int main(){
    cin >> n >> c;
    pair<int, int> arr[n];
    int temp;
    for (int x = 0; x < n; x++){
        cin >> temp;
        arr[x] = make_pair(temp, x);
    }
    sort(arr, arr + n);
    int point1 = 0;
    int point2 = n - 1;
    while(point1 < point2){
        if (arr[point1].first + arr[point2].first == c){
            cout << arr[point1].second + 1 << " " << arr[point2].second + 1 << "\n";
            break;
        }
        else{
            if (arr[point1].first + arr[point2].first > c){
                point2--;
            }
            else{
                point1++;
            }
        }
    }
    if (point1 >= point2){
        cout << "IMPOSSIBLE\n";
    }
}
