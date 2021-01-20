#include <fstream>
#include <string>
#include <iostream>
#include <math.h>
#include <algorithm>
#include<bits/stdc++.h>
#include <vector>
using namespace std;
int t, n, k;

int main(){
    cin >> t;
    for (int b = 0; b < t; b++){
        cin >> n >> k;
        string s;
        cin >> s;
        bool answer = true;
        int curone = 0;
        int curzero = 0;
        for (int x = 0; x < k; x++){
            if (s[x] == '1'){
                curone++;
            }
            else if (s[x] == '0'){
                curzero ++;
            }
        }
        curone = k/2 - curone;
        curzero = k/2 - curzero;
        for (int x = n - 1; x >= 0; x--){
            if (x - k >= 0){
                if (s[x] != '?' && s[x - k] != '?'){
                    if (s[x] != s[x - k]){
                        //cout << x << " " << x + k + 1 <<"\n";
                        answer = false;

                    }
                }
                else{
                    if (s[x] == '?'){
                        s[x] = s[x - k];
                        if (s[x] == '1'){
                            if (x < k){
                                curone --;
                            }
                        }
                        else{
                            if (x < k){
                                curzero--;
                            }
                        }
                    }
                    else{
                        s[x - k] = s[x];
                        if (s[x - k] == '1'){
                            if (x - k < k){
                                curone --;
                            }
                        }
                        else{
                            if (x - k < k){
                                curzero--;
                            }
                        }
                    }
                }
            }
        }
        for (int x = 0; x < k; x++){
            if (s[x] == '?'){
                if (x + k < n){
                    if (s[x + k] == '1'){
                        if (curone > 0){
                            curone--;
                            s[x] = '1';
                        }
                        else{
                            answer = false;

                        }
                    }
                    else if (s[x + k] == '0'){
                        if (curzero > 0){
                            curzero --;
                            s[x] = '0';
                        }
                        else{
                            answer = false;

                        }
                    }
                    else{
                        if (curone > 0){
                        curone--;
                        s[x] = '1';
                        }
                        else if (curzero > 0){
                            curzero --;
                            s[x] = '0';
                        }
                    }
                }
                else{
                    if (curone > 0){
                        curone--;
                        s[x] = '1';
                    }
                    else if (curzero > 0){
                        curzero --;
                        s[x] = '0';
                    }
                }
            }
        }
        if (curone > 0 || curzero > 0){
            answer = false;
            //cout << "ok";
        }
        for (int x = 0; x < n; x++){
            if (x + k < n){
                if (s[x] != '?' && s[x + k] != '?'){
                    if (s[x] != s[x + k]){
                        //cout << x << " " << x + k + 1 <<"\n";
                        answer = false;
                    }
                }
                else{
                    if (s[x] == '?'){
                        s[x] = s[x + k];
                    }
                    else{
                        s[x + k] = s[x];
                    }
                }
            }
        }

        if (answer){
            cout << "YES\n";
        }
        else{
            cout << "NO\n";
        }
    }
}
