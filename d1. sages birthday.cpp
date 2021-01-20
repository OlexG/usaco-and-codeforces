#include <fstream>
#include <string>
#include <iostream>
#include <math.h>
#include <algorithm>
#include <vector>
#include <iomanip>
using namespace std;

int n;
int main(){
    cin >> n;
    int arr[n];
    for (int x = 0; x < n; x++){
        cin >> arr[x];
    }
    sort(arr, arr + n);
    vector<int> small;
    vector<int> large;
    for (int x = 0; x < (n - 1)/2; x++){
        small.push_back(arr[x]);
    }
    for (int x = (n - 1)/2; x < n; x++){
        large.push_back(arr[x]);
    }
    cout << (n - 1)/2 << "\n";
    while(true){
        if (small.size() == 0){
            cout << large[large.size() - 1] << " ";
            large.pop_back();
        }
        else{
            cout << large[large.size() - 1] << " " << small[small.size() - 1] << " ";
            small.pop_back();
            large.pop_back();
        }
        if (large.size() == 0){
            break;
        }
    }

}
