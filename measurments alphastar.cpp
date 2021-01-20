#include <fstream>
#include <string>
#include <iostream>
#include <algorithm>
#include <map>
#include <set>
using namespace std;
int n;
long long g;
struct change{
    long long day;
    long long id;
    long long amount;
};
bool compare(change a, change b){
    return (a.day < b.day);
}

change arr[100000];
int main(){
    cin >> n >> g;
    long long one, two, three;

    for (int x = 0; x < n; x++){
        change temp;
        cin >> one >> two >> three;
        temp.day = one;
        temp.id = two;
        temp.amount = three;
        arr[x] = temp;
    }
    sort(arr, arr + n, compare);
    map<long long, long long> milkamount;
    map<long long, set<long long>> amtcows;
    for (int x = 0; x < n; x++){
        amtcows[g].insert(arr[n].id);
        milkamount[arr[x].id] = g;
    }
    int answer = 0;
    for (int x = 0; x < n; x++){
        set<long long> leaderboard = (*amtcows.rbegin()).second;
        amtcows[milkamount[arr[x].id]].erase(arr[x].id);
        if (amtcows[milkamount[arr[x].id]].empty()){
            amtcows.erase(milkamount[arr[x].id]);
        }
        milkamount[arr[x].id] += arr[x].amount;
        amtcows[milkamount[arr[x].id]].insert(arr[x].id);
        if (leaderboard != (*amtcows.rbegin()).second){
            answer++;
        }


    }
    cout << answer;
}
