#include <fstream>
#include <string>
#include <iostream>
#include <math.h>
#include <algorithm>
#include <vector>
using namespace std;
int n;
bool myComparison(const pair<int,int> &a,const pair<int,int> &b)
{
       return a.second<b.second;
}
vector<pair<long long ,long long>> sortedx;
vector<pair<long long ,long long>> sortedy;
vector<pair<long long, long long>> actual;
int main(){
    ifstream in("reduce.in");
    ofstream out("reduce.out");
    in >> n;
    int one, two;
    for (int x = 0; x < n; x++){
        in >> one >> two;
        sortedx.push_back(make_pair(one, two));
        sortedy.push_back(make_pair(one ,two));
        actual.push_back(make_pair(one, two));
    }
    sort(sortedx.begin(), sortedx.end());
    sort(sortedy.begin(),sortedy.end(),myComparison);
    long long answer = 100000000000;
    for (int x = 0; x < 4; x++){
        for (int y = 0; y < 4; y++){
            for (int z = 0; z < 4; z++){
                pair<long long, long long> one;
                vector<pair<long long ,long long>> copysortedx;
                vector<pair<long long  ,long long>> copysortedy;
                vector<pair<long long, long long>> copyactual;
                for (int c = 0; c < n; c++){
                    copysortedx.push_back(sortedx[c]);
                }
                 for (int c = 0; c < n; c++){
                    copysortedy.push_back(sortedy[c]);
                }
                 for (int c = 0; c < n; c++){
                    actual.push_back(actual[c]);
                }
                if (x == 0){
                    one = copysortedx[0];
                }
                if (x == 1){
                    one = copysortedx[copysortedx.size() - 1];
                }
                if (x == 2){
                    one = copysortedy[0];
                }
                if (x == 3){
                    one = copysortedy[copysortedy.size() - 1];
                }
                 for (int c = copysortedy.size() - 1; c >= 0; c--){
                    if (copysortedx[c] == one){
                        copysortedx.erase(copysortedx.begin() + c);
                    }
                    if (copysortedy[c] == one){
                        copysortedy.erase(copysortedy.begin() + c);
                    }
                }
                //AGAIN REPEAT
                if (y == 0){
                    one = copysortedx[0];
                }
                if (y == 1){
                    one = copysortedx[copysortedx.size() - 1];
                }
                if (y == 2){
                    one = copysortedy[0];
                }
                if (y == 3){
                    one = copysortedy[copysortedy.size() - 1];
                }
                for (int c = copysortedy.size() - 1; c >= 0; c--){
                    if (copysortedx[c] == one){
                        copysortedx.erase(copysortedx.begin() + c);
                    }
                    if (copysortedy[c] == one){
                        copysortedy.erase(copysortedy.begin() + c);
                    }
                }
                //AGAIN REPEAT
                if (z == 0){
                    one = copysortedx[0];
                }
                if (z == 1){
                    one = copysortedx[copysortedx.size() - 1];
                }
                if (z == 2){
                    one = copysortedy[0];
                }
                if (z == 3){
                    one = copysortedy[copysortedy.size() - 1];
                }
                for (int c = copysortedy.size() - 1; c >= 0; c--){
                    if (copysortedx[c] == one){
                        copysortedx.erase(copysortedx.begin() + c);
                    }
                    if (copysortedy[c] == one){
                        copysortedy.erase(copysortedy.begin() + c);
                    }
                }
                answer = min(answer, (copysortedx[copysortedx.size() - 1].first - copysortedx[0].first) * (copysortedy[copysortedy.size() - 1].second - copysortedy[0].second));

            }
        }
    }
    out << answer << "\n";
}
