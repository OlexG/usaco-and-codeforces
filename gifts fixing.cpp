#include <fstream>
#include <string>
#include <iostream>
#include <math.h>
#include <algorithm>
#include <vector>
using namespace std;

int t, n;
long long a[51];
long long b[51];

int main(){
    cin >> t;
    for (int k = 0; k < t; k++){
        long long moves = 0;
        cin >> n;
        long long temp;
        for (int x = 0; x < n; x++){
            cin >> temp;
            a[x] = temp;
        }
        for (int x = 0; x < n; x++){
            cin >> temp;
            b[x] = temp;
        }
        long long smallesta = 1000000000;
        long long smallestb = 1000000000;
        for (int x = 0; x < n; x++){
            if (a[x] < smallesta){
                smallesta = a[x];
            }
            if (b[x] < smallestb){
                smallestb = b[x];
            }
        }
        for (int x = 0; x < n; x++){
            long long firstsub = min(a[x] - smallesta, b[x] - smallestb);
            moves += firstsub;
            a[x] -= firstsub;
            b[x] -= firstsub;
            if (a[x] - smallesta == 0){
                moves += b[x] - smallestb;
            }
            else{
                moves += a[x] - smallesta;
            }
        }
        cout << moves << "\n";
    }
}
