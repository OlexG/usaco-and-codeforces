#include <fstream>
#include <string>
#include <iostream>
#include <math.h>
#include <algorithm>
#include <vector>
using namespace std;

int a, b, c;
int arr[202020];
int allc[20];
vector<int> answers;
int pour(int one, int two, int limone, int limtwo){
    if (one > limtwo - two){
        return limtwo - two;
    }
    else{
        return one;
    }
}
void rec(int ca, int cb, int cc){
    if (arr[ca * 10000 + cb * 100 + cc] == 2){
        return;
    }
    arr[ca * 10000 + cb * 100 + cc] = 2;
    if (ca == 0){
        if (allc[cc] = 1){
            allc[cc] = 2;
            answers.push_back(cc);
        }
    }
    if (ca > 0){
        int na = ca;
        int nb = cb;
        int nc = cc;
        int pourone = pour(na, nb, a, b);
        rec(na - pourone, nb + pourone, nc);
        int pourtwo = pour(na, nc, a, c);
        rec(na - pourtwo, nb, nc + pourtwo);
    }
    if (cb > 0){
        int na = ca;
        int nb = cb;
        int nc = cc;
        int pourone = pour(nb, na, b, a);
        rec(na + pourone, nb - pourone, nc);
        int pourtwo = pour(nb, nc, b, c);
        rec(na, nb  - pourtwo, nc + pourtwo);
    }
    if (cc > 0){
        int na = ca;
        int nb = cb;
        int nc = cc;
        int pourone = pour(nc, na, c, a);
        rec(na + pourone, nb, nc - pourone);
        int pourtwo = pour(nc, nb, c, b);
        rec(na, nb  + pourtwo, nc - pourtwo);
    }
}
int main(){
    cin >> a >> b >> c;
    for (int x = 0; x < 202020; x++){
        arr[x] = 1;
    }
    for (int y = 0; y < 20; y++){
        allc[y] = 1;
    }
    rec(0,0,c);
    sort(answers.begin(), answers.end());
    for (int x = 0; x < answers.size(); x++){
        cout << answers[x] << " ";
    }
}
