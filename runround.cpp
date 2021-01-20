/*
ID: alex.go2
LANG: C++11
PROB: runround
*/
#include <fstream>
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;

long long n;


bool check(long long n){
    string check1 = "xxxxxxxxx";
    string check2 = "xxxxxxxxx";
    string number = to_string(n);
    for (int x = 0; x < number.size(); x++){
        int cur = number[x] - '0';
        if (check1[cur - 1] == 'o'){
            return false;
        }
        else{
            check1[cur - 1] = 'o';
        }
    }
    int curindex = 0;
    int counter = 0;
    while(counter <= number.size()){
        if (counter == number.size()){
            if (check2[curindex] == 'x'){
                return true;
            }
        }
        else{
            curindex = ((number[curindex] - '0') + curindex) % number.size();
            if (check2[curindex] == 'x'){
                check2[curindex] = 'o';
            }
            else{
                return false;
            }
        }
        counter++;
    }
    return true;
}
int main(){
    ifstream in("runround.in");
    ofstream out("runround.out");
    in >> n;
    int i = n + 1;
    while(check(i) == false){
        i++;
    }
    out << i << "\n";
}
