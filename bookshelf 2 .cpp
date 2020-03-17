#include <fstream>
#include <string>
#include <iostream>
#include <math.h>
#include <algorithm>
using namespace std;

int used[21];
int n;
int m;
int arr[21];
int answer;
void rec(int c){
    if (c == n){
        int total = 0;
        for (int x = 0; x < n; x++){
            if (used[x] == 1){
                total = total + arr[x];

            }
        }

        if (total > m &&  total - m < answer){
            answer = total - m;
        }
    }
    else{
        used[c] = 0;
        rec(c + 1);
        used[c] = 1;
        rec(c + 1);
    }
}
int main(){
    answer = 10000;
    cin >> n;
    cin >> m;
    for (int x =0; x < 21; x ++){
        used[x] =0;
    }
    for (int x = 0; x < n; x++){
        cin >> arr[x];
    }
    rec(0);
    cout << answer;
    }
