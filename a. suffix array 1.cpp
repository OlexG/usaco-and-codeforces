#include <fstream>
#include <string>
#include <iostream>
#include <math.h>
#include <algorithm>
#include<bits/stdc++.h>
#include <vector>
using namespace std;
string s;
vector<pair<int, pair<int, int>>> arr;
bool custsort1(pair<int, pair<int, int>> a, pair<int, pair<int, int>> b){
    return  s[a.first] < s[b.first];
}
bool custsort2(pair<int, pair<int, int>> a, pair<int, pair<int, int>> b){
    if (a.second.first == b.second.first){
        return a.second.second < b.second.second;
    }
    else{
        return a.second.first < b.second.first;
    }
}
int main(){
    cin >> s;
    s += '$';
    for (int x = 0; x < s.size(); x++){
        arr.push_back(make_pair(x, make_pair(0,0)));
    }
    sort(arr.begin(), arr.end(), custsort1);
    int k = 1;
    arr[0].second.first = 1;
    for (int x = 1; x < s.size(); x++){
        if (s[arr[x - 1].first] == s[arr[x].first]){
            //assign same class
            arr[x].second.first = arr[x - 1].second.first;
        }
        else{
            arr[x].second.first = arr[x - 1].second.first + 1;
        }
    }
    int classes[s.size() + 5];
    int classes1[s.size() + 5];

    for (int x = 0; x < s.size(); x++){
        classes[arr[x].first] = arr[x].second.first;
    }
    for (int x = 0; x < s.size(); x++){

        long long len = pow(2, k);
        int second_pos = (arr[x].first + len/2) % s.size();
        //assign second classes through the classes we had before
        arr[x].second.second = classes[second_pos];
        //cout << arr[x].first << " " << arr[x].second.first << " " << arr[x].second.second << "\n";
    }
    sort(arr.begin(), arr.end(), custsort2);
    /*for (int x = 0; x < s.size(); x++){
        cout << arr[x].first << " " << arr[x].second.first << " " << arr[x].second.second << "\n";
    }
    cout << "\n";*/
    while(pow(2, k) <= s.size()){
        k++;
        long long len = pow(2, k);
        classes1[0] = 1;
        for (int x = 1; x < s.size(); x++){
            if (arr[x].second.first == arr[x - 1].second.first && arr[x].second.second == arr[x - 1].second.second){
                classes1[x] = classes1[x - 1];
            }
            else{
                classes1[x] = classes1[x - 1] + 1;
            }
            classes[arr[x].first] = classes1[x];
        }
        if (classes1[s.size() - 1] == s.size()){
            break;
        }

        for (int x = 0; x < s.size(); x++){
            int second_pos = (arr[x].first + len/2) % s.size();
            arr[x].second.first = classes1[x];
            arr[x].second.second = classes[second_pos];
        }
        /*cout << "\n";
        for (int x = 0; x < s.size(); x++){
            cout << arr[x].first << " " << arr[x].second.first << " " << arr[x].second.second << "\n";
        }*/
        sort(arr.begin(), arr.end(), custsort2);


    }
    for (int x = 0; x < s.size(); x++){
        cout << arr[x].first << " ";
    }

}
