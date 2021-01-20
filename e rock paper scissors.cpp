#include <fstream>
#include <string>
#include <iostream>
#include <math.h>
#include <algorithm>
#include<bits/stdc++.h>
#include <vector>
using namespace std;

int n;
int a1, b1, c1, a2, b2, c2;

int perm[3][2][2] = {{{0, 2}, {2, 0}}, {{1, 0}, {0, 1}}, {{2, 1}, {1, 2}}};
int main(){
    cin >> n >> a1 >> b1 >> c1 >> a2 >> b2 >> c2;

    int maximum = (min(a1, b2) + min(b1, c2) + min(c1, a2));

    int ca1, cb1, cc1, ca2, cb2, cc2;
    int minimum = 1e9;
    for (int one = 0; one < 2; one++){
        for (int two = 0; two < 2; two++){
            for (int three = 0; three < 2; three++){
                int arr1[3] = {a1, b1, c1};
                int arr2[3] = {a2, b2, c2};

                for (int x = 0; x < 2; x++){
                    arr1[0] -= min(arr2[perm[0][one][x]], arr1[0]);
                }
                for (int x = 0; x < 2; x++){
                    arr1[1] -= min(arr2[perm[1][two][x]], arr1[1]);
                }
                for (int x = 0; x < 2; x++){
                    arr1[2] -= min(arr2[perm[2][three][x]], arr1[2]);
                }
                minimum = min(minimum, arr1[0] + arr1[1] + arr1[2]);
            }
        }
    }
    cout << minimum << " " << maximum << "\n";
}
