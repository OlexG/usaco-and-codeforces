#include <fstream>
#include <string>
#include <iostream>
#include <math.h>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;


string s;
int main(){
    cin >> s;
    int n = s.size();
    int an = 0;
    int answer = 0;
    int b = -1;
    bool banswer = false;
    bool solve = true;
    for (int x = 0; x < n; x++){
        if (s[x] == '('){
            an++;
        }
        else{
            an--;
        }

    }
    if (an != 2 && an != -2){
        solve = false;
    }
    an = 0;
    for (int x = 0; x < n; x++){
        if (s[x] == '('){
            an++;
        }
        else{
            an--;
        }
        if (an < 0){
            if (x != 0){
                b = x;
                banswer = true;
                break;
            }
        }
    }
    if (solve){
        if (banswer){
            for (int x = 0; x < b + 1; x++){
                if (s[x] == ')'){
                    answer++;
                }
            }
        }
        else{
            an = 0;
            for (int x = n - 1; x >= 0; x--){
                if (s[x] == ')'){
                    an++;
                }
                else{
                    an--;
                }
                if (an < 0){
                    if (x != 0){
                        b = x;
                        break;
                    }
                }
            }
            for (int x = b; x < n; x++){
                if (s[x] == '('){
                    answer++;
                }
            }
        }
    }
    cout << answer;

}
