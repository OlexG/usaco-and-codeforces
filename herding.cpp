#include <fstream>
#include <string>
#include <iostream>
#include <math.h>
#include <algorithm>
#include <vector>
using namespace std;
int n;

int main(){
    ifstream in("herding.in");
    ofstream out("herding.out");
    in >> n;
    long long arr[n];
    for (int x = 0; x < n; x++){
        in >> arr[x];
    }
    sort(arr, arr+n);
    long long ma;
    if ((arr[1] - arr[0]) > (arr[n - 1] - arr[n -2])){
        ma = arr[1] - arr[0] - 1;
    }
    else{
        ma = arr[n - 1] - arr[n -2] - 1;
    }
    for (int x = 1; x < n - 2; x++){
        ma = ma + arr[x + 1] - arr[x] - 1;
    }
    int j = 0;
    int i = 0;
    long long best = 0;
    while (j < n ){
        if (arr[j] - arr[i] <= n){
            if ((j - i) > best){
                best = j - i;
            };
            j = j + 1;
        }
        else{
            i = i + 1;
        }
    }
    if (arr[n - 2] - arr[0] == n -2 && arr[n - 1] - arr[n - 2] > 2){
        out << 2 << "\n";
    }
    else if (arr[n - 1] - arr[1] == n - 2 && arr[1] - arr[0] > 2){
        out << 2 <<"\n";
    }
    else {
        out << n - best - 1 << "\n";
    }
    out << ma << "\n";



}
