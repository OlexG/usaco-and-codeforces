#include <fstream>
#include <string>
#include <iostream>
#include <math.h>
#include <algorithm>
#include <vector>
using namespace std;
int n;
int arr[2200];
int answer = 0;
void rec(int top, int bottom){
    if (bottom - top == 1){
        answer = answer + (arr[top] * arr[bottom]);
        return;
    }
    else if (bottom == top){
        return;
    }
    else{
        int mid = (top + bottom)/2;
        rec(top, mid);
        rec(mid + 1, bottom);
    }
}
int main(){
    cin >> n;
    for (int x = 1; x <= n; x++){
        arr[x - 1] = x;
    }
    rec(0, n - 1);
    cout << answer;
}
