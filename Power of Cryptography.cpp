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
long long powb(long long a,long long b) {long long res=1;a ; assert(b>=0); for(;b;b>>=1){if(b&1)res=res*a;a=a*a;}return res;}

double n, k;
int main(){
    //ifstream in("in.txt");
    //ofstream out("output.txt");
    while(cin >> k && cin >> n){
       printf("%.0lf\n",pow(n, 1/k));
    }
}
