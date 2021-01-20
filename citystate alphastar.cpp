#include <fstream>
#include <string>
#include <iostream>
#include <algorithm>
#include <math.h>
#include <map>
#include <string>
using namespace std;
#include <vector>
int n;
vector<string> s;
int upperbound(string x){
    int l = 0;
    int t = n;
    while (l < t){
        int mid = (l + t)/2;
        if (x >= s[mid]){
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
        if (x <= s[mid]){
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
    string one, two;
    for (int x = 0; x < n; x++){
        cin >> one >> two;
        s.push_back("");
        s[x] += one[0];
        s[x] += one[1];
        s[x] += two;
    }
    sort(s.begin(), s.end());
    int answer = 0;
    for (int x = 0; x < n; x++){
        string temp = "";
        temp += s[x][2];
        temp += s[x][3];
        temp += s[x][0];
        temp += s[x][1];
        if (temp[0] != temp[2] || temp[1] != temp[3]){
            answer += upper_bound(s.begin(), s.end(), temp) - lower_bound(s.begin(), s.end(), temp);
        }
    }
    cout << answer/2;


}
