#include <fstream>
#include <string>
#include <iostream>
#include <math.h>
#include <algorithm>
#include<bits/stdc++.h>
#include <vector>
using namespace std;
int t, n;

int main(){
    cin >> t;
    for  (int c = 0; c < t; c++){
        cin >> n;
        string s;
        cin >> s;
        int arr[n];
        int counter = 0;
        for (counter = n - 1; counter >= 0; counter--){
            if (s[counter] != s[0]){
                break;
            }
        }
        counter = (counter + 1) % n;
        int cursize = 0;
        int answer = 0;
        int moves = 0;
        bool starting = true;
        while(moves <= n){
            //cout << counter << " " << cursize << "\n";
            if (starting){
                counter = (counter + 1) % n;
                cursize++;
                moves++;
                starting = false;
            }
            else{
                int b_index = counter - 1 < 0 ? n - 1: counter - 1;
                if (s[b_index] == s[counter]){
                    counter = (counter + 1) % n;
                    cursize++;
                    moves++;
                }
                else{
                    counter = (counter + 1) % n;
                    moves++;
                    answer += cursize / 3;
                    cursize = 1;
                }
            }
            if (moves == n &&  cursize == n){
                answer = ceil(n / 3.0);
            }

        }
        cout << answer << "\n";
    }
}
