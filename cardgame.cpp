#include <fstream>
#include <string>
#include <iostream>
#include <math.h>
#include <algorithm>
#include<bits/stdc++.h>
#include <vector>
using namespace std;

int n;
set<int> cards;
int main(){
    ifstream in("cardgame.in");
    ofstream out("cardgame.out");
    in >> n;
    for (int x = 1; x <= 2*n; x++){
        cards.insert(x);
    }
    int temp;
    vector<int> el;
    for (int x = 0; x < n; x++){
        in >> temp;
        el.push_back(temp);
        cards.erase(temp);
    }
    vector<int> c;
    for (auto it: cards){
        c.push_back(it);
    }
    int answer = 0;
    vector<int> fh;
    vector<int> sh;
    for (int x = 0; x < n/2; x++){
        fh.push_back(el[x]);
    }
    for (int x = n/2; x < n; x++){
        sh.push_back(el[x]);
    }
    sort(fh.rbegin(), fh.rend());
    sort(sh.begin(), sh.end());
    int pointer1 = c.size() - 1;
    int pointer2 = 0;
    while(pointer2 < n/2){
        if (c[pointer1] > fh[pointer2]){
            answer++;
            pointer2++;
            pointer1--;
        }
        else{
            pointer2++;
        }
    }
    pointer1 = 0;
    pointer2 = 0;
    while(pointer2 < n/2){
        if (c[pointer1] < sh[pointer2]){
            answer++;
            pointer2++;
            pointer1++;
        }
        else{
            pointer2++;
        }
    }


    out << answer << "\n";
}
