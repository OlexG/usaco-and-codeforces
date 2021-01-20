#include <fstream>
#include <string>
#include <iostream>
#include <math.h>
#include <vector>
#include <bitset>
#include <algorithm>
#include <map>
using namespace std;
struct Node {
   int value = -1;
};

bool answer = true;
int n, m;
vector<pair<int, int>> cons[100001];
pair<int, int> eq[100001];
map<long long, Node> mcons;
double answers[100001];
vector<int> curcheck;
bool loop = false;
int lstart = 0;
double lstartval = 0;
int used[100001];
int used2[100001];
void gdfs(int cur, double val){
    answers[cur] = val;
    used2[cur] = 2;
    for (int x = 0; x < cons[cur].size(); x++){
        if (used2[cons[cur][x].first] == 1){
            gdfs(cons[cur][x].first, cons[cur][x].second - val);
        }
    }
}
void nldfs(int cur){
    used[cur] = 2;
    curcheck.push_back(cur);
    for (int x = 0; x < cons[cur].size(); x++){
        if (used[cons[cur][x].first] == 1){
            eq[cons[cur][x].first] = make_pair(-1 * eq[cur].first, cons[cur][x].second - eq[cur].second);
            nldfs(cons[cur][x].first);
        }
        else{
            if (loop == false){
                if (eq[cur].first - eq[cons[cur][x].first].first == 0){
                    loop = true;
                    lstartval = (double)(cons[cur][x].second - (eq[cur].second + eq[cons[cur][x].first].second))/(double)(eq[cur].first + eq[cons[cur][x].first].first);
                }
            }
        }
    }
}

int main(){
    cin >> n >> m;
    for (int x = 0; x < n; x++){
        eq[x] = make_pair(-1, -1);
        answers[x] = 0;
        used[x] = 1;
        used2[x] = 1;
    }

    int one, two, three;
    bool test = true;
    for (int x = 0; x < m; x++){
        cin >> one >> two >> three;
        if (mcons.count((long long)one * 10000000 + two) > 0){
            if (mcons[(long long)one * 10000000 + two].value != three){
                if (mcons[(long long)one * 10000000 + two].value == 1 || mcons[(long long)one * 10000000 + two].value == 2){
                    answer = false;
                }
            }
        }
        if (answer){
            mcons[(long long)one * 10000000 + two].value = three;
            mcons[(long long)two * 10000000 + one].value = three;

            if (one == two){
                cons[one - 1].push_back(make_pair(two - 1, three));
            }
            else{
                cons[one - 1].push_back(make_pair(two - 1, three));
                cons[two - 1].push_back(make_pair(one - 1, three));
            }
        }

    }
    if (answer){
        for (int x = 0; x < n; x++){
            if (used[x] == 1){
                curcheck.clear();
                loop = false;
                eq[x] = make_pair(1, 0);
                nldfs(x);
                if (loop){
                    lstart = x;
                    gdfs(lstart, lstartval);
                }
                else{
                    vector<int> bs;
                    for (int y = 0; y < curcheck.size(); y++){
                        bs.push_back(eq[curcheck[y]].second * -1 * eq[curcheck[y]].first);
                    }
                    sort(bs.begin(), bs.end());
                    double result;
                    if (bs.size() % 2  == 1){
                        result = bs[bs.size()/2];
                    }
                    else{
                        result = (double)(bs[bs.size()/2] + bs[bs.size()/2 - 1])/2.0;
                    }
                    for (int y = 0; y < curcheck.size(); y++){
                        answers[curcheck[y]] = eq[curcheck[y]].first * result + eq[curcheck[y]].second;
                    }
                }
            }
        }
    }
    for (int x = 0; x < n; x++){
        for (int y = 0; y < cons[x].size(); y++){
            if (answers[cons[x][y].first] + answers[x] != cons[x][y].second){
                if (n == 100000 && m == 99999){
                    cout << eq[x].first << " " << eq[x].second << " " << eq[cons[x][y].first].first << " " << eq[cons[x][y].first].second << "\n";
                    cout << answers[cons[x][y].first] << " " << answers[x] << " " << cons[x][y].second << "\n";
                }
                answer = false;
            }
        }
    }
    if (answer){
        cout << "YES\n";
        for (int x = 0; x < n; x++){
            cout << answers[x] << " ";
        }
        cout << "\n";
    }
    else{
        cout << "NO\n";
    }
}
