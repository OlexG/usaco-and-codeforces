#include <fstream>
#include <string>
#include <iostream>
#include <math.h>
#include <algorithm>
using namespace std;
long long n, d, m;
bool ok(long long x, long long n, long long m, long long d){
    long long need = n;
    long long give = need/x;
    long long curdays = 0;
    while(give > m && need > 0){
        //cout << give << "\n";
        long long tillchange = need - (x * give);
        curdays += ((tillchange/give) + 1);
        need = need - (tillchange/give) * give;
        need -= give;
        give = need/x;
    }
    //cout << need << "\n";
    if (need == 0){
        return curdays <= d;
    }
    curdays += (need + m - 1)/m;
    return curdays <= d;
}
int main(){
    ifstream in("loan.in");
    ofstream out("loan.out");
    in >> n >> d >> m;
    long long one = 0;
    long long two = 1000000000001;
    while(one < two){
        //cout << one << " " << two << "\n";
        long long x = (one + two + 1)/2;
        //cout << x << "\n";
        if (ok(x, n, m, d)){
            one = x;
        }
        else{
            two = x - 1;
        }
    }
    out << one << "\n";
}
