#include <fstream>
#include <string>
#include <iostream>
#include <math.h>
#include <algorithm>
#include<bits/stdc++.h>
#include <vector>
using namespace std;

int t, n;
pair<int, int> arr[201];
int best[201];
int main(){
    cin >> t;
    for (int z = 0; z < t; z++){
        cin >> n;
        int temp;
        for (int x = 0; x < n; x++){
            cin >> temp;
            arr[x] = make_pair(temp, x);
        }
        sort(arr, arr + n);
        best[n - 1] = arr[n - 1].first;
        for (int x = n - 2; x >= 0; x--){
            int answer = 1000000;
            int besttime = 0;
            for (int y = 1; y < 2 * n; y++){
                int curanswer = 0;
                curanswer += abs(arr[x].first - y);
                int nbest[n];
                for (int z = x + 1; z < n; z++){
                    nbest[z] = best[z];
                }
                nbest[x] = y;
                for (int z = x + 1; z < n; z++){
                    if (nbest[z] <= nbest[z - 1]){
                        nbest[z] = nbest[z - 1] + 1;
                    }
                }
                for (int z = x + 1; z < n; z++){
                    curanswer += abs(nbest[z] - arr[z].first);
                }
                if (curanswer <= answer){
                    answer = curanswer;
                    besttime = y;
                }
            }
            best[x] = besttime;
            //cout << best[x] << " ";
            //cout << besttime << " " << x << " " << bestshift << " " << arr[x].first << "\n";
            for (int z = x + 1; z < n; z++){
                if (best[z] <= best[z - 1]){
                    best[z] = best[z - 1] + 1;
                }
            }
        }
        int answer = 0;
        for (int x = 0; x < n; x++){
            answer += abs(best[x] - arr[x].first);
            //cout << best[x] << " " << arr[x].first << "\n";
        }
        //cout << "\n";
        cout << answer << "\n";
    }
}
