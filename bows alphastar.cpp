#include <fstream>
#include <string>
#include <iostream>
#include <math.h>
#include <algorithm>
#include <vector>
using namespace std;

int arr[20];
int answer = 21;
int rec(int cur, int num){
    if (cur == 20){
        bool ans = true;
        for (int x = 0; x < 20; x++){
            if (arr[x] == 1){
                ans = false;
            }
        }
        if (ans){
            answer = min(answer, num);
        }
    }
    else{
        for (int x = cur - 1; x <= cur + 1; x++){
            if (x >= 0 && x < 20){
                if (arr[x] == 1){
                    arr[x] = 0;
                }
                else{
                    arr[x] = 1;
                }
            }
        }
        rec(cur + 1, num + 1);
        for (int x = cur - 1; x <= cur + 1; x++){
            if (x >= 0 && x < 20){
                if (arr[x] == 1){
                    arr[x] = 0;
                }
                else{
                    arr[x] = 1;
                }
            }
        }
        rec(cur + 1, num);
    }
}
int main(){
    for (int x = 0; x < 20; x++){
        cin >> arr[x];
    }
    rec(0,0);
    cout << answer;
}
