#include <fstream>
#include <string>
#include <iostream>
#include <math.h>
#include <algorithm>
#include <vector>
using namespace std;
int n;
int main(){
    cin >> n;
    long long arr[n];
    int one;
    for (int x = 0; x < n; x++){
        cin >> one >> one;
        arr[x] = one;
    }
    long long curmin = arr[n - 1];
    int answer = 1;
    for (int x = n - 2; x >= 0; x--){
        if (arr[x] <= curmin){
            answer++;
            curmin = arr[x];
        }
    }
    cout << answer;
}
