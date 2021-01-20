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
    int arr[n];
    int power = 1;
    for (int x = 0; x < n; x++){
        cin >> arr[x];
        power *= 2;
    }
    int answer = 0;
    for (int x = 0; x < power; x++){
        bool carry = false;
        long long curanswer = 0;
        int sol = 0;
        for (int y = 0; y < n; y++){
            if ((x &(1<<y)) > 0){
                string curstring = to_string(curanswer);
                string newstring = to_string(arr[y]);
                if (curstring.size() <= newstring.size()){
                    for (int z = 0; z < curstring.size(); z++){
                        int one = curstring[z] - '0';
                        int two = newstring[z + newstring.size() - curstring.size()] - '0';
                        if (one + two > 9){
                            carry = true;
                        }
                    }
                }
                else{
                     for (int z = 0; z < newstring.size(); z++){
                        int one = newstring[z] - '0';
                        int two = curstring[z + curstring.size() - newstring.size()] - '0';
                        if (one + two > 9){
                            carry = true;
                        }
                    }
                }
                if (carry){
                    break;
                }
                else{
                    curanswer += arr[y];
                    sol++;
                }
            }
        }
        if(!carry){
            answer = max(answer, sol);
        }
    }
    cout << answer;
}
