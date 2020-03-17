#include <fstream>
#include <string>
#include <iostream>
#include <math.h>
#include <algorithm>
#include <string>
using namespace std;
int n;
int total = 0;
void recurse(int num1,int num0, string result){

    if (result.length() == n){
        if (num1 > num0){
            cout << result << "\n";
            total = total + 1;
        }
    }
    else{
        recurse(num1, num0 + 1, result + "0");
        recurse(num1 + 1, num0, result + "1");

    }
}
int main(){
    cin >> n;
    recurse(0, 0, "");
    cout << total << "\n";
}
