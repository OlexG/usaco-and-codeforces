#include <fstream>
#include <string>
#include <iostream>
#include <math.h>
#include <algorithm>
#include <vector>
using namespace std;
int n;

int main(){
    ifstream in("herding.in");
    ofstream out("herding.out");
    in >> n;
    int arr[n];
    for (int x = 0; x < n; x++){
        in >> arr[x];
    }
    sort(arr, arr + n);
    int ma = 0;
    int totals = 0;
    int mins = 1000000001;
    int spaces = 0;
    int doublespaces = 0;
    int cons = 1;
    int bestcons = 0;
    for (int x = 1; x < n; x++){
        if (arr[x] - arr[x - 1] > 1){
            spaces++;
            totals += (arr[x] - arr[x - 1] - 1);
            cons = 1;
        }
        else{
            cons += 1;
            bestcons = max(cons, bestcons);
        }
    }
    mins = min(arr[1] - arr[0] - 1, arr[n - 1] - arr[n - 2] - 1);


    if (spaces == 0){
        ma = 0;
    }
    else if (spaces == 1){
        ma = totals;
    }
    else{
        ma = totals-mins;
    }



    int point1 = 0;
    int point2 = 0;
    int best = 1;
    while(point2 < n){
        if (arr[point2] - arr[point1] > n){
            point1++;
        }
        else{
            point2++;
            best = max(best, point2 - point1);
        }
    }
    if (n - best == 0){
        if (arr[n - 1] - arr[n - 2] > 1 || arr[1] - arr[0] > 1){
            best -= 1;
        }
    }
    else if (n - best == 1){

        if (arr[n - 1] - arr[n - 2] >= 2 && arr[1] - arr[0] == 1){
            best -= 1;
        }
        if (arr[n - 1] - arr[n - 2] == 1 && arr[1] - arr[0] >= 2){
            best -= 1;
        }
    }
    out << n - best << "\n";
    out << ma << "\n";
}
