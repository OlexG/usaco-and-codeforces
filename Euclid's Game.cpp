#pragma GCC optimize("O2")
#include <fstream>
#include <string>
#include <iostream>
#include <bitset>
#include <math.h>
#include <string>
#include <algorithm>
#include<bits/stdc++.h>
#include <vector>
#include <queue>
using namespace std;

long long a, b;
bool stan = true;
int main(){
    //fstream in("in.txt");
    //ofstream out("output.txt");
    while(true){
        cin >> a >> b;
        stan = true;
        if (a == 0 && b == 0){
            break;
        }
        if (a < b){
            long long temp = a;
            a = b;
            b = temp;
        }
        while(a != 0 && b != 0){
            if (stan){
                if (a/b >= 2){
                    break;
                }
                a %= b;
                if (a == 0){
                    break;
                }
                stan = false;
            }
            else{
                if (b/a >= 2){
                    break;
                }
                b %= a;
                if (b == 0){
                    break;
                }
                stan = true;
            }
        }
        cout << (stan?"Stan wins\n":"Ollie wins\n");

    }
}
