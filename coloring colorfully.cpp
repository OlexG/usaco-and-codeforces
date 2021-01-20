#include <fstream>
#include <string>
#include <iostream>
#include <math.h>
#include <algorithm>
#include<bits/stdc++.h>
#include <vector>
using namespace std;

string s;
int main(){
    cin >> s;
    int answer = s.size() + 1;
    for (char start = '0'; start <= '1'; start++){
        char cur = start;
        int curanswer = 0;
        for (int y = 0; y < s.size(); y++){
            if (s[y] != cur){
                curanswer++;
            }
            if (cur == '0'){
                cur = '1';
            }
            else{
                cur = '0';
            }
        }
        answer = min(answer, curanswer);
    }
    cout << answer << "\n";

}
