#include <fstream>
#include <string>
#include <iostream>
#include <math.h>
#include <algorithm>
#include <vector>
using namespace std;
int convert(char temp){
    if (temp == '1'){
        return 1;
    }
    if (temp == '2'){
        return 2;
    }
    if (temp == '3'){
        return 3;
    }
    if (temp == '4'){
        return 4;
    }
    if (temp == '5'){
        return 5;
    }
    if (temp == '6'){
        return 6;
    }
    if (temp == '7'){
        return 7;
    }
    if (temp == '8'){
        return 8;
    }
    if (temp == '9'){
        return 9;
    }
    if (temp == 'A'){
        return 1;
    }
    if (temp == 'T'){
        return 10;
    }
    if (temp == 'J'){
        return 11;
    }
    if (temp == 'Q'){
        return 12;
    }
    if (temp == 'K'){
        return 13;
    }

}
int n;
int main(){
    cin >> n;
    int arr[n + 1][n + 1];
    string temp;
    for (int x = 0; x < n; x++){
        arr[x][0] = 0;
        for (int y = 1; y < n + 1; y++){
            cin >> temp;
            arr[x][y] = convert(temp[0]);
        }

    }
    for (int x = 0; x < n + 1; x++){
        arr[n][x] = 0;
    }
    for (int x = n - 1; x >= 0; x--){
        for (int y = 1; y < n + 1; y++){
            arr[x][y] = max(arr[x][y] + arr[x + 1][y], arr[x][y] + arr[x][y - 1]);
        }
    }
    cout << arr[0][n];
}
