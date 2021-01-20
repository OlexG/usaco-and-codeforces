#include <fstream>
#include <string>
#include <iostream>
#include <math.h>
#include <algorithm>
#include <vector>
using namespace std;

int n, k;
vector<int> nums;
int main(){
    ifstream in("diamond.in");
    ofstream out("diamond.out");
    in >> n >> k;
    int temp;
    for (int x = 0; x < n; x++){
        in >> temp;
        nums.push_back(temp);
    }
    sort(nums.begin(), nums.end());
    int point1 = 0;
    int point2 = 0;
    int answer = 0;
    int bestp1 = 0;
    int bestp2 = 0;

    int farr[n];
    for (int x = 0; x < n; x++){
        farr[x] = 0;
    }
    while(point2 < n){
        if (nums[point2] - nums[point1] <= k){
            farr[point2] = max(farr[point2], point2 - point1 + 1);
            answer = max(answer, point2 - point1 + 1);
            point2++;
        }
        else{
            point1++;
        }
    }
    int barr[n];
    for (int x = 0; x < n; x++){
        barr[x] = 0;
    }
    point1 = n - 1;
    point2 = n - 1;
    while(point1 >= 0){
        if (nums[point2] - nums[point1] <= k){
            barr[point1] = max(barr[point1], point2 - point1 + 1);
            answer = max(answer, point2 - point1 + 1);
            point1--;
        }
        else{
            point2--;
        }
    }
    for (int x = 1; x < n; x++){
        farr[x] = max(farr[x], farr[x - 1]);
    }
    for (int x = n - 2; x >= 0; x--){
        barr[x] = max(barr[x], barr[x + 1]);
    }
    for (int x = 0; x < n - 1; x++){
        answer = max(answer, farr[x] + barr[x + 1]);
    }
    out << answer<< "\n";
}
