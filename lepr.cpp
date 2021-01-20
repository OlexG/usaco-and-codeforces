#include <fstream>
#include <string>
#include <iostream>
#include <math.h>
#include <algorithm>
#include <vector>
using namespace std;
int n;

int main(){
    cin >> n;
    int arr[n][n];
    for (int x = 0; x < n; x++){
        for (int y = 0; y < n; y++){
            cin >> arr[x][y];
        }
    }
    vector<int> cur;
    int answer = -100000;
    for (int x = 0; x < n; x++){
        cur.clear();
        cur.push_back(0);
        for (int y = 0; y < n; y++){
            cur.push_back(arr[x][y]);
        }
        for (int y = 2; y < n + 1; y++){
            cur[y] = cur[y] + cur[y - 1];
        }

        for (int y = 0; y < n + 1; y++){
            for (int z = 1; z < n + 1; z++){
                if (y != z){
                    if (y < z){
                        answer = max(answer, cur[z] - cur[y]);
                    }
                    else{
                        answer = max(answer, cur[n] - cur[y] + cur[z]);
                    }
                }
            }
        }
    }
    for (int x = 0; x < n; x++){
        cur.clear();
        cur.push_back(0);
        for (int y = 0; y < n; y++){
            cur.push_back(arr[y][x]);
        }
        for (int y = 2; y < n + 1; y++){
            cur[y] = cur[y] + cur[y - 1];
        }
        /*for (int y = 0; y < n + 1; y++){
            cout << cur[y];
        }
        cout << "\n";*/
        for (int y = 0; y < n + 1; y++){
            for (int z = 1; z < n + 1; z++){
                if (y != z){
                    if (y < z){
                        answer = max(answer, cur[z] - cur[y]);
                    }
                    else{
                        answer = max(answer, cur[n] - cur[y] + cur[z]);
                    }
                }
            }
        }
    }
     for (int x = 0; x < n; x++){
        cur.clear();
        cur.push_back(0);
        int xc = x;
        int yc = 0;
        for (int y = 0; y < n; y++){
            cur.push_back(arr[xc][yc]);
            xc++;
            yc--;
            if (xc >= n){
                xc = 0;
            }
            if (xc < 0){
                xc = n - 1;
            }
            if (yc >= n){
                yc = 0;
            }
            if (yc < 0){
                yc = n - 1;
            }
        }
        /*for (int y = 0; y < n + 1; y++){
            cout << cur[y];
        }
        cout << "\n";*/
        for (int y = 2; y < n + 1; y++){
            cur[y] = cur[y] + cur[y - 1];
        }
        for (int y = 0; y < n + 1; y++){
            for (int z = 1; z < n + 1; z++){
                if (y != z){
                    if (y < z){
                        answer = max(answer, cur[z] - cur[y]);
                    }
                    else{
                        answer = max(answer, cur[n] - cur[y] + cur[z]);
                    }
                }
            }
        }
    }
    for (int x = 0; x < n; x++){
        cur.clear();
        cur.push_back(0);
        int xc = x;
        int yc = 0;
        for (int y = 0; y < n; y++){
            cur.push_back(arr[xc][yc]);
            xc++;
            yc++;
            if (xc >= n){
                xc = 0;
            }
            if (xc < 0){
                xc = n - 1;
            }
            if (yc >= n){
                yc = 0;
            }
            if (yc < 0){
                yc = n - 1;
            }
        }
        /*for (int y = 0; y < n + 1; y++){
            cout << cur[y];
        }
        cout << "\n";*/
        for (int y = 2; y < n + 1; y++){
            cur[y] = cur[y] + cur[y - 1];
        }
        for (int y = 0; y < n + 1; y++){
            for (int z = 1; z < n + 1; z++){
                if (y != z){
                    if (y < z){
                        answer = max(answer, cur[z] - cur[y]);
                    }
                    else{
                        answer = max(answer, cur[n] - cur[y] + cur[z]);
                    }
                }
            }
        }
    }
    cout << answer;

}
