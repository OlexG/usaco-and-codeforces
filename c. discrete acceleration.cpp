#include <fstream>
#include <string>
#include <iostream>
#include <math.h>
#include <algorithm>
#include<bits/stdc++.h>
#include <vector>
using namespace std;
int t;
long long n, l;
int main(){
    cin >> t;
    for (int z = 0; z < t; z++){
        cin >> n >> l;
        vector<int> fl;
        int temp;
        for (int x = 0; x < n; x++){
            cin >> temp;
            fl.push_back(temp);
        }
        double cura = 0;
        int anext = 0;
        int bnext = n - 1;
        double curb = l;
        double curaa = 1;
        double curba = 1;
        sort(fl.begin(), fl.end());
        double answer = 0;
        while(cura < curb){
            //cout << cura << " " << curb << "\n";
            if (anext > bnext){
                answer += ((curb - cura)/(curaa + curba));
                break;
            }
            if ((fl[anext] - cura)/curaa < (curb - fl[bnext])/curba){
                curb -= (((fl[anext] - cura)/curaa) * curba);
                answer += ((fl[anext] - cura)/curaa);
                cura = fl[anext];
                curaa += 1;
                anext += 1;
            }
            else if ((curb - fl[bnext])/curba < (fl[anext] - cura)/curaa){
                cura += (((curb - fl[bnext])/curba) * curaa);
                answer += ((curb - fl[bnext])/curba);
                curb = fl[bnext];
                curba += 1;
                bnext -= 1;
            }
            else{
                answer += ((curb - fl[bnext])/curba);
                cura = fl[anext];
                anext += 1;
                curb = fl[bnext];
                curaa += 1;
                curba += 1;
                bnext -= 1;
            }
        }
        cout << setprecision(20) << answer << "\n";
    }
}
