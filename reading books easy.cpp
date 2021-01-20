#include <fstream>
#include <string>
#include <iostream>
#include <math.h>
#include <algorithm>
#include <vector>
using namespace std;

int n, k;
vector<pair<float, pair<int ,int>>> books;
vector<pair<float, pair<int ,int>>> needtobematchedz;
vector<pair<float, pair<int ,int>>> needtobematchedo;
int main(){
    cin >> n >> k;
    int one, two, three;
    for (int x = 0; x < n; x++){
        cin >> one >> two >> three;
        if (three == 1 && two == 1){
            books.push_back(make_pair(one, make_pair(two, three)));
        }
        else if (two == 1 || three == 1){
            if (two == 1){
                needtobematchedo.push_back(make_pair(one, make_pair(two, three)));
            }
            else{
                needtobematchedz.push_back(make_pair(one, make_pair(two, three)));
            }
        }
    }
    int k1 = k;
    int totalreadingtime = 0;
    sort(needtobematchedz.begin(), needtobematchedz.end());
    sort(needtobematchedo.begin(), needtobematchedo.end());
    for (int x = 0; x < min(needtobematchedo.size(), needtobematchedz.size()); x++){
        books.push_back(make_pair(needtobematchedo[x].first + needtobematchedz[x].first, make_pair(1, 1)));
    }
    sort(books.begin(), books.end());
    /*for (int x = 0; x < books.size(); x++){
        cout << books[x].first << " " << books[x].second.first << " " << books[x].second.second << "\n";
    }*/
    int counter = 0;
    bool answer = true;
    while(k1 > 0){
        if (counter >= books.size()){
            answer = false;
            break;
        }
        totalreadingtime += books[counter].first;
        k1 -= 1;
        counter++;
    }

    if (answer){
        cout << totalreadingtime << "\n";
    }
    else{
        cout << -1;
    }
}
