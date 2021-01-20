#include <fstream>
#include <string>
#include <iostream>
#include <math.h>
#include <algorithm>
#include<bits/stdc++.h>
#include <vector>
#include <math.h>
using namespace std;
int n;
int main(){
    cin >> n;
    vector<pair<int , int>> arr;
    int one, two;
	while(cin >> one >> two){
		arr.push_back(make_pair(one ,two));
	}

    vector<int> dried;
    vector<int> washed;
    vector<int> dirty;
    for (int x = n ; x > 0; x--){
        dirty.push_back(x);
    }
    for (int x = 0; x < arr.size(); x++){
        if(arr[x].first == 1){
            for (int z = 0; z < arr[x].second; z++){
                washed.push_back(dirty[dirty.size() - 1]);
                dirty.pop_back();
            }
        }
        else{
            for (int z = 0; z < arr[x].second; z++){

                dried.push_back(washed[washed.size() - 1]);
                washed.pop_back();
            }
        }
    }
    for (int x = n - 1; x >= 0; x--){
        cout << dried[x] << "\n";
    }
}
