#include <fstream>
#include <string>
#include <iostream>
#include <math.h>
#include <algorithm>
#include <vector>
using namespace std;

int n;

vector<vector<int>> rooms;
vector<int> arr;
int recurse(vector<int> arr, int room, int v[], int total, int prevroom){

    for (int x = 0; x < rooms[room].size(); x ++){
        if (v[rooms[room][x]] == 0){
            if (arr[rooms[room][x]] + 1 == 12){
                if (rooms[room][x] != prevroom){
                    v[rooms[room][x]] = 1;
                    arr[rooms[room][x]] = arr[rooms[room][x]] + 1;
                    return recurse(arr, rooms[room][x], v, total + 1, room);
                }
            }
            else{
            if (rooms[room][x] != prevroom){
                if (arr[rooms[room][x]] == 12){
                    arr[rooms[room][x]] = 1;
                }
                else{
                    arr[rooms[room][x]] += 1;
                }
                return recurse(arr, rooms[room][x], v, total, room);
            }
            }
        }
    }
    if (v[prevroom] == 0){
            if (arr[prevroom] + 1 == 12){

                    v[prevroom] = 1;
                    arr[prevroom] = arr[prevroom] + 1;
                    return recurse(arr, prevroom, v, total + 1, room);

            }
            else{

                if (arr[prevroom] == 12){
                    arr[prevroom] = 1;
                }
                else{
                    arr[prevroom] += 1;
                }
                return recurse(arr, prevroom, v, total, room);

            }
        }
    return total;
}
int main(){
    ifstream in("clocktree.in");
    ofstream out("clocktree.out");

    in >> n;
    int num;
    vector<int> em;
    for (int x = 0; x < n; x ++){
        in >> num;
        arr.push_back(num);
        rooms.push_back(em);
    }
    int numone;
    int numtwo;
    for (int x = 0; x < n - 1; x ++){
        in >> numone;
        in >> numtwo;
        rooms[numone - 1].push_back(numtwo - 1);
        rooms[numtwo - 1].push_back(numone - 1);
    }
    int answer = 0;

    for (int x = 0; x < n - 1; x ++){
         int v[n];
    for (int x = 0; x < n; x ++){
        v[x] = 0;
    }

        if (recurse(arr, x, v, 0, 0) == n){
            answer= answer + 1;

        }
    }
    out << answer << "\n";



}
