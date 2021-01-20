#include <fstream>
#include <string>
#include <iostream>
#include <math.h>
#include <algorithm>
#include<bits/stdc++.h>
#include <vector>
using namespace std;

int n, q;
int prefix[3][100002];
int arr[100001];
int main(){
    ifstream in("bcount.in");
    ofstream out("bcount.out");
    in >> n >> q;
    for (int x = 0; x < n;x++){
        in >> arr[x];
    }
    prefix[0][0] = 0;
    prefix[1][0] = 0;
    prefix[2][0] = 0;


    for (int x = 0; x < n; x++){
        for (int y = 0; y < 3; y++){
            prefix[y][x + 1] = prefix[y][x];
        }
        prefix[arr[x] - 1][x + 1]+=1;
    }
    int one, two;
    for (int x = 0; x < q; x++){
        in >> one >> two;
        out << prefix[0][two] - prefix[0][one - 1] << " ";
        out << prefix[1][two] - prefix[1][one - 1] << " ";
        out << prefix[2][two] - prefix[2][one - 1] << "\n";

    }

}
