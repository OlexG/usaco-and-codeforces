#include <fstream>
#include <string>
#include <iostream>
#include <math.h>
#include <algorithm>
#include <vector>
using namespace std;

int t, n, k, l;
vector<long long> depths;
vector<long long> times;
bool possible = true;
bool up(long long start, long long finish){
    for (int x = start; x <= finish; x++){
        if (x - start > times[x]){
            return false;
        }
    }
    return true;
}
bool down(long long start, long long finish){
    for (int x = start; x <= finish; x++){
        long long totall = finish - start + 1;
        long long left = finish - x;
        if (left > times[x]){
            //cout << "\n\n" << x  << " " << times[x] << "\n\n";
            long long minimum = x + times[x];
            long long counter = x;
            while(counter < minimum){
                if (counter + times[counter] < minimum){
                    minimum = counter + times[counter];
                }
                counter++;
            }
            return up(minimum, finish);
        }
    }
    return true;
}
int main(){
    cin >> t;
    for (int b = 0; b < t; b++){
        cin >> n >> k >> l;
        depths.clear();
        times.clear();
        possible = true;
        long long temp;
        for (int x = 0; x < n; x++){
            cin >> temp;
            depths.push_back(temp);
            if (temp > l){
                possible = false;
            }
            times.push_back(l - temp);
        }
        if (possible){
            long long start = 0;
            long long ending = -1;
            for (int x = 0; x <= n; x++){
                if (x == n){
                    ending = x - 1;
                }
                else if (times[x] >= k){
                    ending = x - 1;
                }
                if (ending > start){
                    if (up(start, ending) || down(start, ending)){
                        //cout << start << " " << ending << "\n";
                        start = ending + 2;
                    }
                    else{
                        //cout << start << " " << ending << "\n";
                        possible = false;
                    }
                }
                else{
                    start = ending + 1;
                }
            }
        }
        if (possible){
            cout << "YES\n";
        }
        else{
            cout << "NO\n";
        }
    }

}
