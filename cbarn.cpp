#include <fstream>
#include <string>
#include <iostream>
#include <algorithm>
#include <cstdlib>
using namespace std;

int arr[1000];
int n;
int answer = 0;
int lastindex = 0;
bool notdone(){
    for (int x = 0; x < n; x++){
        if (arr[x] != 1){
            return true;
        }
    }
    return false;
}
int dist(int x, int y){
    if (x <= y){
        return y - x;
    }
    else{
        return n - x + y;
    }
}
bool pos(int x){
    int curzero = x;
    int cur = x;
    int counter = 0;
    while(counter < n){
        cur--;
        counter++;
        if (cur < 0){
            cur = n - 1;
        }
        if (cur == x){
            break;
        }
        if (arr[cur] != 0){
            if (dist(cur, curzero) < arr[cur] - 1){
                return false;
            }
            curzero -= arr[cur];
            if (curzero < 0){
                curzero = n + curzero;
            }
            //cout << cur << " " << curzero << "\n";
        }
    }
    return true;
}
int main(){
    ifstream in("cbarn.in");
    ofstream out("cbarn.out");
    in >> n;
    for (int x = 0; x < n; x++){
        in >> arr[x];
        if (arr[x] == 0){
            if (pos(x)){
                lastindex = x;
            }
        }
    }
    //cout << pos(4) << "\n";
    while(notdone()){
        int curindex = lastindex;
        while(true){
            curindex--;
            if (curindex < 0){
                curindex = n - 1;
            }
            if (arr[curindex] != 0){
                answer = answer + (dist(curindex, lastindex) * dist(curindex, lastindex));
                //cout << answer << " " << curindex <<  " " << lastindex << "\n";
                arr[curindex]--;
                arr[lastindex] = 1;
                lastindex--;
                if (lastindex < 0){
                    lastindex = n - 1;
                }
                break;
            }
        }
    }
    out << answer << "\n";

}
