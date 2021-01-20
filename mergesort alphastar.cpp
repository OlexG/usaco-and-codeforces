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
queue<int> temp1;
queue<int> temp2;
void mer(int low, int mid, int high){
    for (int x = low; x < mid + 1; x++){
        temp1.push(arr[x]);
    }
    for (int x = mid + 1; x < high + 1; x++){
        temp2.push(arr[x]);
    }
    int cur = low;
    while(temp1.empty() == false && temp2.empty() == false){
        if (temp1.front() <= temp2.front()){
            arr[cur] = temp1.front();
            temp1.pop();
            cur++;
        }
        else {
            arr[cur] = temp2.front();
            temp2.pop();
            cur++;
        }
    }
    while(temp1.empty() == false){
        arr[cur] = temp1.front();
        cur++;
        temp1.pop();
    }
    while(temp2.empty() == false){
        arr[cur] = temp2.front();
        cur++;
        temp2.pop();
    }
}
void msort(int low, int high) {
   int mid;

   if(low < high) {
      mid = (low + high) / 2;
      msort(low, mid);
      msort(mid+1, high);
      mer(low, mid, high);
      for (int x = 0; x < n; x++){
        cout << arr[x] << " ";
      }
      cout << "\n";
   } else {
      return;
   }
}
int main(){
    cin >> n;
    for (int x = 0; x < n; x++){
        cin >> arr[x];
    }
    msort(0, n - 1);
    mer(0, 4, 9);




}
