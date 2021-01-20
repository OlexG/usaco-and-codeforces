#include <fstream>
#include <string>
#include <iostream>
#include <math.h>
#include <algorithm>
#include<bits/stdc++.h>
#include <vector>
using namespace std;

long long t, a, b;

int main(){
    ifstream in("feast.in");
    ofstream out("feast.out");
    in >> t >> a >> b;
    bool used[t + 1];
    bool works[t + 1];
    for (int x = 0; x < t; x++){
        used[x] = false;
        works[x] = false;;
    }
    works[0] = true;
    for (int x = 1; x <= t; x++){
        if (x >= a && x >= b){
            if (works[x - a] || works[x - b]){
                works[x] = true;
            }
        }
        else if (x >= a){
            if (works[x - a]){
                works[x] = true;
            }
        }
        else if (x >= b){
            if (works[x - b]){
                works[x] = true;
            }
        }
    }
    for (int x = 1; x <= t; x++){
        if (works[x] && !works[x/2]){
            works[x/2] = true;
        }
    }
    for (int x = 1; x <= t; x++){
        if (x >= a && x >= b){
            if (works[x - a] || works[x - b]){
                works[x] = true;
            }
        }
        else if (x >= a){
            if (works[x - a]){
                works[x] = true;
            }
        }
        else if (x >= b){
            if (works[x - b]){
                works[x] = true;
            }
        }
    }
    for (int x = t; x >= 1; x--){
        if (works[x]){
            out << x << "\n";
            break;
        }
    }

}
