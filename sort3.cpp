/*
ID: alex.go2
LANG: C++11
PROB: sort3
*/
#include <fstream>
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;
int n;

int main(){
    ifstream in("sort3.in");
    ofstream out("sort3.out");
    in >> n;
    int arr[n];
    int og[n];
    int sizeone = 0;
    int sizetwo = 0;
    int sizethree = 0;
    for (int x = 0; x < n; x++){
        in >> arr[x];
        if (arr[x] == 1){
            sizeone++;
        }
        else if (arr[x] == 2){
            sizetwo++;
        }
        else{
            sizethree++;
        }
    }
    int twoin1 = 0;
    int threein1 = 0;
    int onein2 = 0;
    int threein2 = 0;
    int twoin3 = 0;
    int onein3 = 0;
    for (int x = 0; x < sizeone; x++){
        if (arr[x] == 2){
            twoin1++;
        }
        else if (arr[x] == 3){
            threein1++;
        }
    }
    for (int x = sizeone; x < sizeone + sizetwo; x++){
        if (arr[x] == 1){
            onein2++;
        }
        else if (arr[x] == 3){
            threein2++;
        }
    }
    for (int x = sizeone + sizetwo; x < sizeone + sizetwo + sizethree; x++){
        if (arr[x] == 1){
            onein3++;
        }
        else if (arr[x] == 2){
            twoin3++;
        }
    }
    int answer = 0;
    //try to switch the ones and twos
    int temp = min(twoin1, onein2);
    answer += temp;
    onein2 -= temp;
    twoin1 -= temp;
    if (onein2 > 0){
        threein1 -= onein2;
        threein2 += onein2;
        answer += onein2;
        onein2 = 0;
    }
    //
    //try to swtich threes and ones
    temp = min(threein1, onein3);
    answer += temp;
    threein1 -= temp;
    onein3 -= temp;
    if (onein3 > 0){
        twoin1 -= onein3;
        twoin3 += onein3;
        answer += onein3;
        onein3 = 0;
    }
    //try to swtich two and threes
    temp = min(twoin3, threein2);
    answer += temp;
    twoin3 -= temp;
    threein2 -= temp;

    out << answer << "\n";

}
