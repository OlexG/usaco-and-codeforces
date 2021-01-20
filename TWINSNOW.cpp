#pragma GCC optimize("O2")
#include <fstream>
#include <string>
#include <iostream>
#include <bitset>
#include <math.h>
#include <string>
#include <algorithm>
#include<bits/stdc++.h>
#include <vector>
#include <queue>
#define ll long long
using namespace std;

ll n;
struct snow{
    ll a,b,c,d,e,f;
};

bool csort(snow one, snow two){
    if (one.a == two.a && one.b == two.b && one.c == two.c && one.d == two.d && one.e == two.e){
        return one.f <= two.f;
    }
    else if (one.a == two.a && one.b == two.b && one.c == two.c && one.d == two.d){
        return one.e <= two.e;
    }
    else if (one.a == two.a && one.b == two.b && one.c == two.c){
        return one.d <= two.d;
    }
    else if (one.a == two.a && one.b == two.b){
        return one.c <= two.c;
    }
    else if (one.a == two.a){
        return one.b <= two.b;
    }
    else{
        return one.a <= two.a;
    }
}
bool eq(snow one, snow two){
    return (one.a == two.a && one.b == two.b && one.c == two.c && one.d == two.d && one.e == two.e && one.f == two.f);
}
int main(){
    cin >> n;
    int a,b,c,d,e,f;
    vector<snow> snows;
    for (int x = 0; x < n; x++){
        cin >> a >> b >> c >> d >> e >> f;
        snows.push_back({a,b,c,d,e,f});
        snows.push_back({b,c,d,e,f,a});
        snows.push_back({c,d,e,f,a,b});
        snows.push_back({d,e,f,a,b,c});
        snows.push_back({e,f,a,b,c,d});
        snows.push_back({f,a,b,c,d,e});

        snows.push_back({f,e,d,c,b,a});
        snows.push_back({e,d,c,b,a,f});
        snows.push_back({d,c,b,a,f,e});
        snows.push_back({c,b,a,f,e,d});
        snows.push_back({b,a,f,e,d,c});
        snows.push_back({a,f,e,d,c,b});
    }
    sort(snows.begin(), snows.end(), csort);
    bool found = false;
    for (int x = 1; x < snows.size(); x++){
        if (eq(snows[x], snows[x - 1])){
            found = true;
        }
    }
    if (found){
        cout << "Twin snowflakes found.\n";
    }
    else{
        cout << "No two snowflakes are alike.\n";
    }
}
