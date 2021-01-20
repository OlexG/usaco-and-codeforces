#include <fstream>
#include <string>
#include <iostream>
#include <math.h>
#include <algorithm>
#include <vector>
#include<cmath>
using namespace std;
long long n;
vector<string> arr;
 long long power(int x, int y){
        long long answer = 1;
        for (int z = 0; z < y; z++){
            answer *= x;
        }
        return answer;
    }
int main(){
    cin >> n;
    int x = 0;
    bool none = true;
    string temp;
    while(cin >> temp){
        arr.push_back(temp);
        x++;
    }
    long long numsize = to_string(n).size();
    for (int x = 0; x < arr.size(); x++){
        if (arr[x].size() == numsize){
            long long answer = 0;
            for (int y = numsize - 1; y >= 0; y--){
                long long pos = ((int)arr[x][y] - 65)/3 + 2;
                if ((int)arr[x][y] - 65 >= 18){
                    pos = ((int)arr[x][y] - 66)/3 + 2;
                }
                answer = answer + pos * power(10, numsize - y - 1);
            }
            if (answer == n){
                none = false;
                cout << arr[x] << "\n";
            }
        }

    }
    if (none){
        cout << "NONE\n";
    }
}
