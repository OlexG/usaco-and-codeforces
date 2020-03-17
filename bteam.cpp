#include <fstream>
#include <string>
#include <iostream>
#include <math.h>
#include <algorithm>
#include <initializer_list>
using namespace std;
int arr[12];
long long best = 1000000000;
void recurse(int one, int two, int three, int four, int sumone, int sumtwo, int sumthree, int sumfour ,int f){
    if (one == 3 && two == 3 && three == 3 && four == 3){
        int ma = max({sumone, sumtwo, sumthree, sumfour});
        int mi = min({sumone, sumtwo, sumthree, sumfour});
        if ((ma - mi) < best){
            best = ma - mi;

        }
    }
    else{
        if (one < 3){
            recurse(one + 1, two, three, four, sumone + arr[f], sumtwo, sumthree, sumfour, f + 1);
        }
        if (two < 3){
            recurse(one, two + 1, three, four, sumone, sumtwo  + arr[f], sumthree, sumfour, f + 1);
        }
        if (three < 3){
            recurse(one, two, three + 1, four, sumone, sumtwo, sumthree + arr[f], sumfour, f + 1);
        }
        if (four < 3){
            recurse(one, two, three, four + 1, sumone, sumtwo, sumthree, sumfour  + arr[f], f + 1);
        }
    }
}
int main(){
    for (int x = 0; x < 12; x ++){
        cin >> arr[x];
    }
    recurse(0, 0, 0, 0, 0, 0,0, 0 ,0);
    cout << best;

}
