#include <fstream>
#include <string>
#include <iostream>
#include <math.h>
#include <algorithm>
#include<bits/stdc++.h>
#include <vector>
using namespace std;

int n;

int main(){
    cin >> n;
    int answer = 0;
    for (int x = 1; x <= n; x++)
        answer += n/x;
    }
    cout << answer/2 << "\n";
}
