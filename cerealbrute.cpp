#include <fstream>
#include <string>
#include <iostream>
#include <math.h>
#include <algorithm>
using namespace std;
int n, m;
vector<pair<int ,int>> milks;
int arr[100000];
int got[100000];
int main(){
    ifstream in("cereal.in");
    ofstream out("cereal.out");
    in >> n >> m;
    int one, two;
    for (int x = 0; x < n; x++){
        in >> one >> two;
        milks.push_back(make_pair(one ,two));
        got[x] = 0;
    }
    for (int x = 0; x < m; x++){
        arr[x] = m + 1;
    }
    int answer = 0;
    for (int y = 0; y < n; y++){
        answer = 0;
        for (int x = 0; x < m; x++){
            arr[x] = 1;
        }
        for(int x = y; x < n; x++){
            if (arr[milks[x].first - 1]){
                answer++;
                arr[milks[x].first - 1] = 0;

            }
            else if(arr[milks[x].second - 1]){
                answer++;
                arr[milks[x].second - 1] = 0;
            }

        }
        out << answer << "\n";
    }

}
