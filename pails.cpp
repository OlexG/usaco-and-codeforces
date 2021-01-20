#include <fstream>
#include <string>
#include <iostream>
#include <algorithm>
#include <stdlib.h>
using namespace std;

int used[100000];
int enc[100000];

int pourfindfirst(int a, int b, int x, int y){
    int diff = y - b;
    if (a < diff){
        b = b + a;
        a = 0;
    }
    else{
        a = a - diff;
        b = y;
    }
    return a;
}
int pourfindsecond(int a, int b, int x, int y){
    int diff = y - b;
    if (a < diff){
        b = b + a;
        a = 0;
    }
    else{
        a = a - diff;
        b = y;
    }
    return b;
}
int x, y, k, m, cura, curb;
int answer = 1000000;
int rec(int cur, int a, int b){
    if (cur == k){
        answer = min(answer, abs(m - (a + b)));
    }
    else{
        int newa, newb;
        newa = pourfindfirst(a,b,x,y);
        newb = pourfindsecond(a,b,x,y);
        //try one pour
        if (used[newa * 1000 + newb] == 1){
            answer = min(answer, abs(m - (newa + newb)));
            used[newa * 1000 + newb] = 2;
            rec(cur + 1, newa, newb);
        }
        newb = pourfindfirst(b,a,y,x);
        newa = pourfindsecond(b,a,y,x);
        //try other pour
        if (used[newa * 1000 + newb] == 1){
            answer = min(answer, abs(m - (newa + newb)));
            used[newa * 1000 + newb] = 2;
            rec(cur + 1, newa, newb);
        }
        //empty
        newb = b;
        newa = 0;
        if (used[newa * 1000 + newb] == 1){

            answer = min(answer, abs(m - (newa + newb)));
            used[newa * 1000 + newb] = 2;
            rec(cur + 1, newa, newb);
        }
        //empty again
        newb = 0;
        newa = a;
        if (used[newa * 1000 + newb] == 1){
            answer = min(answer, abs(m - (newa + newb)));
            used[newa * 1000 + newb] = 2;
            rec(cur + 1, newa, newb);
        }
        //fill
        newb = y;
        newa = a;
        if (used[newa * 1000 + newb] == 1){
            answer = min(answer, abs(m - (newa + newb)));
            used[newa * 1000 + newb] = 2;
            rec(cur + 1, newa, newb);
        }
        //fill again
        newb = b;
        newa = x;
        if (used[newa * 1000 + newb] == 1){
            answer = min(answer, abs(m - (newa + newb)));
            used[newa * 1000 + newb] = 2;
            rec(cur + 1, newa, newb);
        }

    }
}
int main(){
    ifstream in("pails.in");
    ofstream out("pails.out");
    cura = 0;
    curb = 0;
    in >> x >> y >> k >> m;
    for (int x = 0; x < 100000; x++){
        used[x] = 1;
    }
    rec(0,0,0);
    out << answer << "\n";
}



