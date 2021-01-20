/*
ID: alex.go2
LANG: C++11
PROB: lamps
*/
#include <fstream>
#include <string>
#include <iostream>
#include <algorithm>
#include <set>
#include <vector>
using namespace std;
int n;
int c;
vector<int> on;
vector<int> off;
set<string> answers;
string check = "";
string doall(string cur){
    for (int x = 0; x < n; x++){
        if (cur[x] == 'o'){
            cur[x] = 'x';
        }
        else{
            cur[x] = 'o';
        }
    }
    return cur;
}
string doodd(string cur){
    for (int x = 0; x < n; x++){
        if (x % 2 == 0){
            if (cur[x] == 'o'){
                cur[x] = 'x';
            }
            else{
                cur[x] = 'o';
            }
        }
    }
    return cur;
}
string doeven(string cur){
    for (int x = 0; x < n; x++){
        if (x % 2 == 1){
            if (cur[x] == 'o'){
                cur[x] = 'x';
            }
            else{
                cur[x] = 'o';
            }
        }
    }
    return cur;
}
string dotriple(string cur){
    for (int x = 0; x < n; x++){
        if ((x + 1) % 3 == 1){
            if (cur[x] == 'o'){
                cur[x] = 'x';
            }
            else{
                cur[x] = 'o';
            }
        }
    }
    return cur;
}

bool ok(string cur, string check){
    for (int x = 0; x < n; x++){
        if (check[x] != 't' && cur[x] != check[x]){
            return false;
        }
    }
    return true;
}
void rec(int it, string cur){
    if (it == c && ok(cur, check)){
        answers.insert(cur);
    }
    else if (it < c){
        cur = doall(cur);
        rec(it + 1, cur);
        cur = doall(cur);
        cur = doodd(cur);
        rec(it + 1, cur);
        cur = doodd(cur);
        cur = doeven(cur);
        rec(it + 1, cur);
        cur = doeven(cur);
        cur = dotriple(cur);
        rec(it + 1, cur);
        cur = dotriple(cur);
    }
}

int main(){
    ifstream in("lamps.in");
    ofstream out("lamps.out");
    in >> n >> c;
    int one = -2;
    while(one != - 1){
        in >> one;
        if (one != -1){
            on.push_back(one);
        }
    }
    int two = -2;
    while (two != -1){
        in >> two;
        if (two != - 1){
            off.push_back(two);
        }
    }
    for (int x = 0; x < n; x++){
        check += 't';
    }
    for (int x = 0; x < on.size(); x++){
        check[on[x] - 1] = 'x';
    }
    for (int x = 0; x < off.size(); x++){
        check[off[x] - 1] = 'o';
    }
    if (c > 5){
        c = 5;
    }
    string temp = "";
    for (int x = 0; x < n; x++){
        temp += 'x';
    }
    rec(0, temp);
    for (const string &answer : answers){
        for (int x = 0; x < n; x++){
            if (answer[x] == 'o'){
                out << 0;
            }
            else{
                out << 1;
            }
        }
        out << "\n";
    }
    if (answers.size() == 0){
        out << "IMPOSSIBLE\n";
    }

}
