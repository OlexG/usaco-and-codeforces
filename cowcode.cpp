#include <fstream>
#include <string>
#include <iostream>
#include <math.h>
#include <vector>
#include <bitset>
#include <algorithm>
using namespace std;
long long n;
string m;
char rec(long long x, string s){
    if (x <= s.size()){
        return s[x - 1];
    }
    else{
        long long length = s.size();
        while(length <= x){
            length *= 2;
        }
        if (x == length - s.size() + 1){
            return rec(length/2, s);
        }
        else{
                 cout << length << "\n";
            return rec(x - length/2 - 1, s);
        }
    }
}
int main(){
    ifstream in("cowcode.in");
    ofstream out("cowcode.out");
    in >> m >> n;
    out << rec(n, m) << "\n";
}
