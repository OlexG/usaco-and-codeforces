#include <fstream>
#include <string>
#include <iostream>
#include <bitset>
#include <math.h>
#include <string>
#include <algorithm>
#include<bits/stdc++.h>
#include <vector>
using namespace std;

long long n, b;
vector<pair<long long, long long>> bales;
int bp = 0;
bool ok(long long cur){
    int p2 = bp;
    for (int x = bp - 1; x >= 0; x--){
        while(p2 < n){
            if (bales[p2].first - bales[x].first <= bales[p2].second){
                break;
            }
            p2++;
        }
        if (p2 >= n){
            break;
        }
        if (bales[p2].first - bales[x].first <= bales[x].second + cur){
            //cout << bales[x].first << " " << bales[x].second << "\n";
            //cout << bales[p2].first << " " << bales[p2].second << "\n";
            return true;
        }
    }
    p2 = bp - 1;
    for (int x = bp; x < n; x++){
        while(p2 >= 0){
            if (bales[x].first - bales[p2].first <= bales[p2].second){
                break;
            }
            p2--;
        }
        if (p2 < 0){
            break;
        }
        if (bales[x].first - bales[p2].first <= bales[x].second + cur){
            return true;
        }
    }
    return false;

}
int main(){
    ifstream in("trapped.in");
    ofstream out("trapped.out");
    in >> n >> b;
    long long one, two;

    for (int x = 0; x < n; x++){
        in >> one >> two;
        bales.push_back(make_pair(two, one));
    }
    sort(bales.begin(), bales.end());
    //bp points to the first haybale in front
    for (int x = 0; x < n; x++){
        if (b > bales[x].first){
            bp = x + 1;
        }
    }
    long long mi = 0;
    long long ma = 1000000001;
    //cout << ok(0) << "\n";
    while(mi < ma){
        long long mid = (ma + mi)/2;
        if (ok(mid)){
            ma = mid;
        }
        else{
            mi = mid + 1;
        }
    }
    if (ma == 1000000001){
        out << -1 << "\n";
    }
    else{
        out << ma << "\n";
    }
}
