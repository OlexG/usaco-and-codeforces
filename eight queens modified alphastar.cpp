#include <fstream>
#include <string>
#include <iostream>
#include <math.h>
#include <algorithm>
#include <vector>
using namespace std;
int arr[15];
int n;
int answer = 0;
void rec(int cur){
    if (cur == n){
        answer++;
    }
    else{
        for (int x = 0; x < n; x++){
            bool works = true;
            for (int y = 0; y < cur; y++){
                if (arr[y] == x || y - arr[y] == cur - x || cur + x == y + arr[y]){
                    works = false;
                }
            }
            if (works){
                arr[cur] = x;
                rec(cur + 1);
            }

        }
    }
}

int main(){
    cin >> n;
    rec(0);
    cout << answer;
}
