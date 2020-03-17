#include <fstream>
#include <string>
#include <iostream>
#include <math.h>
#include <algorithm>
using namespace std;
int sum;
int n;
int arr[21];
int best = 0;
void recurse(int csum, int f){
    if (f == n){
        if (csum > best){
            best = csum;
        }
    }
    else{
        if (csum + arr[f] <= sum){

            recurse(csum + arr[f], f + 1);
        }
        recurse(csum, f + 1);


    }
}
int main(){
    cin >> sum;
    cin >> n;
    for (int x = 0; x < n; x ++){
        cin >> arr[x];
    }
    recurse(0, 0);
    cout << best;

}
