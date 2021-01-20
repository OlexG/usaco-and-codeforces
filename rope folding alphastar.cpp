#include <fstream>
#include <string>
#include <iostream>
#include <math.h>
#include <algorithm>
#include <vector>
using namespace std;
int n, l;
int arr[100];
int main(){
    cin >> n >> l;
    for (int x = 0; x < n; x++){
        cin >> arr[x];
    }
    sort(arr, arr + n);
    int answer = 0;
    for (int x = 0; x < n - 1; x++){
        float foldingpos = (arr[x] + arr[x + 1])/2.0;
        int valid = true;
        int one = x;
        int two = x + 1;
        while(one >= 0 && two < n && valid){
            if (foldingpos - arr[one] != arr[two] - foldingpos){
                valid = false;
            }
            one--;
            two++;
        }
        if (valid){
            //cout << foldingpos << "\n";
            answer++;
        }
        if (x != 0){
            float foldingpos = (arr[x]);
            int valid = true;
            int one = x - 1;
            int two = x + 1;
            while(one >= 0 && two < n && valid){
                if (foldingpos - arr[one] != arr[two] - foldingpos){
                    valid = false;
                }
                one--;
                two++;
            }
            if (valid){
                //cout << foldingpos << "\n";
                answer++;
            }
        }
    }
    cout << answer << "\n";
}
