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
#include<stdio.h>
#include<ctype.h>
#define ll long long
using namespace std;

ll t;
ll n;
struct box{
    ll a;
    ll o;
    ll i;
};

bool csort(box one, box two){
    return (one.a + one.o) < (two.a + two.o);
}
bool csorta(box one, box two){
    return one.a < two.a;
}
bool csorto(box one, box two){
    return one.o < two.o;
}
vector<box> boxes;
vector<box> curused;
int main(){
    cin >> t;
    for (int z = 0; z < t; z++){
        cin >> n;
        boxes.clear();
        curused.clear();
        ll a, b;
        ll ta = 0;
        ll tb = 0;
        ll ca = 0;
        ll cb = 0;
        for (int x = 0; x < 2*n - 1; x++){
            cin >> a >> b;
            ta += a;
            tb += b;
            boxes.push_back({a, b, x + 1});
        }
        ta = (ta + 1)/2;
        tb = (tb + 1)/2;
        sort(boxes.begin(), boxes.end(), csorta);
        bool even = false;
        for (int x = 2*n - 2; x >= 0; x-=2){
            cb += boxes[x].o;
        }
        if (cb >= tb){
            even = true;
        }
        if (even){
            cout << "YES\n";
            for (int x = 2*n - 2; x >= 0; x-=2){
                cout << boxes[x].i << " ";
            }
            cout << "\n";
        }
        else{
            cout << "YES\n";
            for (int x = 2*n - 3; x >= 0; x-=2){
                cout << boxes[x].i << " ";
            }
            cout << boxes[2*n - 2].i << " ";
            cout << "\n";
        }
    }
}
