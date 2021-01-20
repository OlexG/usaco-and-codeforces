#include <fstream>
#include <string>
#include <iostream>
#include <math.h>
#include <algorithm>
#include <vector>
using namespace std;

int n;
string arr[7];
int used[7];
int answer = 10000000;
string m(string one, string two){
    int where = one.size();
    for (int x = 0; x < one.size(); x++){
        bool merged = true;
        for (int y = x; y < one.size(); y++){
            if (y - x >= two.size()){
                merged = false;
                break;
            }
            else{
                if (one[y] != two[y - x]){
                    merged = false;
                    break;
                }
            }
        }
        if (merged){
            where = x;
            break;
        }
    }
    int counter = 0;
    while(where < one.size()){
        one[where] = two[counter];
        where++;
        counter++;
    }
    while(counter < two.size()){
        one += two[counter];
        counter++;
    }
    return one;
}
int rec(int l, string cur){
    if (l == n){
        int s = cur.size();
        answer = min(answer, s);
    }
    else{
        for (int x = 0; x < n; x++){
            if (used[x] == 1){
                used[x] = 2;
                rec(l + 1, m(cur, arr[x]));
                used[x] = 1;
            }
        }
    }
}
int main(){
    cin >> n;
    for (int x = 0; x < n; x++){
        cin >> arr[x];
        used[x] = 1;
    }
    rec(0, "");
    cout << answer;

}
