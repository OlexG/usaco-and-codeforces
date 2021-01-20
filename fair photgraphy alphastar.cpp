#include <fstream>
#include <string>
#include <iostream>
#include <math.h>
#include <algorithm>
#include <vector>
using namespace std;

int n;
struct point{
    long long pos;
    char type;
};
point arr[100000];
bool comp(point a, point b){
    return a.pos < b.pos;
}
int main(){
    cin >> n;
    long long one;
    char two;
    for (int x = 0; x < n; x++){
        cin >> one >> two;
        arr[x].pos = one;
        arr[x].type = two;
    }
    sort(arr, arr + n, comp);
    int start = -1;
    int ending = -1;
    long long answer = 0;
    for (int x = 0; x < n; x++){
        if (arr[x].type == 'G'){
            if (start == -1){
                start = x;
            }
            else{
                ending = x;
                answer = max(answer, arr[ending].pos - arr[start].pos);
            }
        }
        else{
            start = - 1;
        }
    }
    start = -1;
    ending = -1;
    for (int x = 0; x < n; x++){
        if (arr[x].type == 'H'){
            if (start == -1){
                start = x;
            }
            else{
                ending = x;
                answer = max(answer, arr[ending].pos - arr[start].pos);
            }
        }
        else{
            start = - 1;
        }
    }
    long long pref[n];
    if (arr[0].type == 'G'){
        pref[0] = 1;
    }
    else{
        pref[0] = -1;
    }

    for (int x = 1; x < n; x++){
        if (arr[x].type == 'G'){
            pref[x] = pref[x - 1] + 1;
        }
        else{
            pref[x] = pref[x - 1] - 1;
        }

    }
    pair<long long, long long> in[2*n];
    for (int x = 0; x < 2 * n; x++){
        in[x].first = -1;
    }

    for (int x = 0; x < n; x++){
        if (in[pref[x] + n - 1].first == -1){
            in[pref[x] + n - 1].first = arr[x + 1].pos;
        }
        else{
            in[pref[x] + n - 1].second = arr[x].pos;
        }
    }

    for (int x = 0; x < 2 * n; x++){
        if (in[x].first != - 1){
            answer = max(answer, in[x].second - in[x].first);
        }
    }
    cout << answer;


}
