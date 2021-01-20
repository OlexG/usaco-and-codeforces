#include <fstream>
#include <string>
#include <iostream>
#include <algorithm>
#include <math.h>
#include <map>
#include <string>
using namespace std;
#include <vector>
int n;
map<string, int> states;
vector<string> q;
int main(){
    ifstream in("citystate.in");
    ofstream out("citystate.out");
    in >> n;
    string one, two;
    int answer = 0;
    string index;
    for (int x = 0; x < n; x++){
        in >> one >> two;
        index = two;
        q.push_back(one.substr(0, 2) + two);
        if (states.count(one.substr(0, 2) + two)){
            states[one.substr(0, 2) + two] ++;
        }
        else{
            states[one.substr(0, 2) + two] = 1;
        }

    }
    for (int x = 0; x < n; x++){
        if (q[x].substr(0, 2) != q[x].substr(2, 2)){
            answer += states[q[x].substr(2, 2) + q[x].substr(0, 2)];
        }
    }

    out << answer/2 << "\n";

}
