#include <fstream>
#include <string>
#include <iostream>
#include <math.h>
#include <algorithm>
#include <vector>
using namespace std;
int arr[8];
int answer = 0;
void rec(int cur){
    if (cur == 8){
        answer++;
    }
    else{
        for (int x = 0; x < 8; x++){
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
    rec(0);
    cout << answer;
}
