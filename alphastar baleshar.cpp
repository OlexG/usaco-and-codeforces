#include <fstream>
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;

int n;
int arr[20];
int answer = 10000000;
void rec(int cur1, int cur2, int cur3, int cur){
    if (cur == n){
        answer = min(answer, max(max(cur1, cur2), cur3));
    }
    else{
        if (cur1 + arr[cur] < answer){
            rec(cur1 + arr[cur], cur2, cur3, cur+1);
        }
        if (cur2 + arr[cur] < answer){
            rec(cur1, cur2 + arr[cur], cur3, cur+1);
        }
        if (cur3 + arr[cur] < answer){
            rec(cur1, cur2, cur3 + arr[cur], cur+1);
        }
    }
}
int main(){
    cin >> n;
    for (int x = 0; x < n; x++){
        cin >> arr[x];
    }
    rec(0,0,0,0);
    cout << answer;
}
