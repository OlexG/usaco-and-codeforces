#include <fstream>
#include <string>
#include <iostream>
#include <math.h>
#include <algorithm>
#include <vector>
#include <iomanip>
using namespace std;

int n;
int main(){
    cin >> n;
    int arr[n];
    for (int x = 0; x < n; x++){
        cin >> arr[x];
    }
    sort(arr, arr + n);
    int setdown[n];
    int counter = 0;
    for (int x = 1; x < n - 1; x += 2){
        setdown[x] = arr[counter];
        counter ++;
    }
    int point1 = counter;
    int point2 = n - 1;
    int startingpoint = 0;
    if (n%2 == 0){
        startingpoint = n - 3;
        setdown[n - 1] = arr[point1];
        point1++;
    }
    else{
        startingpoint = n - 2;
    }
    while(point1 < point2){
        if (arr[point2] > setdown[startingpoint] && arr[point2 - 1] > setdown[startingpoint]){
            setdown[startingpoint + 1] = arr[point2];
            point2--;
        }
        else{
            setdown[startingpoint + 1] = arr[point1];
            point1++;
        }
        startingpoint -= 2;
    }
    setdown[0] = arr[point2];
    int answer = 0;
    for (int y = 1; y < n - 1; y += 2){
        if (setdown[y] < setdown[y - 1] && setdown[y] < setdown[y + 1]){
            answer++;
        }
    }
    cout << answer << "\n";
    for (int x = 0; x < n; x++){
        cout << setdown[x] << " ";
    }

}
