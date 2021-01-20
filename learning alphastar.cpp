#include <fstream>
#include <string>
#include <iostream>
#include <math.h>
#include <algorithm>
#include <vector>
using namespace std;
long long n, a ,b;
struct point{
    string type;
    long long pos;
};
struct interval{
    string type;
    long long a;
    long long b;
};
long long decidef(long long posa, long long posb, string typea, string typeb){
    if (typea == "S"){
        return posa + (posb - posa)/2;
    }
    else{
        if (typeb == "NS"){
            return posa + (posb - posa)/2;
        }
        else{
            return posa + (posb - posa - 1)/2;
        }
    }
}
long long decideb(long long posa, long long posb, string typea, string typeb){
    if (typea == "S"){
        if (typeb == "NS"){
            return posa - (posa - posb)/2;
        }
        else{
            return posa - (posa - posb - 1)/2;
        }
    }
    else{
        return posa - (posa - posb - 1)/2;
    }
}
bool compare(point a, point b){
    return a.pos < b.pos;
}
int main(){
    cin >> n >> a >> b;
    point arr[n];
    string one;
    long long two;
    for (int x = 0; x < n; x++){
        cin >> one >> two;
        arr[x].type = one;
        arr[x].pos = two;
    }
    sort(arr, arr + n, compare);
    int answer = 0;
    if (n == 1){
        if (arr[0].type == "S"){
            answer = b - a;
        }
    }
    else{
        interval intervals[n];
        intervals[0].a = arr[0].pos;
        intervals[0].b = decidef(arr[0].pos, arr[1].pos, arr[0].type, arr[1].type);
        intervals[0].type = arr[0].type;
        intervals[n - 1].b = arr[n-1].pos;
        intervals[n - 1].a = decideb(arr[n - 1].pos, arr[n - 2].pos, arr[n - 1].type, arr[n - 2].type);
        intervals[n - 1].type = arr[n - 1].type;
        for (int x = 1; x < n - 1; x++){
            intervals[x].a = decideb(arr[x].pos, arr[x - 1].pos, arr[x].type, arr[x - 1].type);
            intervals[x].b = decidef(arr[x].pos, arr[x + 1].pos, arr[x].type, arr[ x + 1].type);
            intervals[x].type = arr[x].type;
        }
        if (a < intervals[0].a && b < intervals[0].a){
            if (intervals[0].type == "S"){
                answer = b - a;
            }
        }
        else if (a > intervals[n - 1].b && b > intervals[n - 1].b){
            if (intervals[n - 1].type == "S"){
                answer = b - a;
            }
        }
        else{
            if (a <= intervals[0].a){
                intervals[0].a = a;
            }
            else{
                for (int x = 0; x < n; x++){
                    if (a >= intervals[x].a && a <= intervals[x].b){
                        intervals[x].a = a;
                        break;
                    }
                    else{
                        intervals[x].b = intervals[x].a - 1;
                    }
                }
            }
            if (b >= intervals[n - 1].b){
                intervals[n - 1].b = b;
            }
            else{
                for (int x = n - 1; x >= 0; x--){
                    if (b >= intervals[x].a && b <= intervals[x].b){
                        intervals[x].b = b;
                        break;
                    }
                    else{
                        intervals[x].b = intervals[x].a - 1;
                    }
                }
            }

            for (int x = 0; x < n; x++){
                if (intervals[x].type == "S"){
                    answer = answer + intervals[x].b - intervals[x].a + 1;
                }
            }
        }

    }
    cout << answer;
}
