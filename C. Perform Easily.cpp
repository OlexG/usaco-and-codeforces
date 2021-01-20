#include <fstream>
#include <string>
#include <iostream>
#include <math.h>
#include <algorithm>
#include<bits/stdc++.h>
#include <vector>
using namespace std;



int arr[6];
int b;
int bs[100005];
int mins[6];
vector<pair<int, int>> notes;
int used[100005];

int main(){
    cin >> arr[0] >> arr[1] >> arr[2] >> arr[3] >> arr[4] >> arr[5];
    cin >> b;
    for (int x = 0; x < b; x++){
        cin >> bs[x];
        used[x] = 0;
    }

    for (int x = 0; x < b; x++){
        for (int y = 0; y < 6; y++){
            notes.push_back(make_pair(bs[x] - arr[y], x));
        }
    }
    sort(notes.begin(), notes.end());
    int p1 = 0;
    int p2 = 0;
    used[notes[p1].second] = 1;
    int answer = 1000000005;
    int sum = 1;
    while(p2 < notes.size()){
        if (p2 == notes.size() - 1){
            if (used[notes[p1].second] == 1){
                if (sum == b){
                    answer = min(answer, notes[p2].first - notes[p1].first);
                }
                break;
            }
            else{
                used[notes[p1].second] -= 1;
                p1++;
                if (sum == b){
                    answer = min(answer, notes[p2].first - notes[p1].first);
                }
            }
        }
        else{
            if (used[notes[p1].second] > 1){
                used[notes[p1].second] -= 1;
                p1++;
                if (sum == b){
                    answer = min(answer, notes[p2].first - notes[p1].first);
                }
            }
            else{
                p2++;
                if (used[notes[p2].second] == 0){
                    sum++;
                }
                used[notes[p2].second] += 1;
                if (sum == b){
                    answer = min(answer, notes[p2].first - notes[p1].first);
                }
            }
        }
    }
    cout << answer << "\n";
}
