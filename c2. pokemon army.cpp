#include <fstream>
#include <string>
#include <iostream>
#include <math.h>
#include <algorithm>
#include<bits/stdc++.h>
#include <vector>
using namespace std;


int t, n, q;
/*1 7 0 1 2 3 4 3 2 6*/


int main(){
    cin >> t;
    for (int z = 0; z < t; z++){
        cin >> n >> q;
        int arr[n];
        for (int x = 0; x < n; x++){
            cin >> arr[x];
        }
        vector<pair<int, int>> swaps;
        int one, two;
        for (int x = 0; x < q; x++){
            cin >> one >> two;
            swaps.push_back(make_pair(one, two));
        }
        bool cu = true;
        int cursum = 0;
        for (int x = 0; x < n; x++){
            if (x != n - 1){
                if (cu){
                    if (arr[x + 1] < arr[x]){
                        cursum += arr[x];
                        cu = false;
                    }
                }
                else{
                    if (arr[x + 1] > arr[x]){
                        cursum -= arr[x];
                        cu = true;
                    }
                }
            }
            else{
                if (x != 0){
                    if (cu){
                        cursum += arr[x];
                    }
                }
            }
        }
        cout << cursum << "\n";
        for (int x = 0; x < q; x++){
            if (n != 1){

                int one = arr[swaps[x].first - 1];
                int two = arr[swaps[x].second - 1];
                int one_index = swaps[x].first - 1;
                int two_index = swaps[x].second - 1;

                if (one_index == 0){
                    if (one > arr[one_index + 1]){
                        cursum -= one;
                    }
                }
                else if (one_index == n - 1){
                    if (one > arr[one_index - 1]){
                        cursum -= one;
                    }
                }
                else{
                    if (one <= arr[one_index - 1] && one < arr[one_index + 1]){
                        cursum += one;
                    }
                    else if (one >= arr[one_index - 1] && one > arr[one_index + 1]){
                        cursum -= one;
                    }
                }


                if (two_index == 0){
                    if (two > arr[two_index + 1]){
                        cursum -= two;
                    }
                }
                else if (two_index == n - 1){
                    if (two > arr[two_index - 1]){
                        cursum -= two;
                    }
                }
                else{
                    if (two <= arr[two_index - 1] && two < arr[two_index + 1]){
                        cursum += two;
                    }
                    else if (two >= arr[two_index - 1] && two > arr[two_index + 1]){
                        cursum -= two;
                    }
                }

                arr[two_index] = one;
                arr[one_index] = two;

                if (one_index == 0){
                    if (two > arr[one_index + 1]){
                        cursum += two;
                    }
                    if (one <= arr[one_index + 1]){
                        cursum -= arr[one_index + 1];
                        if (one_index + 1 < n - 1){
                            if (arr[one_index + 2] < arr[one_index + 1]){
                                cursum -= arr[one_index + 1];
                            }
                        }
                    }
                }
                else if (one_index == n - 1){
                    if (two > arr[one_index - 1]){
                        cursum += two;
                    }
                    if (one <= arr[one_index - 1]){
                        cursum -= arr[one_index - 1];
                    }
                }
                else{
                    if (two <= arr[one_index - 1] && two < arr[one_index + 1]){
                        cursum -= two;
                        if (one > arr[one_index + 1]){
                            cursum += arr[one_index + 1];
                            if (one_index + 1 < n - 1){
                                if (arr[one_index + 2] > arr[one_index + 1]){
                                    cursum += arr[one_index + 1];
                                }
                            }
                        }
                        if (one > arr[one_index - 1]){
                            cursum += arr[one_index - 1];
                        }

                    }
                    else if (two >= arr[one_index - 1] && two > arr[one_index + 1]){
                        cursum += two;

                    }
                }


                if (two_index == 0){
                    if (one > arr[two_index + 1]){
                        cursum += one;
                    }
                    if (two <= arr[two_index + 1]){
                        cursum -= arr[two_index + 1];
                        if (two_index + 1 < n - 1){
                            if (arr[two_index + 2] < arr[two_index + 1]){
                                cursum -= arr[two_index + 1];
                            }
                        }
                    }
                }
                else if (two_index == n - 1){
                    if (one > arr[two_index - 1]){
                        cursum += one;
                    }
                    if (two <= arr[two_index - 1]){
                        cursum -= arr[two_index - 1];
                    }
                }
                else{
                    if (one <= arr[two_index - 1] && one < arr[two_index + 1]){
                        cursum -= one;
                    }
                    else if (one >= arr[two_index - 1] && one > arr[two_index]){
                        cursum += one;
                    }
                }
            }
            cout << cursum << "\n";
        }
    }
}
