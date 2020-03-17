
#include <fstream>
#include <string>
#include <iostream>
#include <math.h>
#include <algorithm>
#include <cstdio>
using namespace std;
int n;
string maze = "";
int answer = 0;
void rec(int l, int r, char start, bool switched, int x, int y, char visited[]){


    if (l == r && l != 0){
        if (l * 2 > answer){
            answer = l * 2;
        }
    }
    else {
        if (!switched){
            if (y < n - 1 && visited[(x) * n + y + 1] != 1){
                visited[(x) * n + y + 1] = 1;
                if (maze[(x) * n + y + 1] == start){
                    rec(l + 1, r, start, false, x, y + 1, visited);
                }
                else{
                    rec(l, r + 1, start, true, x, y + 1, visited);
                }
                visited[(x) * n + y + 1] = 0;
            }
             if (y > 0 && visited[(x) * n + y - 1] != 1){
                visited[(x) * n + y - 1] = 1;
                if (maze[(x) * n + y - 1] == start){
                    rec(l + 1, r, start, false, x, y - 1, visited);
                }
                else{
                    rec(l, r + 1, start, true, x, y - 1, visited);
                }
                visited[(x) * n + y - 1] = 0;
            }
            if (x > 0 && visited[(x - 1) * n + y] != 1){
                visited[(x - 1) * n + y ] = 1;
                if (maze[(x - 1) * n + y ] == start){
                    rec(l + 1, r, start, false, x - 1, y, visited);
                }
                else{
                    rec(l, r + 1, start, true, x - 1, y, visited);
                }
                visited[(x - 1) * n + y] = 0;
            }

            if (x < n - 1 && visited[(x + 1) * n + y] != 1){

                visited[(x + 1) * n + y] = 1;
                if (maze[(x + 1) * n + y] == start){
                    rec(l + 1, r, start, false, x + 1, y, visited);
                }
                else{
                    rec(l, r + 1, start, true, x + 1, y, visited);
                }
                visited[(x + 1) * n + y] = 0;
            }



        }
        else{
            if (y < n - 1 && visited[(x) * n + y + 1] != 1){
                visited[(x) * n + y + 1] = 1;
                if (maze[(x) * n + y + 1] != start){
                    rec(l, r + 1, start, true, x, y + 1, visited);
                }
                visited[(x) * n + y + 1] = 0;
            }
             if (y > 0 && visited[(x) * n + y - 1] != 1){
                visited[(x) * n + y - 1] = 1;
                if (maze[(x) * n + y - 1] != start){
                    rec(l, r + 1, start, true, x, y - 1, visited);
                }
                visited[(x) * n + y - 1] = 0;
            }
            if (x > 0 && visited[(x - 1) * n + y] != 1){

                visited[(x - 1) * n + y] = 1;

                if (maze[(x - 1) * n + y] != start){

                    rec(l, r + 1, start, true, x - 1, y, visited);
                }
                visited[(x - 1) * n + y] = 0;
            }
            if (x < n - 1 && visited[(x + 1) * n + y] != 1){
                visited[(x + 1) * n + y] = 1;
                if (maze[(x + 1) * n + y] != start){
                    rec(l, r + 1, start, true, x + 1, y, visited);
                }
                visited[(x + 1) * n + y] = 0;
            }
        }
    }

}
int main(){
    cin >> n;
    string temp;
    for (int x = 0; x < n; x ++){
        cin >> temp;
        maze += temp;

    }

    getchar();
    char visited[n];
    visited[0] = 1;
    if (maze[0] == '('){
    rec(1, 0, maze[0], false, 0, 0, visited);
    }
    cout << answer;



}
