#include <fstream>
#include <string>
#include <iostream>
#include <math.h>
#include <algorithm>
#include <cstdlib>
using namespace std;
#include <vector>
int n;
pair<int, int> cows[1001];


int main(){
    ifstream in("balancing.in");
    ofstream out("balancing.out");
    in >> n;
    int one, two, three, four;
    for (int x = 0; x < n; x++){
        in >> one >> two;
        cows[x].first = one;
        cows[x].second = two;
    }
    sort(cows, cows + n);
    one = 0;
    two = 0;
    three = 0;
    four = 0;
    int answer = 1000000;
    for (int x = 0; x < n; x++){
        one = 0;
        two = 0;
        three = 0;
        four = 0;
        int yline = cows[x].second + 1;
        for (int y = 0; y < n; y++){
            if (cows[y].second < yline){
                one++;
            }
            else{
                two++;
            }
        }
        for (int y = 0; y < n; y++){
            if (cows[y].second > yline){
                four++;
                two--;
            }
            else{
                three++;
                one--;
            }
            answer = min(answer, max(max(one, two), max(three, four)));
        }
    }
    out << answer << "\n";


}
