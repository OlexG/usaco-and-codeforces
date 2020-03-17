#include <fstream>
#include <string>
#include <iostream>
#include <math.h>
using namespace std;
#include <vector>

int main() {
    ifstream in("shuffle.in");
    ofstream out("shuffle.out");
    int n;
    in >> n;
    int shuffles[n];
    int cows[n];
     for (int x = 0; x < n; x ++){
        cows[x] = 0;
    }

    for (int x = 0; x < n; x ++){
        in >> shuffles[x];
        cows[shuffles[x] - 1] ++;
    }

    int answer = n;
    vector<int> q;
    for (int x = 0; x < n; x ++){
        if (cows[x] == 0){
                q.push_back(shuffles[x]);

        };
    }

    int index;
    while (q.size() != 0) {
        cows[q[q.size() - 1] - 1] --;
        answer --;
        index = q[q.size() - 1] - 1;
        q.pop_back();
        if (cows[index] == 0){
            q.push_back(shuffles[index]);
        }


    }
    out << answer << "\n";


}
