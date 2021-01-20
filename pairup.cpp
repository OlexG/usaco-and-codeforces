#include <fstream>
#include <string>
#include <iostream>
#include <math.h>
#include <algorithm>
#include <vector>
using namespace std;
int n;

int main(){
    ifstream in("pairup.in");
    ofstream out("pairup.out");
    in >> n;
    pair<int ,int> arr[n];
    int one, two;
    for (int x = 0; x < n; x++){in >> one >> two; arr[x] = make_pair(two, one);}
    sort(arr, arr + n);
    int y = 0;
    int x = n - 1;
    int bpair = 0;
    while(x != y){
        if (arr[x].first + arr[y].first > bpair)
        {
            bpair = arr[x].first + arr[y].first;
        }
        if (arr[x].second > arr[y].second){
            arr[x].second -= arr[y].second;
            y++;
        }
        else if (arr[x].second < arr[y].second){
            arr[y].second -= arr[x].second;
            x--;
        }
        else{
            x--;
            y++;
        }

    }
    out << bpair << "\n";

}
