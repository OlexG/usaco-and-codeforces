 #include <fstream>
#include <string>
#include <iostream>
#include <math.h>
#include <algorithm>
#include <vector>
using namespace std;
int t, n;
vector<int> arr;
int main(){
    cin >> t;
    for (int z = 0; z < t; z++){
        cin >> n;
        arr.clear();
        int temp;
        for (int x = 0; x < n; x++){
            cin >> temp;
            arr.push_back(temp);
        }
        sort(arr.begin(), arr.end());
        bool answer = true;
        for (int x = 0; x < n - 1; x++){
            if (arr[x + 1] - arr[x] > 1){
                answer = false;
            }
        }
        if (answer){
            cout << "YES\n";
        }
        else{
            cout << "NO\n";
        }
    }
}
