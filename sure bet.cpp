#include <fstream>
#include <string>
#include <iostream>
#include <math.h>
#include <algorithm>
#include<bits/stdc++.h>
#include <vector>
using namespace std;

int n;

int main(){
    cin >> n;
    vector<double> a(n);
    vector<double> b(n);
    double cab = 0;
    double cbb = 0;
    for (int x = 0; x < n; x++){
        cin >> a[x];
        cin >> b[x];
    }
    sort(a.rbegin(), a.rend());
    sort(b.rbegin(), b.rend());
    int p1 = 0;
    int p2 = 0;
    int tbets = 0;
    double answer = 0;
    while(p1 < n){
        cab += a[p1];
        tbets += 1;
        if (cbb < cab){
            while(p2 < n && cbb < cab){
                cbb += b[p2];
                tbets += 1;
                p2++;
                if (cab - tbets < 0){
                    break;
                }
            }
        }
        p1++;
        if (cab <= cbb){
            answer = max(answer, cab - tbets);
        }
    }
    p2 = 0;
    p1 = 0;
    cab = 0 ;
    cbb = 0;
    tbets = 0;
    while(p2 < n){
        cbb += b[p2];
        tbets += 1;
        if (cab < cbb){
            while(p1 < n && cab < cbb){
                cab += a[p1];
                tbets += 1;
                p1++;
                if (cbb - tbets < 0){
                    break;
                }
            }
        }
        p2++;
        if (cab >= cbb){
            answer = max(answer, cbb - tbets);
        }
    }
    cout << answer << "\n";
}
