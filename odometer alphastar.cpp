#include <fstream>
#include <string>
#include <iostream>
#include <math.h>
#include <algorithm>
#include <vector>
using namespace std;
long long a,b;
int main(){
    cin >> a >> b;
    long long alen = to_string(a).size();
    long long blen = to_string(b).size();
    int answer = 0;
    for (int z = alen; z < blen + 1; z++){
        for (int v = 0; v < z; v++){

            for (int x = 0; x < 10; x++){
                for (int y = 1; y < 10; y++){
                    if (x != y){
                        if (v != z - 1 || x != 0){
                            long long temp = 0;
                            long long cur = 1;
                            for (int c = 0; c < z; c++){

                                if (c != v){
                                    temp += cur * y;
                                    cur *= 10;
                                }
                                else{
                                    temp += cur * x;
                                    cur *= 10;
                                }

                            }
                            if (temp >= a && temp <= b){

                                answer++;
                            }
                        }

                    }

                }
            }

        }
        long long ntemp = 0;
        long long ncur = 1;
        for (int v = 0; v < z - 1; v++){
            ncur *= 10;
        }
        for (int x = 1; x < 10; x++){
            ntemp = ncur * x;
            if (ntemp >= a && ntemp <= b){

                answer++;
            }
        }
    }
    cout << answer;
}
