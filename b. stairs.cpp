#include <fstream>
#include <string>
#include <iostream>
#include <math.h>
#include <algorithm>
#include <vector>
#include <iomanip>
using namespace std;

int t;
long long xi;
int main(){
    cin >> t;
    for (int z = 0; z < t; z++){
        cin >> xi;
        //cout << xi << "\n";
        long long prev = 0;
        long long cur = 1;
        long long counter = 1;
        while(true){
            long long amount = (cur*cur) + prev * 2;
            prev = amount;
            if (amount > xi){
                break;
            }
            xi -= amount;
            counter++;
            cur = cur * 2;

        }
        cout << counter - 1 << "\n";
    }
}
