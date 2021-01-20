#include <fstream>
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;
int minx = 0;
int maxx = 1;
int miny = 0;
int maxy = 0;
struct point{
    int x;
    int y;
    int dir1;
    int  dir2;
};
/*
1 is up
2 is right
3 is down
4 is left
*/
point arr[4];
point fl;
point fr;
point rr;
point rl;
int n;
void mo(string type, char where){
    if (type == "FL"){
        if (where == 'F'){
            arr[0].x = arr[0].x + 1 * arr[0].dir1;
            arr[0].y = arr[0].y + 1 * arr[0].dir2;
        }
        else if (where == 'R'){
            arr[0].x = arr[0].x + 1 * arr[0].dir2;
            arr[0].y = arr[0].y + -1 * arr[0].dir1;
        }
        else if (where == 'B'){
            arr[0].x = arr[0].x + -1 * arr[0].dir1;
            arr[0].y = arr[0].y + -1 * arr[0].dir2;
        }
        else if (where == 'L'){
            arr[0].x = arr[0].x + -1 * arr[0].dir2;
            arr[0].y = arr[0].y + 1 * arr[0].dir1;
        }
    }
    else if (type == "FR"){
        if (where == 'F'){
            arr[1].x = arr[1].x + 1 * arr[1].dir1;
            arr[1].y = arr[1].y + 1 * arr[1].dir2;
        }
        else if (where == 'R'){
            arr[1].x = arr[1].x + 1 * arr[1].dir2;
            arr[1].y = arr[1].y + -1 * arr[1].dir1;
        }
        else if (where == 'B'){
            arr[1].x = arr[1].x + -1 * arr[1].dir1;
            arr[1].y = arr[1].y + -1 * arr[1].dir2;
        }
        else if (where == 'L'){
            arr[1].x = arr[1].x + -1 * arr[1].dir2;
            arr[1].y = arr[1].y + 1 * arr[1].dir1;
        }
    }
    else if (type == "RR"){
        if (where == 'F'){
            arr[2].x = arr[2].x + 1 * arr[2].dir1;
            arr[2].y = arr[2].y + 1 * arr[2].dir2;
        }
        else if (where == 'R'){
            arr[2].x = arr[2].x + 1 * arr[2].dir2;
            arr[2].y = arr[2].y + -1 * arr[2].dir1;
        }
        else if (where == 'B'){
            arr[2].x = arr[2].x + -1 * arr[2].dir1;
            arr[2].y = arr[2].y + -1 * arr[2].dir2;
        }
        else if (where == 'L'){
            arr[2].x = arr[2].x + -1 * arr[2].dir2;
            arr[2].y = arr[2].y + 1 * arr[2].dir1;
        }
    }
    else if (type == "RL"){
        if (where == 'F'){
            arr[3].x = arr[3].x + 1 * arr[3].dir1;
            arr[3].y = arr[3].y + 1 * arr[3].dir2;
        }
        else if (where == 'R'){
            arr[3].x = arr[3].x + 1 * arr[3].dir2;
            arr[3].y = arr[3].y + -1 * arr[3].dir1;
        }
        else if (where == 'B'){
            arr[3].x = arr[3].x + -1 * arr[3].dir1;
            arr[3].y = arr[3].y + -1 * arr[3].dir2;
        }
        else if (where == 'L'){
            arr[3].x = arr[3].x + -1 * arr[3].dir2;
            arr[3].y = arr[3].y + 1 * arr[3].dir1;
        }
    }
}
void decide(string type, char where){
    if (type == "FL"){
        mo(type, where);
    }
    else if (type == "FR"){
        mo(type, where);
    }
    else if (type == "RR"){
        mo(type, where);
    }
    else if (type == "RL"){
        mo(type, where);
    }
}
void rot(int x, int y){
    for (int z = 0; z < 4; z++){
        int changex = x - arr[z].x;
        int changey = arr[z].y - y;
        arr[z].x = x + changey;
        arr[z].y = y + changex;
    }
}
int main(){
    arr[0].x = 0;
    arr[0].y = 1;
    arr[0].dir1 = 0;
    arr[0].dir2 = 1;
    arr[1].x = 1;
    arr[1].y = 1;
    arr[1].dir1 = 0;
    arr[1].dir2 = 1;
    arr[2].x = 1;
    arr[2].y = 0;
    arr[2].dir1 = 0;
    arr[2].dir2 = 1;
    arr[3].x = 0;
    arr[3].y = 0;
    arr[3].dir1 = 0;
    arr[3].dir2 = 1;

    cin >> n;
    string temp;
    string type;
    bool done = false;
    for (int x = 0; x < n; x++){
        cin >> temp;
        type = "";
        type += temp[0];
        type += temp[1];
        if (temp[2] != 'P'){
            decide(type, temp[2]);
        }
        else{
            if (type == "FL"){
                rot(arr[0].x, arr[0].y);
            }
            if (type == "FR"){
                rot(arr[1].x, arr[1].y);
            }
            if (type == "RR"){
                rot(arr[2].x, arr[2].y);
            }
            if (type == "RL"){
                rot(arr[3].x, arr[3].y);
            }
        }
        for (int x = 0; x < 4; x++){
            if (temp[2] == 'P'){
                if (arr[x].dir1 == 0 && arr[x].dir2 == 1){
                    arr[x].dir1 = 1;
                    arr[x].dir2 = 0;
                }
                else if (arr[x].dir1 == 1 && arr[x].dir2 == 0){
                    arr[x].dir1 = 0;
                    arr[x].dir2 = -1;
                }
                else if (arr[x].dir1 == 0 && arr[x].dir2 == -1){
                    arr[x].dir1 = -1;
                    arr[x].dir2 = 0;
                }
                else if (arr[x].dir1 == -1 && arr[x].dir2 == 0){
                    arr[x].dir1 = 0;
                    arr[x].dir2 = 1;
                }
            }
            minx = min(minx, arr[x].x);
            maxx = max(maxx, arr[x].x);
            maxy = max(maxy, arr[x].y);
            miny = min(miny, arr[x].y);
            for (int y = 0; y < 4; y++){
                if  (x != y && arr[x].x == arr[y].x && arr[x].y == arr[y].y){
                    if (!done){
                        cout << -1;
                    }
                    done = true;
                }
            }
        }
        /*cout << arr[0].x << " " << arr[0].y << "\n";
        cout << arr[1].x << " " << arr[1].y << "\n";
        cout << arr[2].x << " " << arr[2].y << "\n";
        cout << arr[3].x << " " << arr[3].y << "\n";
        cout << "\n";*/
        if (done){
            break;
        }

    }
    if (!done){
        cout << (maxx - minx + 1) * (maxy - miny + 1);
    }
}
