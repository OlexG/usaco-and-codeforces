#include <fstream>
#include <string>
#include <iostream>
#include <math.h>
#include <algorithm>
#include <vector>
using namespace std;
int n, b;
int answer = 9999;
long long arr[251];
bool notbeenthere[250][250];
vector< pair<long long, long long> > boots;
void rec(int where, int boot){


    if (notbeenthere[where][boot]){
        notbeenthere[where][boot] = false;
        if (where >= n - 1){
            answer = min(answer, boot);
        }
        for(int x = where; x < n && x < where + boots[boot].second + 1; x++){
            if (arr[x] <= boots[boot].first){
                rec(x, boot);
            }
        }
        for (int x = boot; x < b; x++){
            if (arr[where] <= boots[x].first){
                rec(where, x);
            }
        }

    }
}
int main(){
    ifstream in("snowboots.in");
    ofstream out("snowboots.out");
    in >> n >> b;
    for (int x = 0; x < n; x ++){
        in >> arr[x];
         for (int y = 0; y < b; y ++){
            notbeenthere[x][y] = true;
        }
    }
    long long one, two;
    for (int x = 0; x < b; x ++){
        in >> one >> two;
        boots.push_back(make_pair(one, two));

    }
    rec(0,0);
    out << answer;

}
