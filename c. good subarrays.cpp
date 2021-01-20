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
        vector<int> arr;
        arr.push_back(0);
        string temp;
        cin >> temp;
        for (int x = 0; x < n; x++){
            arr.push_back(temp[x] - '0');
        }
        for (int x = 1; x <= n; x++){
            arr[x] = arr[x] + arr[x - 1];
        }
        for (int x = 1; x <= n; x++){
            arr[x] = arr[x] - x;
            //cout << arr[x] << " ";
        }
        sort(arr.begin(), arr.end());
        long long answer = 0;
        long long cur = 1;
        for (int x = 1; x <= n; x++){
            if (arr[x - 1] == arr[x]){
                cur+=1;
            }
            else{
                //cout << cur << "\n";
                answer = answer + ((cur - 1) * (cur))/2;
                cur = 1;
            }
        }
        answer = answer + ((cur - 1) * (cur))/2;
        cout << answer << "\n";

    }
}
