/*
ID: alex.go2
LANG: C++11
PROB: subset
*/
#include <fstream>
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;
int n;
int answer = 0;
int arr[39];
int sum[900];


int main(){

     ifstream in("subset.in");
     ofstream out("subset.out");
     cin >> n;
     for (int x = 0; x < 900; x++){
        sum[x] = 0;
     }
     sum[0] = 1;
     if ((n * (n + 1)/2) % 2 == 0){
        for (int x = 1; x < n; x++){
            for (int y = (n * (n + 1))/2 - x; y >= 0; y--){
                sum[x + y] += sum[y];
            }
        }
        cout << sum[(n * (n + 1))/2/2] << "\n";
     }
     else{
        cout << 0 << "\n";
     }

}
