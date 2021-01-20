#include <fstream>
#include <string>
#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
using namespace std;

int n;
vector<pair<long long, long long>> shifts;
long long calc(int index){
    if (shifts[index - 1].second > shifts[index].second){
        return 0;
    }
    else{
        if (shifts[index + 1].second < shifts[index].second){
            if (shifts[index].first > shifts[index - 1].second){
                return shifts[index].second - shifts[index].first;
            }
            return shifts[index].second - shifts[index - 1].second;
        }
        else if  (shifts[index].second < shifts[index + 1].first){
            if (shifts[index].first > shifts[index - 1].second){
                return shifts[index].second - shifts[index].first;
            }
            return shifts[index].second - shifts[index - 1].second;
        }
        else{
            return shifts[index].second - shifts[index - 1].second - (shifts[index].second - shifts[index + 1].first);
        }
    }
}
long long calcone(){
    if (shifts[0].second > shifts[1].second){
        return shifts[0].second - shifts[0].first;
    }
    else if (shifts[0].second < shifts[1].first){
        return shifts[0].second - shifts[0].first;
    }
    else{
        return shifts[1].first - shifts[0].first;
    }
}
long long calclast(){
    if (shifts[n - 1].second > shifts[n - 2].second && shifts[n - 1].first > shifts[n - 2].second){
        return shifts[n - 1].second - shifts[n - 1].first;
    }
    else  if (shifts[n - 1].second < shifts[n - 2].second){
        return 0;
    }
    else{
        return shifts[n - 1].second - shifts[n - 2].second;
    }
}
int main(){
    cin >> n;
    long long one, two;
    long long forw[n];
    long long backw[n];
    for (int x = 0; x < n; x++){
        cin >> one >> two;
        shifts.push_back(make_pair(one, two));
    }
    sort(shifts.begin(), shifts.end());

    long long smallest = 100000000;
    int sindex = 0;
    if (calcone() < smallest){
        smallest = calcone();
        sindex = 0;
    }
    for (int x = 1; x < n - 1; x++){
        if (calc(x) < smallest){
            smallest = calc(x);
            sindex = x;
        }
    }
    if (calclast() < smallest){
        sindex = n - 1;
    }
    shifts.erase(shifts.begin() + sindex);
    int answer = 0;
    long long curmax = 0;
    for (int x = 0; x < n - 1; x++){
        if (shifts[x].first > curmax){
            answer += shifts[x].second - shifts[x].first;

            curmax = shifts[x].second;
        }
        else if (shifts[x].second > curmax){
            answer += shifts[x].second - curmax;
            curmax = shifts[x].second;
        }
    }
    cout << answer;
}
