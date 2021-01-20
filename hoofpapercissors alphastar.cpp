#include <fstream>
#include <string>
#include <iostream>
#include <math.h>
#include <algorithm>
#include <vector>
using namespace std;
int n;
char arr[100000];
int hwins[100000];
int swins[100000];
int pwins[100000];
int main(){
    cin >> n;
    for (int x = 0; x < n; x++){
        hwins[x] = 0;
        swins[x] = 0;
        pwins[x] = 0;
        cin >> arr[x];
    }
    for (int x = 0; x < n; x++){
        if (arr[x] == 'H'){
            if (x == 0){
                pwins[x] = 1;
            }
            else{
                pwins[x] = 1 + pwins[x - 1];
            }
            hwins[x] = hwins[x - 1];
            swins[x] = swins[x - 1];
        }
         if (arr[x] == 'S'){
            if (x == 0){
                hwins[x] = 1;
            }
            else{
                hwins[x] = 1 + hwins[x - 1];
            }
            swins[x] = swins[x - 1];
            pwins[x] = pwins[x - 1];
         }
         if (arr[x] == 'P'){
            if (x == 0){
                swins[x] = 1;
            }
            else{
                swins[x] = 1 + swins[x - 1];
            }
            hwins[x] = hwins[x - 1];
            pwins[x] = pwins[x - 1];
        }
    }
    int answer = 0;
    for (int x = 0; x < n; x++){
        answer = max(pwins[x]  + pwins[n - 1] - pwins[x], answer);
        answer = max(pwins[x]  + swins[n - 1] - swins[x], answer);
        answer = max(pwins[x]  + hwins[n - 1] - hwins[x], answer);
        answer = max(swins[x]  + swins[n - 1] - swins[x], answer);
        answer = max(swins[x]  + pwins[n - 1] - pwins[x], answer);
        answer = max(swins[x]  + hwins[n - 1] - hwins[x], answer);
        answer = max(hwins[x]  + pwins[n - 1] - pwins[x], answer);
        answer = max(hwins[x]  + swins[n - 1] - swins[x], answer);
        answer = max(hwins[x]  + hwins[n - 1] - hwins[x], answer);

    }
    cout << answer;
}
