#include <fstream>
#include <string>
#include <iostream>
#include <math.h>
#include <algorithm>
#include <vector>
using namespace std;
int t, n;
int main(){
    cin >> t;
    for (int x = 0; x < t; x++){
        cin >> n;
        vector<long long> arr;
        long long one;
        for (int y = 0; y < n; y++){
            cin >> one;
            arr.push_back(one);
        }
        sort(arr.begin(), arr.end());
        int ione, itwo;
        vector<long long> answer;
        if (arr.size()%2 == 0){
            ione = arr.size()/2 - 1;
            itwo = arr.size()/2;
            answer.push_back(arr[ione]);
            answer.push_back(arr[itwo]);
        }
        else{
            ione = (arr.size() - 1)/2;
            itwo = ione;
            answer.push_back(arr[ione]);
        }
        while(ione > 0){
            ione--;
            itwo++;
            answer.push_back(arr[ione]);
            answer.push_back(arr[itwo]);
        }
        for (int y = 0; y < n; y++){
            cout << answer[y] << " ";
        }
        cout << "\n";

    }
}
