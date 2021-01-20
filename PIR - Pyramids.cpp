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

long long t;

long long powb(long long a,long long b) {long long res=1;a ; assert(b>=0); for(;b;b>>=1){if(b&1)res=res*a;a=a*a;}return res;}
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
    cin >> t;
    for(int z = 0; z < t; z++){
        long long a,b,c,d,e,f;
        cin >> a >> b >> c >> d >> e >> f;
        long long matrix[10][10];
        for (int x = 0; x < 5; x++){
            for (int y = 0; y < 5; y++){
                matrix[x][y] = 0;
            }
        }
        for (int x = 1; x < 5; x++){
            matrix[0][x] = 1;
            matrix[x][0] = 1;
        }
        matrix[0][0] = 0;
        matrix[1][2] = a * a;
        matrix[1][3] = b * b;
        matrix[1][4] = c * c;
        matrix[2][1] = a * a;
        matrix[3][1] = b * b;
        matrix[4][1] = c * c;
        matrix[2][3] = d * d;
        matrix[3][2] = d * d;
        matrix[2][4] = e * e;
        matrix[4][2] = e * e;
        matrix[4][3] = f * f;
        matrix[3][4] = f * f;
        /*for (int x = 0; x < 5; x++){
            for (int y = 0; y < 5; y++){
                cout << matrix[x][y] << " ";
            }
            cout << "\n";
        }*/
        long long det = determinant(matrix, 5);
        double answer = sqrt((double)det/288);
        long long rounded_answer = round(sqrt((double)det/288));
        int s = to_string(rounded_answer).length();
        if (rounded_answer == 0){
            s = 0;
        }
        cout << setprecision(s+4) << answer << "\n";
    }
}
