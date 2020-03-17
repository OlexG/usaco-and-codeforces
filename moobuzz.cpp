#include <fstream>
#include <string>
#include <iostream>
#include <math.h>
#include <algorithm>
#include <vector>
using namespace std;
int main(){
    ifstream in("moobuzz.in");
    ofstream out("moobuzz.out");
    //1, 2, Moo, 4, Moo, Moo, 7, 8, Moo, Moo, 11, Moo, 13, 14, Moo
    long long n;
    in >> n;
    long long numbefore = ((n - 1)/8) * 15;
    long long whichone = n%8;

    if ( whichone > 2){
        if (whichone == 3){
            numbefore += 1;
        }
        else if (whichone == 4){
            numbefore += 3;
        }
        else if (whichone == 5){
            numbefore += 3;
        }
         else if (whichone == 6){
            numbefore += 5;
        }
         else if (whichone == 7){
            numbefore += 6;
        }
         else if (whichone == 8){
            numbefore += 6;
        }
    }
    out << numbefore + whichone << "\n";

}
