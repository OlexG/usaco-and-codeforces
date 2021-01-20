#include <fstream>
#include <string>
#include <iostream>
#include <math.h>
#include <algorithm>
#include<bits/stdc++.h>
#include <vector>
using namespace std;

int t;

int main(){
    cin >> t;
    for (int z = 0; z < t; z++){
        int one, two, three, four;
        cin >> one >> two >> three >> four;
        string curanswer[4];
        curanswer[0] = "Ya";
        curanswer[1] = "Ya";
        curanswer[2] = "Ya";
        curanswer[3] = "Ya";
        if (one + two == 0 || (one + two) % 2 == 0){
            curanswer[0] = "Tidak";
            curanswer[1] = "Tidak";

            if (four == 0 && one == 0){
                curanswer[3] = "Tidak";
            }
            if (two == 0 && three == 0){
                curanswer[2] = "Tidak";
            }
        }
        else{
            curanswer[2] = "Tidak";
            curanswer[3] = "Tidak";
            if (four == 0 && one == 0){
                curanswer[0] = "Tidak";
            }
            if (two == 0 && three == 0){
                curanswer[1] = "Tidak";
            }
        }
        cout << curanswer[0] << " " << curanswer[1] << " " << curanswer[2] << " " << curanswer[3] << "\n";
    }
}
