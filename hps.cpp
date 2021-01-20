#include <fstream>
#include <string>
#include <iostream>
#include <math.h>
#include <algorithm>
#include <vector>
using namespace std;
int n;
char arr[100000];
int maximum( int a, int b, int c )
{
   int max = ( a < b ) ? b : a;
   return ( ( max < c ) ? c : max );
}
int main(){
    ifstream in("hps.in");
    ofstream out("hps.out");
    in >> n;
    int wins[n][3];
    for (int x = 0; x < n; x++){
        in >> arr[x];
    }
    if (arr[0] == 'P'){
        wins[0][2] = 1;
        wins[0][1] = 0;
        wins[0][0] = 0;
    }
    else if (arr[0] == 'H'){
        wins[0][1] = 1;
        wins[0][2] = 0;
        wins[0][0] = 0;
    }
    else if (arr[0] == 'S'){
        wins[0][0] = 1;
        wins[0][1] = 0;
        wins[0][2] = 0;
    }

    for (int x = 1; x < n; x++){
        if (arr[x] == 'P'){
            wins[x][2] = 1 + wins[x - 1][2];
            wins[x][1] = wins[x - 1][1];
            wins[x][0] = wins[x - 1][0];
        }
        else if (arr[x] == 'H'){
            wins[x][1] = 1 + wins[x - 1][1];
            wins[x][2] = wins[x - 1][2];
            wins[x][0] = wins[x - 1][0];
        }
        else if (arr[x] == 'S'){
            wins[x][0] = 1 + wins[x - 1][0];
            wins[x][2] = wins[x - 1][2];
            wins[x][1] = wins[x - 1][1];
        }

    }
    int answer = 0;
    if (n == 1){
        answer = 1;
    }
    else{
        for (int x = 0; x < n - 1; x++){
            answer = max((maximum(wins[x][0], wins[x][1], wins[x][2]) + maximum(wins[n - 1][0] - wins[x][0], wins[n - 1][1] - wins[x][1], wins[n - 1][2] - wins[x][2])), answer);

        }
    }
    out << answer << "\n";


}
