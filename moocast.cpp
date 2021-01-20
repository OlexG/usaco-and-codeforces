#include <fstream>
#include <string>
#include <iostream>
#include <math.h>
#include <algorithm>
#include <cstdlib>
using namespace std;
#include <vector>
int n;
int cows[200][3];
string used;
vector<int> arr[200];
float dist(int x1, int y1, int x2, int y2){
    return (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);
}
int total = 0;
void rec(int x){
    used[x] = '1';
    total++;
    for (int y = 0; y < arr[x].size(); y++){
        if (used[arr[x][y]] == '0'){
            rec(arr[x][y]);
        }
    }
}
int main(){
    ifstream in("moocast.in");
    ofstream out("moocast.out");
    in >> n;

    for (int x = 0; x < n; x++){
        in >> cows[x][0] >> cows[x][1] >> cows[x][2];
    }
    for (int x = 0; x < n; x++){
        for (int y = 0; y < n; y++){
            if (x != y){
                if (dist(cows[x][0], cows[x][1], cows[y][0], cows[y][1]) <= cows[x][2] * cows[x][2]){
                    arr[x].push_back(y);

                }
            }
        }
    }
    int answer = 0;
    for (int x = 0; x < n; x++){
        used = "";
        total = 0;
        for (int y = 0; y < n; y++){
            used += '0';
        }
        rec(x);
        answer = max(answer,total);
    }
    out << answer << "\n";


}
