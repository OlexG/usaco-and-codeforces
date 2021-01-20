#include <fstream>
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;

long long n;
long long total = 3;
long long cur = 1;
char rec(int need, int total, int cur){
    int midstart = (total - (cur  + 2))/2 + 1;
    int midstop = (total - (cur  + 2))/2 + cur + 2;
    if (need < midstart){
        return rec(need, midstart - 1, cur - 1);
    }
    else if (need > midstop){
        return rec(need - midstop, midstart - 1, cur - 1);
    }
    else{
        if (need == midstart){
            return 'm';
        }
        else{
            return 'o';
        }
    }
}
int main(){
    cin >> n;
    while(total <= n){
        cur++;
        total = total * 2 + cur + 2;
    }
    cout << rec(n, total, cur);

}
