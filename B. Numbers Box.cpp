#include <fstream>
#include <string>
#include <iostream>
#include <math.h>
#include <algorithm>
#include<bits/stdc++.h>
#include <vector>
using namespace std;
int t;

int n, m;
int arr[10][10];
int main(){
    cin >> t;
    for (int z = 0; z < t; z++){
        cin >> n >> m;
        int numofneg = 0;
        int smallest = 101;
        int tsum = 0;
        for (int x = 0; x < n; x++){
            for (int y = 0; y < m; y++){
                cin >> arr[x][y];
                if (arr[x][y] <= 0){
                    numofneg++;
                }
                smallest = min(smallest, abs(arr[x][y]));
                tsum += abs(arr[x][y]);
            }
        }
        if (numofneg % 2 == 0){
            cout << tsum << "\n";
        }
        else{
            cout << tsum - (smallest * 2) << "\n";
        }
    }

}
