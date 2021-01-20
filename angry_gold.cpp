#include <fstream>
#include <string>
#include <iostream>
#include <math.h>
#include <algorithm>
#include <vector>
#include <iomanip>
using namespace std;
/*10 1 5 6 7 8 9 10 22 27 23*/
int n;
long long arr[50005];
bool ok(long long k){
    long long cur = 0;
    double av = (double)k / 2.0;
    long long curk = 0;
    long long most = 1000000000;
    while(true){
        long long counter = cur;
        while(arr[counter] - arr[cur] <= curk){
            counter++;
            if (counter >= n){
                return true;
            }
        }
        cur = counter - 1;
        curk++;
        if (cur < n - 1){
            if (arr[cur + 1] - arr[cur] > curk){
                curk = arr[cur + 1] - arr[cur];
                cur++;
            }
            else if (arr[cur + 1] - arr[cur] == curk){
                curk = arr[cur + 1] - arr[cur] + 1;
                cur++;
            }
        }
        if (curk > av){
            cur--;
            break;
        }
    }
    long long counter = 1;
    long long pointer = cur;
    long long spointer = cur;
    while(arr[spointer] - arr[pointer] <= k){
        spointer++;
        if (spointer >= n){
            return true;
        }
    }
    pointer = spointer - 1;
    while(pointer < n - 1){

        int secondpointer = pointer;
        while(arr[secondpointer] - arr[pointer] <= av - counter){
            secondpointer++;
            if (secondpointer >= n){
                return true;
            }
        }
        if (pointer >= secondpointer - 1){
            return false;
        }
        pointer = secondpointer - 1;
        counter += 1;
    }

    return true;


}
int main(){
    ifstream in("angry.in");
    ofstream out("angry.out");
    in >> n;
    for (int x = 0; x < n; x++){
        in >> arr[x];
    }
    sort(arr, arr + n);
    long long mi = 0;
    long long ma= 1000000000;

    while(mi < ma){
        long long cur = (mi + ma)/2;
        if (ok(cur)){
            ma = cur;
        }
        else{
            mi = cur + 1;
        }
    }
    out.setf(ios::fixed);
    out << setprecision(1) << fixed << (double)ma/2.0;
    out << "\n";
}
