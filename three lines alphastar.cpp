#include <fstream>
#include <string>
#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
using namespace std;


int n;
vector<pair<int, int>> arr;
vector<int> used;
int answer = 0;

void rec(int cur, string cura){
    if (cur == 3){
        bool works = true;
        for (int x = 0; x < n; x++){
            if (used[x] == 1){
                works = false;
            }
        }
        if (works){
            answer = 1;
        }
    }
    else{
        bool alldone = true;
        int ind = 0;
        for (int x = 0; x < n; x++){
            if (used[x] == 1){
                alldone = false;
                ind = x;
                break;
            }
        }
        if (alldone){
            answer = 1;
        }
        else{
            vector<int> changed;
            for (int x = 0; x < n; x++){
                if (arr[x].first == arr[ind].first && used[x] == 1){
                    changed.push_back(x);
                    used[x] = 0;
                }
            }

            rec(cur + 1, cura + " x is" + to_string(arr[ind].first));
            for (int x = 0; x < changed.size(); x++){
                used[changed[x]] = 1;
            }

            changed.clear();
            for (int x = 0; x < n; x++){
                if (arr[x].second == arr[ind].second && used[x] == 1){
                    used[x] = 0;
                    changed.push_back(x);
                }
            }
            rec(cur + 1, cura + " y is" + to_string(arr[ind].second));
            for (int x = 0; x < changed.size(); x++){
                used[changed[x]] = 1;
            }

        }
    }
}
int main(){
    cin >> n;
    int one, two;
    for (int x = 0; x < n; x++){
        cin >> one >> two;
        arr.push_back(make_pair(one, two));
        used.push_back(1);
    }
    rec(0, "");
    cout << answer;
}
