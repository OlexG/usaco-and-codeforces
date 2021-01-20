#include <fstream>
#include <string>
#include <iostream>
#include <math.h>
#include <algorithm>
#include<bits/stdc++.h>
#include <vector>
using namespace std;

int n, k;
vector<int> arr;
int main(){
    ifstream in("berries.in");
    ofstream out("berries.out");
    in >> n >> k;
    int temp;
    for (int x = 0; x < n; x++){
        in >> temp;
        arr.push_back(temp);
    }
    sort(arr.begin(), arr.end());
    int answer = 0;
    for (int b = 0; b <= 1000; b++){
        int curanswer = 0;
        bool works = true;
        multiset<int> c;
        for (int x = 0; x < n; x++){
            c.insert(arr[x]);
        }

        for (int x = 0; x < k/2; x++){
            if (*prev(c.end()) >= b){
                int newelem = *prev(c.end()) - b;
                c.erase(c.find(*prev(c.end())));
                c.insert(newelem);
            }
            else{
                works = false;
            }
        }

        multiset<int> cset;
        for (auto it:c){
            cset.insert(it);
        }

        if (works){
            for (int x = 0; x < k/2; x++){
                curanswer += min(b, *prev(cset.end()));
                int newelem = *prev(cset.end()) - min(b, *prev(cset.end()));
                cset.erase(cset.find(*prev(cset.end())));
                cset.insert(newelem);
                answer = max(answer, curanswer);
            }
        }
    }
    out << answer << "\n";
}
