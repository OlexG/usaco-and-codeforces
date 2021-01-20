#include <fstream>
#include <string>
#include <iostream>
#include <math.h>
#include <algorithm>
#include <vector>
using namespace std;
int i, n;
string cows[20];
string bulls[20];
bool check(string pone, string ptwo, string child){
    bool ok = true;
    for (int x = 0; x < 25; x++){
        if (child[x] != pone[x] && child[x] != ptwo[x]){
            ok = false;
        }
    }
    return ok;
}
int main(){
    cin >> i >> n;
    for (int x = 0; x < i; x++){
        cin >> bulls[x];
    }
    for (int x= 0; x < n; x++){
        cin >> cows[x];
    }
    for (int x = 0; x < i; x++){
        for (int y = 0; y < n; y++){
            int answer = 0;
            for (int z = 0; z < i; z++){
                if (z != x){
                    if (check(bulls[x], cows[y], bulls[z])){
                        answer++;
                    }
                }
            }
             for (int z = 0; z < n; z++){
                if (z != y){
                    if (check(bulls[x], cows[y], cows[z])){
                        answer++;
                    }
                }
            }
            cout << answer << " ";
        }
        cout << "\n";
    }
}
