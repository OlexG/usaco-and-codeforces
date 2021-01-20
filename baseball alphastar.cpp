#include <fstream>
#include <string>
#include <iostream>
#include <math.h>
#include <algorithm>
#include <vector>
using namespace std;
int n;
int arr[1000];
int upperbound(int x){
    int l = 0;
    int t = n;
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
    int t = n;
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
    cin >> n;
    for (int x = 0; x < n; x++){
        cin >> arr[x];
    }
    sort(arr, arr + n);
    int answer = 0;
    for (int x = 0; x < n - 2; x++){
        for (int y = x + 1; y < n; y++){
            int xc = arr[x];
            int yc = arr[y];
            answer = answer + upperbound(yc + 2 * (yc - xc)) - lowerbound(yc + yc - xc);
        }
    }
    cout << answer;
}
