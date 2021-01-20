#include <fstream>
#include <string>
#include <iostream>
#include <math.h>
#include <algorithm>
#include <vector>
using namespace std;

int n, m, e;

int arr[20][8];
int fr[8];
bool checkfr(){
    for (int x = 0; x < e; x++){
        for (int y = 0; y < m; y++){
            if (fr[y] < arr[x][y]){
                break;
            }
            if (y == m - 1 && fr[y] >= arr[e][y]){
                return true;
            }
        }
    }
    return false;
}
int answer = 0;
int rec(int cur){
    if (cur == n){
        if (checkfr()){
            answer++;
        }
    }
    else{
        for (int x = 0; x < m; x++){
            fr[x]++;
            rec(cur+1);
            fr[x]--;
        }
    }
}
int main(){
    for (int x = 0; x < 8; x++){
        fr[x] = 0;
    }
    for (int x = 0; x < 20; x++){
        for (int y = 0; y < 8; y++){
            arr[x][y] = 0;
        }
    }
    cin >> n >> m >> e;
    for (int x = 0; x < e + 1; x++){
        string str;
        getline(cin, str);
        if (x >= 1){
            while(str.size() > 0){
                int i = 0;
                while (str[i] != 'x'){
                    i++;
                }
                int w = stoi(str.substr(0, i));
                int r = str[i + 1] - '0';
                arr[x - 1][r - 1] = w;
                if (i + 3 > str.size()){
                    break;
                }
                else{
                    str = str.substr(i + 3);
                }

            }
        }
    }
    rec(0);
    cout << answer;
}
