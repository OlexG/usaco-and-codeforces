#include <fstream>
#include <string>
#include <iostream>
#include <math.h>
#include <algorithm>
#include <cstdlib>
using namespace std;
#include <vector>
int n;
vector<pair<int ,int>> cows;
int main(){
    cin >> n;
    int one, two;
    for (int x = 0; x < n; x++){
        cin >> one >> two;
        cows.push_back(make_pair(one ,two));
    }
    sort(cows.begin(), cows.end());
    int curstart = cows[0].first;
    int curstop = cows[0].second;
    int bestcomb = curstop - curstart;
    int bestnone = 0;
    for (int x = 1; x < n; x++){
        if (cows[x].second > curstop){
            if (cows[x].first > curstop){
                bestnone = max(bestnone, cows[x].first - curstop);
                curstart = cows[x].first;
                curstop = cows[x].second;
            }
            else{
                curstop = curstop + cows[x].second - curstop;
                bestcomb = max(bestcomb, curstop-curstart);

            }
        }
    }
    cout << bestcomb << " " << bestnone;
}
