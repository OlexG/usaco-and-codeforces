#include <fstream>
#include <string>
#include <iostream>
#include <math.h>
#include <queue>
#include <algorithm>
#include <vector>
using namespace std;
int arr[500];
int n;
vector<int> temp1;
vector<int> temp2;
long long totaldist = 0;
void mer(int low, int mid, int high){

    temp1.clear();
    temp2.clear();
    for (int x = low; x < mid + 1; x++){
        temp1.push_back(arr[x]);
    }
    for (int x = mid + 1; x < high + 1; x++){
        temp2.push_back(arr[x]);
    }
    bool m = false;
    for (int x = 0; x < temp1.size(); x++){
        if (temp1[x] > temp2[x]){
            m = true;
            break;
        }
        else{
            m = false;
            break;
        }
    }
    if (m){
        totaldist += temp1.size() * temp1.size() * 2;
        int cur = 0;
        for (int x = 0; x < temp2.size(); x++){
            arr[x + low] = temp2[x];
            cur++;
        }
        for (int x = 0; x < temp1.size(); x++){
            arr[x + low + cur] = temp1[x];
        }
    }

}
void msort(int low, int high) {
   int mid;

   if(low < high) {
      mid = (low + high) / 2;
      msort(low, mid);
      msort(mid+1, high);
      mer(low, mid, high);
   } else {
      return;
   }
}
int main(){
    cin >> n;
    n = pow(2, n);
    for (int x = 0; x < n; x++){
        cin >> arr[x];
    }
    msort(0, n - 1);
    cout << totaldist << "\n";
    for (int x = 0; x < n; x++){
        cout << arr[x] << "\n";
    }


}
