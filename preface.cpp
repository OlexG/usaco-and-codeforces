/*
ID: alex.go2
LANG: C++11
PROB: preface

*/
#include <fstream>
#include <string>
#include <iostream>
#include <algorithm>
#include <map>
using namespace std;

map<char, int> counting;
string converter(int n){
    string curstring = "";
    while(n > 0){
        if (n >= 1000){
            curstring += 'M';
            n -= 1000;
        }
        else if (n >= 900){
            curstring += "CM";
            n -= 900;
        }
        else if (n >= 500){
            curstring += 'D';
            n -= 500;
        }
        else if (n >= 400){
            curstring += "CD";
            n -= 400;
        }
        else if (n >= 100){
            curstring += 'C';
            n -= 100;
        }
        else if (n >= 90){
            curstring += "XC";
            n -= 90;
        }
        else if (n >= 50){
            curstring += 'L';
            n -= 50;
        }
        else if (n >= 40){
            curstring += "XL";
            n -= 40;
        }
        else if (n >= 10){
            curstring +=' X';
            n -= 10;
        }
        else if (n >= 9){
            curstring += "IX";
            n -= 9;
        }
        else if (n >= 5){
            curstring += 'V';
            n -= 5;
        }
        else if (n >= 4){
            curstring += "IV";
            n -= 4;
        }
        else if (n >= 1){
            curstring += 'I';
            n -= 1;
        }

    }
    return curstring;
}

int n;
int main(){
    ifstream in("preface.in");
    ofstream out("preface.out");
    in >> n;
    counting.insert(make_pair('I', 0));
    counting.insert(make_pair('V', 0));
    counting.insert(make_pair('X', 0));
    counting.insert(make_pair('L', 0));
    counting.insert(make_pair('C', 0));
    counting.insert(make_pair('D', 0));
    counting.insert(make_pair('M', 0));
    for (int x = 1; x <= n; x++){
        string result = converter(x);
        for (int y = 0; y < result.size(); y++){
            counting[result[y]] += 1;
        }
    }
    if (counting['I'] > 0){
        out << 'I' << " " << counting['I'] << "\n";
    }
    if (counting['V'] > 0){
        out << 'V' << " " << counting['V'] << "\n";
    }
    if (counting['X'] > 0){
        out << 'X' << " " << counting['X'] << "\n";
    }
    if (counting['L'] > 0){
        out << 'L' << " " << counting['L'] << "\n";
    }
    if (counting['C'] > 0){
        out << 'C' << " " << counting['C'] << "\n";
    }
    if (counting['D'] > 0){
        out << 'D' << " " << counting['D'] << "\n";
    }
    if (counting['M'] > 0){
        out << 'M' << " " << counting['M'] << "\n";
    }

}
