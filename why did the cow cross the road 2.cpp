#include <fstream>
#include <string>
#include <iostream>
#include <math.h>
#include <algorithm>
#include <vector>
using namespace std;

int n, k, b;
int arr[100000];
int upperbound(int x){
    int l = 0;
    int t = b;
    while (l < t){
        int mid = (l + t)/2;
        if (x >= arr[mid]){
            l = mid + 1;
        }
        else{
            t = mid;
        }
    }
    return l;
}
int lowerbound(int x){
    int l = 0;
    int t = b;
    while (l < t){
        int mid = (l + t)/2;
        if (x <= arr[mid]){
            t = mid;
        }
        else{
            l = mid + 1;
        }
    }
    return l;
}
int main(){
    cin >> n >> k >> b;
    int one;
    for (int x = 0; x < b; x++){
        cin >> one;
        arr[x] = one - 1;
    }
    sort(arr, arr  + b);
    int answer = 1000000;
    for (int x = 0; x < n - k; x++){
        answer = min(upperbound(x + k - 1) - lowerbound(x), answer);

    }
    cout << answer;
}


