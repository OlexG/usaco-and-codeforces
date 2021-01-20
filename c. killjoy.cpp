#include <fstream>
#include <string>
#include <iostream>
#include <math.h>
#include <algorithm>
#include <vector>
#include <iomanip>
using namespace std;
int t, k, n;

int main(){
    cin >> t;
    for (int z = 0; z < t; z++){
        cin >> n >> k;
        int arr[n];
        for (int x = 0; x < n; x++){
            cin >> arr[x];
        }
        int prevchanges = 0;
        for (int x = 0; x < n - 1; x++){
            prevchanges += k - arr[x];
        }
        if (prevchanges + (k - arr[n - 1]) == 0){
            int nochange = true;
            for (int x = 1; x < n; x++){
                if (arr[x] != arr[x - 1]){
                    nochange = false;
                }
            }
            if (nochange){
                cout << 0 << "\n";
            }
            else{
                cout << 1 << "\n";
            }
        }
        else{
            bool startinf = false;
            for (int x = 0; x < n; x++){
                if (arr[x] == k){
                    startinf = true;
                }
            }
            if (startinf){
                cout << 1 << "\n";
            }
            else{
                cout << 2 << "\n";
            }
        }
    }
}
