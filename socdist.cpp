#include <fstream>
#include <string>
#include <iostream>
#include <math.h>
#include <algorithm>
using namespace std;
#include <vector>
long long n, m;

pair<long long, long long> arr[100000];
bool check(long long d){
    long long curind = 0;
    long long cur = arr[0].first;
    long long cows = n;
    while(curind < m && cows > 0){
        cows = cows - 1;
        if (cows < 1){
            return true;
        }
        while(curind < m && cur + d > arr[curind].second){
            curind = curind + 1;
        }
        if (curind >= m){
            return false;
        }
        else{
            if (cur + d <= arr[curind].first){
                cur = arr[curind].first;
            }
            else{
                cur = cur + d;
            }
        }
    }
    if (cows < 1){
        return true;
    }
    else{
        return false;
    }
}

int main(){
    ifstream in("socdist.in");
    ofstream out("socdist.out");
    in >> n >> m;
    long long one, two;
    for (int x = 0; x < m; x++){
        in >> one >> two;
        arr[x] = make_pair(one, two);
    }
    sort(arr, arr + m);

    long long low = 0;
    long long high = 1000000000000000000;
    while(low < high){
        long long x = (low + high + 1)/2;
        if (check(x)){
            low = x;
        }
        else{
            high = x - 1;
        }
    }
    out << low << "\n";

}
