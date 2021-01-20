#include <fstream>
#include <string>
#include <iostream>
#include <math.h>
#include <algorithm>
#include <vector>
using namespace std;

int n;
long long arr[100003];
long long leftm = 50002;
long long rightm = 50003;
long long curcow = 1;
int main(){

    cin >> n;
    char type;
    char lorr;
    long long howmany;
    for (int x = 0; x < n; x++){
        cin >> type;
        if (type == 'A'){
            cin >> lorr;
            if (lorr == 'L'){
                arr[leftm] = curcow;
                leftm--;
                curcow++;
            }
            else{
                arr[rightm] = curcow;
                rightm++;
                curcow++;
            }
        }
        else{
            cin >> lorr >> howmany;
            if (lorr == 'L'){
                leftm += howmany;
            }
            else{
                rightm -= howmany;
            }
        }

    }
    for (long long x = leftm + 1; x < rightm; x++){
        cout << arr[x] << "\n";
    }
}
