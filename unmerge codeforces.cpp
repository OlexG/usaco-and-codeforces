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
    for (int z = 0; z < t; z++){
        cin >> n;
        vector<int> subsets;
        int arr[2*n + 1];
        for (int x = 0; x < 2*n; x++){
            cin >> arr[x];
        }
        int cur = 2*n - 1;
        while(cur >= 0){
            int curmax = arr[cur];
            int curmaxindex = cur;
            for (int x = cur; x >= 0; x--){
                if (arr[x] > curmax){
                    curmax = arr[x];
                    curmaxindex = x;
                }
            }
            subsets.push_back(cur - curmaxindex + 1);
            //cout << cur - curmaxindex + 1 << "\n";
            cur = curmaxindex - 1;
        }
        subsets.push_back(0);
        sort(subsets.begin(), subsets.end());
        bool memoization[subsets.size()][n + 1];
        memoization[0][0] = true;
        for (int x = 1; x <= n; x++){
            memoization[0][x] = false;
        }
        for (int x = 1; x < subsets.size(); x++){
            for (int y = 0; y <= n; y++){
                bool bool1 = memoization[x - 1][y];
                bool bool2;
                int remainingsum = y - subsets[x];
                if (remainingsum < 0){
                    bool2 = false;
                }
                else{
                    bool2 = memoization[x - 1][remainingsum];
                }
                memoization[x][y] = bool1 || bool2;
            }
        }
        if (memoization[subsets.size() - 1][n]){
            cout << "YES\n";
        }
        else{
            cout << "NO\n";
        }
    }
}
