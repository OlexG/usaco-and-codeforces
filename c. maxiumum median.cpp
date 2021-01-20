#include <fstream>
#include <string>
#include <iostream>
#include <math.h>
#include <algorithm>
#include <vector>
using namespace std;

int n,k;
vector<long long> arr;
bool ok(long long needed){
    long long av = k;
    for (int x = 0; x < arr.size(); x++){
        if (needed > arr[x]){
            av -= (needed - arr[x]);
        }
    }
    if (av < 0){
        return false;
    }
    return true;
}
int main(){
    cin >> n >> k;
    vector<long long> nums;
    long long temp;
    for (int x = 0; x < n; x++){
        cin >> temp;
        nums.push_back(temp);
    }
    sort(nums.begin(), nums.end());

    for (int x = n/2; x < n; x++){
        arr.push_back(nums[x]);
    }

    long long low = 0;
    long long high = 3000000000;
    while(low < high){
        long long mid = (low + high + 1)/2;
        if (ok(mid)){
            low = mid;
        }
        else{
            high = mid - 1;
        }
    }
    cout << low << "\n";


}
