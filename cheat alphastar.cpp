#include <fstream>
#include <string>
#include <iostream>
#include <math.h>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;


int n, m, k;
queue <int> cards;
vector<int> bessy;
int main(){
    cin >> n >> m >> k;
    for (int x = 1; x < m + 1; x++){
        cards.push(x);
    }
    int cur = 1;
    while(cards.empty() == false){
        if (cur % n == 0){
            cur = 1;
            bessy.push_back(cards.front());
            cards.pop();
        }
        else{
            cur++;
            cards.pop();
        }
        for (int x = 0; x < k; x++){
            int temp = cards.front();
            cards.push(temp);
            cards.pop();
        }
    }
    sort(bessy.begin(), bessy.end());
    for (int x = 0; x < bessy.size(); x++){
        cout << bessy[x] << "\n";
    }

}
