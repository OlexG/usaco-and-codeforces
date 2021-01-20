#include <fstream>
#include <string>
#include <iostream>
#include <math.h>
#include <algorithm>
#include <vector>
using namespace std;
int n, t;
int main(){
    cin >> t;
    for (int c = 0; c < t; c++){
        cin >> n;
        vector<int> arr;
        int one;
        for (int x = 0; x < n; x++){
            cin >> one;
            arr.push_back(one);
        }
        sort(arr.begin(), arr.end());
        int numofsame = 1;
        int total = 1;
        for(int x = 1; x < n; x++){
            if (arr[x - 1] != arr[x]){
                total = 1;
            }
            else{
                total++;
                numofsame = max(numofsame, total);
            }
        }
        int numofdif = 0;
        for (int x = 1; x < n; x++){
            if (arr[x - 1] != arr[x]){
                numofdif++;
            }
        }
        if (numofdif == numofsame){
            cout << numofdif << "\n";
        }
        else if (numofdif < numofsame){
            cout << min(numofdif + 1, numofsame - 1) << "\n";
        }
        else if (numofdif > numofsame){
            cout << numofsame << "\n";
        }
    }
}
