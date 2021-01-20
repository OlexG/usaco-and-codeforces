#include <fstream>
#include <string>
#include <iostream>
#include <math.h>
#include <algorithm>
#include<bits/stdc++.h>
#include <vector>
using namespace std;


int t;
long long n, s;
int main(){
    cin >> t;
    for (int z = 0; z < t; z++){
        cin >> n >> s;
        string ns = to_string(n);
        string nd = "";
        int tsum = 0;
        for (int x = 0; x < ns.size(); x++){
            tsum += (ns[x] - '0');
        }
        if (tsum <= s){
            cout << 0 << "\n";
            continue;
        }
        bool carry = false;
        for (int x = ns.size() - 1; x >= 0; x--){
            //cout << tsum << "\n";
            //cout << ns << "\n";
            if (x == 0){
                int si = ns.size();
                ns = "1";
                for (int y = 0; y < si; y++){
                    ns += '0';
                }
                break;
            }
            if (ns[x] - '0' == 0){
                if (!carry){
                    continue;
                }
            }
            tsum -= (ns[x] - '0');
            ns[x] = '0';
            if (carry){
                carry = false;
            }

            if (ns[x - 1] == '9'){
                //cout << "yes\n";
                carry = true;
                ns[x - 1] = '0';
                tsum -= 9;
            }
            else{
                tsum += 1;
                ns[x - 1] = ('0' + ((ns[x - 1] - '0') + 1));
            }
            if (!carry){
                if (tsum <= s){
                    break;
                }
            }
        }
        //cout << ns << "\n";
        string::size_type sz = 1000;
        cout << stoll(ns, &sz, 10) - n << "\n";
    }
}
