#include <iostream>
#include <math.h>
#include <algorithm>
using namespace std;
void solve()
{
    int arr[20];
    int power = 1;
    for (int x = 0; x < 20; x++){
        cin >> arr[x];
        power *= 2;
    }
    int finalanswer = 100000;
    int dx[3] = {1, 0, -1};
    for (int x = 0; x < power; x++){
        int newarr[20];
        int answer = 0;
        for (int y = 0; y < 20; y++){
            newarr[y] = arr[y];
        }

        for (int y = 0; y < 20; y++){
            if ((x &(1<<y)) > 0){
                for (int z = 0; z < 3; z++){
                    int cx = y + dx[z];
                    if (cx >= 0 && cx < 20){
                        if (newarr[cx] == 1){
                            newarr[cx] = 0;
                        }
                        else{
                            newarr[cx] = 1;
                        }
                    }

                }
                answer++;
            }
        }

        bool done = true;
        for (int y = 0; y < 20; y++){
            if (newarr[y] == 1){
                done = false;
            }
        }
        if (done){
            finalanswer = min(finalanswer, answer);
        }
    }
    cout << finalanswer;

}

int main()
{
    solve();
}
