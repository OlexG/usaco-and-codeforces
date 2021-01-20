#include <fstream>
#include <string>
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int t, n;

int main(){
    cin >> t;
    for (int h = 0; h < t; h++){
        cin >> n;
        long long arr[n];
        vector<long long> a;
        vector<long long> b;
        long long curevensum = 0;
        for (int x = 0; x < n; x++){
            cin >> arr[x];
        }
        for (int x = 1; x < n; x+=2){
            if (x - 1 >= 0){
                a.push_back(arr[x] - arr[x - 1]);
                curevensum += arr[x - 1];
            }
            if (x + 1 < n){
                b.push_back(arr[x] - arr[x + 1]);
            }
        }
        if (n%2 == 1){
            curevensum += arr[n - 1];
        }
        long long bestanswerchange = 0;
        long long cursum = 0;
        for (int x = 0; x < a.size(); x++){
            cursum += a[x];
            bestanswerchange = max(bestanswerchange, cursum);
            if (cursum < 0){
                cursum = 0;
            }
        }
        cursum = 0;
        for (int x = 0; x < b.size(); x++){
            cursum += b[x];
            bestanswerchange = max(bestanswerchange, cursum);
            if (cursum < 0){
                cursum = 0;
            }
        }
        curevensum += bestanswerchange;
        cout << curevensum << "\n";
    }
}
