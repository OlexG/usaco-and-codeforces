#include <fstream>
#include <string>
#include <iostream>
#include <math.h>
#include <algorithm>
#include<bits/stdc++.h>
#include <vector>
using namespace std;
long long a, b, c, d;

long long sum(long long n){
    return ((1 + n) * n)/2;
}
long long square(long long n){
    return n * (n + 1) * (2 * n + 1)/6;
}

int main(){
    cin >> a >> b >> c >> d;
    long long answer = 0;
    for (long long one = a; one <= b; one++){
            //for the smallest b side, all c sides must be bottom or less
            long long bottom = b + one - 1;
            long long numofb = c - b + 1;

            //the bottom is too low, we discard some of the smaller bs
            if (bottom < c){
                numofb -= (c - bottom);
                bottom = c;
            }
            if (numofb <= 0){
                continue;
            }
            //if all a + b will be more then c
            if (bottom > d){
                answer += ((numofb) * (d - c + 1));
                continue;
            }

            long long cmax = min((bottom - c) + numofb, d - c + 1);
            long long cstart = bottom - c;
            //cout << one << " " << bottom << " " << cmax << " " << numofb << "\n";
            answer += (sum(cmax) - sum(cstart));
            numofb -= (cmax - (cstart));
            if (numofb <= 0){
                continue;
            }
            answer += ((numofb) * (d - c + 1));




    }
    cout << answer << "\n";
}
