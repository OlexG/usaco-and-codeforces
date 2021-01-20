#include <fstream>
#include <string>
#include <iostream>
#include <math.h>
#include <algorithm>
#include <vector>
using namespace std;
int n, m;
pair<int, int> cows[100000];
pair<int, int> cm[100000];

int main(){
    ifstream in("cereal.in");
    ofstream out("cereal.out");
    in >> n >> m;
    int one, two;
    for (int x = 0; x < n; x++){
        in >> one >> two;
        cows[x] = make_pair(one, two);
    }
    for (int x = 0; x < m; x++){
        cm[x] = make_pair(0,0);
    }
    int answers[n];
    int cur = 0;
    for (int x = n - 1; x >= 0; x--){
        cur += 1;
        int wanted = cows[x].first - 1;
        int cow = x;
        int needed = 1;
        while(true){
            if (cm[wanted].first == 0){
                cm[wanted].first = cow;
                cm[wanted].second = needed;
                break;
            }
            else{
                if (cm[wanted].first < cow){
                    cur--;
                    break;
                }
                else{
                    if (cm[wanted].second == 2){
                        cm[wanted].first = cow;
                        cm[wanted].second = needed;
                        cur--;
                        break;
                    }
                    else{
                        int newwanted = cows[cm[wanted].first].second - 1;
                        int newcow = cm[wanted].first;
                        cm[wanted].first = cow;
                        cm[wanted].second = needed;
                        wanted = newwanted;
                        cow = newcow;
                        needed = 2;
                    }
                }
            }
        }
        answers[x] = cur;

    }
    for (int x = 0; x < n; x++){
        out << answers[x] << "\n";
    }

}
