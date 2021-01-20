#include <fstream>
#include <string>
#include <iostream>
#include <math.h>
#include <algorithm>
#include<bits/stdc++.h>
#include <vector>
using namespace std;

int t, n;
long long arr[100001];
int main(){
    cin >> t;
    for (int p = 0; p < t; p++){
        cin >> n;
        long long posf = 0;
        long long posb = 0;
        long long backf = 0;
        long long backb = 0;
        for (int x = 0; x < n; x++){
            cin >> arr[x];
            if (arr[x] >= 0){
                posf += arr[x];
            }
            else{
                backf += arr[x];
            }
        }

        long long dump = 0;
        for (int x = 0; x < n; x++){
            if (arr[x] > 0){
                dump += arr[x];
                arr[x] = 0;
            }
            else{
                if (arr[x] * - 1 >= dump){
                    dump = 0;
                    arr[x] += dump;
                }
                else{
                    dump += arr[x];
                    arr[x] = 0;
                }
            }
        }
        /*for (int x = 0; x < n; x++){
            cout << arr[x] << " ";
        }*/
        cout << dump << "\n";



    }
}
