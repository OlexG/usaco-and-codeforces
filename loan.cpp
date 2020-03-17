#include <fstream>
#include <string>
#include <iostream>
#include <math.h>
#include <algorithm>
using namespace std;
bool ok(long long n, long long k, long long m, long long x){
    long long total = 0;
    long long z = 0;
    while(z < k){

        long long y = (n - total)/x;
        if (y < m){
            total = total + (m * (k - z));
            break;
        }
        long long tillchange = (n-total) %x ;
        long long act = (tillchange / y) + 1;
        total += act * y;
        z += act;
    }

    return total >= n;
}
int main(){
    ifstream in("loan.in");
    ofstream out("loan.out");
    long long n = 0;
    long long k = 0;
    long long m = 0;

    in >> n;
    in >> k;
    in >> m;
    long long low = 1;
    long long high = 1000000000000;
    long long x;

    while(low < high){
        x = (low + high + 1)/2;

        if (ok(n, k, m, x)){
            low = x;
        }
        else{
            high = x - 1;
        }

    }
    out << low << "\n";


}
