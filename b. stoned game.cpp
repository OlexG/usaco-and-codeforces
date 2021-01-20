#include <fstream>
#include <string>
#include <iostream>
#include <math.h>
#include <algorithm>
#include<bits/stdc++.h>
#include <vector>
using namespace std;

int t, n;

int main(){
    cin >> t;
    for (int b = 0; b < t; b++){
        cin >> n;
        vector<int> arr;
        int temp;
        for (int x = 0;  x < n; x++){
            cin >> temp;
            arr.push_back(temp);
        }
        sort(arr.rbegin(), arr.rend());
        int counter = 0;
        int firstwins = false;
        int sum = 0;
        for (int x = 0; x < n; x++){
            sum += arr[x];
        }
        if (sum % 2 == 1){
            firstwins = true;
        }
        else{
            /*while(true){
                //cout << counter << "\n";
                if (counter >= n){
                    break;
                }
                if (arr[counter] == 0){
                    counter++;
                    continue;
                }
                int first = arr[counter];
                if (first <= 0){
                    counter++;
                    continue;
                }
                //cout << first << "\n";
                int starting = counter + 1;
                int del = 0;
                while(true){
                    if (starting >= n){
                        firstwins = true;
                        break;
                    }
                    for (int x = n - 1; x >= starting; x--){
                        if (x == starting){
                            if (arr[starting] <= 0 && del < first){
                                firstwins = true;
                                break;
                            }
                            arr[x]--;
                            del++;
                        }
                        else{
                            if (arr[x - 1] == arr[x]){
                                arr[x]--;
                                del++;
                            }
                        }
                        if (del == first){
                            break;
                        }
                    }
                    if (firstwins){
                        break;
                    }
                    if (arr[starting] == 0 && del < first){
                        firstwins = true;
                        break;
                    }
                    if (del == first){
                        break;
                    }
                }
                counter++;
            }*/
            sum = sum - arr[0];
            if (arr[0] > sum){
                firstwins = true;
            }
        }

        if (firstwins){
            cout << "T\n";
        }
        else{
            cout << "HL\n";
        }
    }
}
