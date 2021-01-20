#include <fstream>
#include <string>
#include <iostream>
#include <math.h>
#include <algorithm>
#include <vector>
using namespace std;
int t, n;
vector<int> newv;
int solve(int pos, int counter, int a, int b){
    int ncounter = 0;
    int newpos = newv.size() - 1;
    while(ncounter < counter){
        if (newpos <= pos){
            return -1;
        }
        if (newv[newpos] == a){
            ncounter++;
        }
        newpos--;
    }
    int bcounter = 0;
    for (int x = pos + 1; x <= newpos; x++){
        if (newv[x] == b){
            bcounter++;
        }
    }
    return counter * 2 + bcounter;
};
int main(){
    cin >> t;
    for (int c = 0; c < t; c++){
        vector<int> arr;
        cin >> n;
        int one;
        for (int x = 0; x < n; x++){
            cin >> one;
            arr.push_back(one);
        }
        int answer = 0;
        for (int a = 1; a <= 26; a++){
            for (int b = 1; b <= 26; b++){
                newv.clear();
                for (int x = 0; x < n; x++){
                    if (arr[x] == a || arr[x] == b){
                        newv.push_back(arr[x]);
                    }
                }
                int counter = 0;
                int nanswer = solve(-1, 0, a, b);
                answer = max(nanswer, answer);
                for (int x = 0; x < newv.size(); x++){
                    if (newv[x] == a){
                        counter++;
                        int nanswer = solve(x, counter, a, b);
                        answer = max(answer, nanswer);
                    }
                }
            }
        }
        cout << answer << "\n";
    }
}
