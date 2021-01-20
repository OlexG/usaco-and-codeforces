#include <fstream>
#include <string>
#include <iostream>
#include <math.h>
#include <algorithm>
#include <vector>
using namespace std;
int n, a, b;
int used[200];
int ups[200];
int downs[200];
int rights[200];
int lefts[200];
struct point{
    int x;
    int y;
    char type;
};
point arr[200];
bool check(string dir, int x, int y){
    //cout << x << " " << y << " " << dir << "\n";
    if (dir == "right"){
        int bestx = 3000000;
        int besty = 3000000;
        int bestindex = -1;
        char besttype ='n';
        for (int z = 0; z < n; z++){
            if (arr[z].y == y){
                if (arr[z].x > x && abs(arr[z].x - x) < abs(bestx - x)){
                    besty = arr[z].y;
                    bestx = arr[z].x;
                    besttype = arr[z].type;
                    bestindex = z;
                }
            }
        }
        if (besttype == '/' || besttype == 'o'){
            if (used[bestindex] == 1 || rights[bestindex] == 1){
                if (b == besty && a >= x && a <= bestx){
                    return true;
                }
                else{
                    used[bestindex] = 2;
                    rights[bestindex] = 2;
                    if (besttype == '/'){
                        return check("up", bestx, besty);
                    }
                    else{
                        return check("down", bestx, besty);
                    }
                }
            }
            else{
                if (b == y && a >= x){
                    return true;
                }
                return false;
            }
        }
        else{
            if (b == y && a >= x){
                return true;
            }
            else{
                return false;
            }
        }
    }
    else if (dir == "left"){
        int bestx = 3000000;
        int besty = 3000000;
        int bestindex = -1;
        char besttype = 'n';
        for (int z = 0; z < n; z++){
            if (arr[z].y == y){
                if (arr[z].x < x && abs(arr[z].x - x) < abs(bestx - x)){
                    besty = arr[z].y;
                    bestx = arr[z].x;
                    besttype = arr[z].type;
                    bestindex = z;
                }
            }
        }
        if (besttype == '/' || besttype == 'o'){
            if (used[bestindex] == 1 || lefts[bestindex] == 1){
                if (b == besty && a <= x && a >= bestx){
                    return true;
                }
                else{
                    used[bestindex] = 2;
                    lefts[bestindex] = 2;
                    if (besttype == '/'){
                        return check("down", bestx, besty);
                    }
                    else{
                        return check("up", bestx, besty);
                    }
                }
            }
            else{
                if (b == y && a <= x){
                    return true;
                }
                return false;
            }
        }
        else{
            if (b == y && a <= x){
                return true;
            }
            else{
                return false;
            }
        }
    }
    else if (dir == "up"){
        int bestx = 3000010;
        int besty = 3000010;
        int bestindex = -1;
        char besttype = 'n';
        for (int z = 0; z < n; z++){
            if (arr[z].x == x){
                if (arr[z].y > y && abs(arr[z].y - y) < abs(besty - y)){
                    besty = arr[z].y;
                    bestx = arr[z].x;
                    besttype = arr[z].type;
                    bestindex = z;
                }
            }
        }
        if (besttype == '/' || besttype == 'o'){
            if (used[bestindex] == 1 || ups[bestindex] == 1){
                if (a == x && b >= y && b <= besty){
                    return true;
                }
                else{
                    used[bestindex] = 2;
                    ups[bestindex] = 2;
                    if (besttype == '/'){
                        return check("right", bestx, besty);
                    }
                    else{
                        return check("left", bestx, besty);
                    }
                }
            }
            else{
                if (a == x && b >= y){
                    return true;
                }
                return false;
            }
        }
        else{
            if (a == x && b >= y){
                return true;
            }
            else{
                return false;
            }
        }
    }
    else {
        int bestx = 3000010;
        int besty = 3000010;
        int bestindex = -1;
        char besttype = 'n';
        for (int z = 0; z < n; z++){
            if (arr[z].x == x){
                if (arr[z].y < y && abs(arr[z].y - y) < abs(besty - y)){
                    besty = arr[z].y;
                    bestx = arr[z].x;
                    besttype = arr[z].type;
                    bestindex = z;
                }
            }
        }
        if (besttype == '/' || besttype == 'o'){
            if (used[bestindex] == 1 || downs[bestindex] == 1){
                if (a == x && b <= y && b >= besty){
                    return true;
                }
                else{
                    used[bestindex] = 2;
                    downs[bestindex] = 2;
                    if (besttype == '/'){
                        return check("left", bestx, besty);
                    }
                    else{
                        return check("right", bestx, besty);
                    }
                }
            }
            else{
                if (a == x && b <= y){
                    return true;
                }
                return false;
            }
        }
        else{
            if (a == x && b <= y){
                return true;
            }
            else{
                return false;
            }
        }
    }
}
int main(){
    cin >> n >> a >> b;
    for (int x = 0; x < n; x++){
        point temp;
        cin >> temp.x >> temp.y >> temp.type;
        if (temp.type != '/'){
            temp.type = 'o';
        }
        arr[x] = temp;
        used[x] = 1;
        rights[x] = 1;
        downs[x] = 1;
        ups[x] = 1;
        lefts[x] = 1;
    }
    bool foundanswer = true;
    if (check("right", 0, 0)){
        cout << 0 << "\n";
        foundanswer = false;
    }
    else{
        for (int z = 0; z < n; z++){
            for (int v = 0; v < n; v++){
                used[v] = 1;
                rights[v] = 1;
                downs[v] = 1;
                ups[v] = 1;
                lefts[v] = 1;
            }
            char original = arr[z].type;
            if (arr[z].type == '/'){
                arr[z].type = 'o';
            }
            else{
                arr[z].type = '/';
            }
            if (check("right", 0, 0)){
                cout << z + 1 << "\n";
                foundanswer = false;
                break;
            }
            else{
                arr[z].type = original;
            }
        }
    }
    if (foundanswer){
        cout << -1 << "\n";
    }

}
