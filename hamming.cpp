/*
ID: alex.go2
LANG: C++11
PROB: hamming
*/
#include <fstream>
#include <string>
#include <iostream>
#include <algorithm>
#include <queue>
#include <math.h>
using namespace std;

int n, b, d;

vector<string> answers;
vector<int> intanswers;
bool valid(string current){
    string second = "";
    for (int x = 0; x < b - current.size(); x++){
        second += '0';
    }
    second += current;
    for (int x = 0; x < answers.size(); x++){
        int diff = 0;
        string first = "";
        for (int y = 0; y < b - answers[x].size(); y++){
            first += '0';
        }
        first += answers[x];
        for (int y = 0; y < b; y++){
            if (second[y] != first[y]){
                diff++;
            }
        }
        if (diff < d){
            return false;
        }
    }
    return true;
}
int intify(string current){
    int result = 0;
    for (int x = current.size() - 1; x >= 0; x--){
        int bit = current[x] - '0';
        int increment = bit * pow(2, current.size() - 1 - x);
        result += increment;
    }
    return result;
}
int main(){
    ifstream in("hamming.in");
    ofstream out("hamming.out");
    in >> n >> b >> d;
    queue<string> cur;
    intanswers.push_back(0);
    answers.push_back("0");
    cur.push("1");
    int c = 0;
    string outputstring = "";
    outputstring +=  "0 ";
    while(c < pow(2, b) - 1 && answers.size() < n){
        string current = cur.front();
        cur.pop();
        cur.push(current + '0');
        cur.push(current + '1');
        if (valid(current)){
            int validanswer = intify(current);
            outputstring += to_string(validanswer);
            intanswers.push_back(validanswer);
            answers.push_back(current);
            if (answers.size() % 10 == 0){
                outputstring += "\n";
            }
            else{
                outputstring += " ";
            }
        }

        c++;
    }
    outputstring.pop_back();
    outputstring += "\n";
    out << outputstring;

}

