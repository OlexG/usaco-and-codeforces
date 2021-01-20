#include <fstream>
#include <string>
#include <iostream>
#include <math.h>
#include <algorithm>
#include <vector>
using namespace std;
int n, k;

struct point{
    long long first;
    long long second;
    long long index;
};
vector<point> ocows;
vector<point> scows;
bool compone(point a, point b){
    return a.first > b.first;
}
bool comptwo(point a, point b){
    return a.second > b.second;
}
int main(){
    cin >> n >> k;
    long long one, two;
    for (int x = 0; x < n; x++){
        cin >> one >> two;
        point temp;
        temp.first = one;
        temp.second = two;
        temp.index = x + 1;
        ocows.push_back(temp);
    }
    sort(ocows.begin(), ocows.end(), compone);
    for (int x = 0; x < k; x++){
        scows.push_back(ocows[x]);
    }
    sort(scows.begin(), scows.end(), comptwo);
    cout << scows[0].index;

}
