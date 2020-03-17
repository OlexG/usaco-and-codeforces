#include <fstream>
#include <string>
#include <iostream>
#include <math.h>
#include <algorithm>
#include<bits/stdc++.h>
using namespace std;

int l;
int n;
char alphabet[26] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
char vowels[5] = {'a', 'e', 'i', 'o','u'};

void recurse(int vused, int length, char arr[], string churstring){
    if (churstring.size() == l && vused >= 1 && l - vused >= 2){
        cout << churstring << "\n";
    }
    else if (length < n){

        bool vowel = false;
        for (int x = 0; x < 6; x ++){
            if (arr[length] == vowels[x]){
                vowel = true;
            }
        }
        if (vowel){
            recurse(vused + 1, length + 1, arr, churstring + arr[length]);
        }
        else{
            recurse(vused, length + 1, arr, churstring + arr[length]);
        }
        recurse(vused, length + 1, arr, churstring);

    }
}
int main(){
    cin >> l;
    cin >> n;
    char arr[l];
    for (int x = 0; x < n; x ++){
        cin >> arr[x];
    }
    sort(arr, arr+n);
    recurse(0, 0, arr, "");



}
