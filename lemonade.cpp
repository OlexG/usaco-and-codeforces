#include <fstream>
#include <string>
#include <iostream>
#include <math.h>
#include <algorithm>
#include <vector>
using namespace std;
int n;
vector<int> cows;
vector<int> ncows;
int main(){
    ifstream in("lemonade.in");
    ofstream out("lemonade.out");
    in >> n;
    int first;
    for (int x = 0; x < n; x++){
        in >> first;
        cows.push_back(first);

    }
    sort(cows.rbegin(), cows.rend());
    for (int x = 0; x < n; x ++){
        if (cows[x] >= ncows.size()){
            ncows.push_back(cows[x]);
        }
    }
    out << ncows.size() << "\n";

}
