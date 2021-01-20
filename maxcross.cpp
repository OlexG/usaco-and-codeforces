#include <fstream>
#include <iostream>
#include <string>
#include <iostream>
#include <math.h>
#include <algorithm>
#include <vector>
using namespace std;
int n, k, b;
vector<pair<int ,int>> cros;
int main(){
    ifstream in("maxcross.in");
    ofstream out("maxcross.out");
    in >> n >> k >> b;
    for (int x = 1; x <= n; x++){
        cros.push_back(make_pair(x, 0));
    }
    int num;
    for (int x = 0; x < b; x++){
        in >> num;
        cros[num - 1].second = 1;
    }
    int answer = 0;;
    int curbroken = 0;;
    for (int x = 0; x < k; x++){
        if (cros[x].second){
            curbroken ++;
        }
    }

    answer = curbroken;
    for (int x = k; x < n; x++){
        if (cros[x - k].second){
            curbroken--;
        }
        if (cros[x].second){
            curbroken++;
        }
        if (curbroken < answer){
            answer = curbroken;
        }
    }
    out << answer << "\n";

}
