#include <fstream>
#include <string>
#include <iostream>
#include <math.h>
#include <algorithm>
#include <vector>
using namespace std;

int n, q;
string s;
vector<pair<pair<int, char>, int>> qs;
bool csort(pair<pair<char, int>, int> a, pair<pair<char, int>, int> b){
    if (a.first.second == b.first.second){
        return a.first.first < b.first.first;
    }
    else{
        return a.first.second < b.first.second;
    }
}
int main(){
    cin >> n >> s >> q;
    int one;
    char two;
    for (int x = 0; x < q; x++){
        cin >> one >> two;
        qs.push_back(make_pair(make_pair(one ,two), x));
    }
    int answers[q];
    sort(qs.begin(), qs.end());
    int prevanswer = 0;
    for (int x = 0; x < q; x++){
        if (x > 0 && qs[x - 1].first.first == qs[x].first.first && qs[x - 1].first.second == qs[x].first.second){
            answers[qs[x].second] = prevanswer;
        }
        else{
            int point1 = 0;
            int point2 = 0;

            int avsize = qs[x].first.first - 1;
            char need = qs[x].first.second;
            if (s[0] == need){
                avsize += 1;
            }
            int best = 1;
            while(point2 < n){
                best = max(best, point2 - point1 + 1);
                if (avsize == 0){
                    if (point2 < n - 1){
                        if (s[point2 + 1] == need){
                            point2++;
                            best = max(best, point2 - point1 + 1);
                            continue;
                        }
                    }
                    if (s[point1] == need){
                        point1 += 1;
                    }
                    else{
                        point1 += 1;
                        avsize += 1;
                    }
                }
                else{
                    point2 += 1;
                    if (point2 >= n){
                        best = max(best, point2 - point1);
                        break;
                    }
                    if (s[point2] != need){
                        avsize--;
                    }
                    best = max(best, point2 - point1 + 1);
                }
            }
            answers[qs[x].second] = best;
            prevanswer = best;
        }
    }
    for (int x = 0; x < q; x++){
        cout << answers[x] << "\n";
    }



}
