#include <fstream>
#include <string>
#include <iostream>
#include <algorithm>
#include <queue>
#include <set>
#include <map>
using namespace std;
map<string, int> used;
vector<string> dictionary;
string one, two;
bool comp(string one, string two){
    int diff = 0;
    for (int x = 0; x < one.size(); x++){
        if (one[x] != two[x]){
            diff++;
        }
    }
    return diff == 1;
}
int main(){
    cin >> one >> two;
    string temp;
    while (cin >> temp){
        if (temp.size() == one.size()){
            dictionary.push_back(temp);
            used.insert(make_pair(temp, 1));
        }
    }
    queue<string> words;
    queue<int> moves;
    words.push(one);
    moves.push(0);
    bool notdone = true;
    while(words.empty() == false && notdone){
        if (words.front() == two){
            notdone = false;
            cout << moves.front();
        }
        else{
            used[words.front()] = 2;
            for (int x = 0; x < dictionary.size(); x++){
                if (comp(words.front(), dictionary[x]) && used[dictionary[x]] == 1){
                    used[dictionary[x]] = 2;
                    words.push(dictionary[x]);
                    moves.push(moves.front() + 1);
                }
            }
            words.pop();
            moves.pop();
        }
    }
}
