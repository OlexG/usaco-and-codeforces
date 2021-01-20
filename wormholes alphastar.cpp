#include <fstream>
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;
vector<pair<int, int>> arr;
int n;
int toright[13];
int partner[13];
int answer = 0;
bool sorted(pair<int, int> a, pair<int, int> b){
    if (a.second == b.second){
        return a.first < b.first;
    }
    else{
        return a.second < b.second;
    }
}
int used[12];
bool check(int cur){
    if (used[cur] == 2){
        return true;
    }
    else if (toright[cur] == -1){
        return false;
    }
    else {
        used[cur] = 2;
        return check(partner[toright[cur]]);
    }
}
void p(int ind){
    if (ind == n){

        int works = false;
        for (int x = 0; x < n; x++){
            for (int x = 0; x < n; x++){
                used[x] = 1;
            }
            works = check(x);
            if (works){
                break;
            }
        }
        if (works){
            answer++;
        }
    }
    else if (partner[ind] == -1){
        for (int x = 0; x < n; x++){
            if (x != ind && partner[x] == -1){
                partner[ind] = x;
                partner[x] = ind;
                p(ind + 1);
                partner[ind] = -1;
                partner[x] = -1;
            }
        }
    }
    else{
        p(ind + 1);
    }
}
int main(){
    cin >> n;
    int one, two;
    for (int x = 0; x < n; x++){
        cin >> one >> two;
        arr.push_back(make_pair(one, two));
        used[x] = 1;
        toright[x] = -1;
        partner[x] = -1;
    }

    sort(arr.begin(), arr.end(), sorted);
    for (int x = 0; x < arr.size() - 1; x++){
        if (arr[x].second == arr[x + 1].second){
            toright[x] = x + 1;
        }
    }
    p(0);
    cout << answer << "\n";

}
