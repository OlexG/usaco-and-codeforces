//created by Oleksandr Gorpynich
#pragma GCC optimize("O2")
#include <fstream>
#include <string>
#include <iostream>
#include <bitset>
#include <math.h>
#include <string>
#include <algorithm>
#include <assert.h>
#include<bits/stdc++.h>
#include <vector>
#include <queue>
#include<stdio.h>
#include<ctype.h>
#define ll long long
using namespace std;
//PI
const double PI  =3.141592653589793238463;

//combinatronics
long long mod = 10000;
long long powmod(long long a,long long b) {long long res=1;a%=mod; assert(b>=0); for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
long long powb(long long a,long long b) {long long res=1;a ; assert(b>=0); for(;b;b>>=1){if(b&1)res=res*a;a=a*a;}return res;}
long long gcd(long long a,long long b) { return b?gcd(b,a%b):a;}

long long modinv(long long n){
    return powmod(n, mod - 2);
}

long long ncrferm(long long n, long long r){
    if (n < r){
        return 0;
    }
    if (r == 0){
        return 1;
    }
    long long fac[n + 1];
    fac[0] = 1;
    for (int i = 1; i <= n; i++){
        fac[i] = (fac[i - 1] * i) % mod;
    }

    return (fac[n] * modinv(fac[r]) % mod * modinv(fac[n - r]) % mod) % mod;
}



//standard functions

long long cbits(long long number)
{
      return (int)log2(number)+1;
}
int upperbound(int x){
    int l = 0;
    int t = n;
    while (l < t){
        int mid = (l + t)/2;
        if (x >= arr[mid]){
            l = mid + 1;
        }
        else{
            t = mid;
        }
    }
    return l;
}
int lowerbound(int x){
    int l = 0;
    int t = n;
    while (l < t){
        int mid = (l + t)/2;
        if (x <= arr[mid]){
            t = mid;
        }
        else{
            l = mid + 1;
        }
    }
    return l;
}


//matrix stuff
long long determinant( long long matrix[10][10], long long n) {
   long long det = 0;
   long long submatrix[10][10];
   if (n == 2)
   return ((matrix[0][0] * matrix[1][1]) - (matrix[1][0] * matrix[0][1]));
   else {
      for (int x = 0; x < n; x++) {
         long long subi = 0;
         for (int i = 1; i < n; i++) {
            long long subj = 0;
            for (long long j = 0; j < n; j++) {
               if (j == x)
               continue;
               submatrix[subi][subj] = matrix[i][j];
               subj++;
            }
            subi++;
         }
         det = det + (pow(-1, x) * matrix[0][x] * determinant( submatrix, n - 1 ));
      }
   }
   return det;
}
int main(){
    ifstream in("meetings.in");
    ofstream out("meetings.out");
}
