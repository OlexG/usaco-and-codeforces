#include <fstream>
#include <string>
#include <iostream>
#include <math.h>
#include <algorithm>
#include<bits/stdc++.h>
#include <vector>
using namespace std;

int t, n;
int main(){
    cin >> t;
    for (int b = 0; b < t; b++){
        cin >> n;
        int arr[n];
        for (int  x = 0; x < n; x++){
            cin >> arr[x];
        }
        long long answer = 0;
        int countUp[n + 5][n + 1];
        int countDown[n + 5][n + 1];
        for (int x = 1; x < n + 1; x++){
            int cur = x;
            //countup is offset by 1
            countUp[cur][0] = 0;
            countDown[cur][n] = 0;
            for (int y = 0; y < n; y++){
                if (arr[y] == cur){
                    countUp[cur][y + 1] = countUp[cur][y] + 1;
                }
                else{
                    countUp[cur][y + 1] = countUp[cur][y];
                }
            }
            for (int y = n - 1; y >= 0; y--){
                if (arr[y] == cur){
                    countDown[cur][y] = countDown[cur][y + 1] + 1;
                }
                else{
                    countDown[cur][y] = countDown[cur][y + 1];
                }
            }
        }
        for (int x = 0; x < n; x++){
            for (int y = x + 1; y < n; y++){
                int one = arr[x];
                int two = arr[y];
                //cout << answer << "\n";
                answer += countUp[two][x] * countDown[one][y + 1];
            }
        }
        cout << answer << "\n";
    }
}
