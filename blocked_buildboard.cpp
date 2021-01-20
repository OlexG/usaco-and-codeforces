#include <fstream>
#include <string>
#include <iostream>
#include <math.h>
#include <algorithm>
#include<bits/stdc++.h>
#include <vector>
using namespace std;

int arr[2][4];
//x1, y1, x2, y2
//x1, y1, x2, y2
int x_1, y_1, x_2, y_2;

int intersection(int a1, int a2, int b1, int b2){
    if (min(b2, a2) - max(b1, a1) > 0){
        return min(b2, a2) - max(b1, a1);
    }
    else{
        return 0;
    }
}
int main(){
    ifstream in("billboard.in");
    ofstream out("billboard.out");
    int a, b, c, d;
    for (int x = 0; x < 2; x++){
        in >> arr[x][0] >> arr[x][1] >> arr[x][2] >> arr[x][3];
    }
    in >> x_1 >> y_1 >> x_2 >> y_2;
    int answer = 0;
    for (int x = 0; x < 2; x++){
        answer += (arr[x][3] - arr[x][1]) * (arr[x][2] - arr[x][0])-(intersection(x_1, x_2, arr[x][0], arr[x][2]) * intersection(y_1, y_2, arr[x][1], arr[x][3]));
    }
    out << answer << "\n";
}
