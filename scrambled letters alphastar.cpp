#include <fstream>
#include <string>
#include <iostream>
#include <math.h>
#include <algorithm>
#include <vector>
using namespace std;
int n;
string sortedsmall[50000];
string sortedbig[50000];
string original[50000];
string originalc[50000];
string originalcc[50000];
bool comprev(char a, char b){
    return a > b;
}
int upperbound(string x){
    int l = 0;
    int t = n;
    while (l < t){
        int mid = (l + t)/2;
        if (x >= sortedsmall[mid]){
            l = mid + 1;
        }
        else{
            t = mid;
        }
    }
    return l;
}
int lowerbound(string x){
    int l = 0;
    int t = n;
    while (l < t){
        int mid = (l + t)/2;
        if (x <= sortedbig[mid]){
            t = mid;
        }
        else{
            l = mid + 1;
        }
    }
    return l;
}
int main(){
    cin >> n;
    string temp;
    for (int x = 0; x < n; x++){
        cin >> temp;
        original[x] = temp;;
        sortedsmall[x] = temp;
        sortedbig[x] = temp;
    }
    for (int x = 0; x < n; x++){
        string temp = sortedsmall[x];
        sort(temp.begin(), temp.end());
        sortedsmall[x] = temp;

    }
    for (int x = 0; x < n; x++){
        string temp = sortedbig[x];
        sort(temp.begin(), temp.end(), comprev);
        sortedbig[x] = temp;

    }
    sort(sortedbig, sortedbig + n);
    sort(sortedsmall, sortedsmall + n);
    for (int x = 0; x < n; x++){
        string temp = original[x];
        sort(temp.begin(), temp.end());
        cout << lowerbound(temp) + 1;
        cout << " ";
        sort(temp.begin(), temp.end(), comprev);
        cout << upperbound(temp) << "\n";
    }

}
