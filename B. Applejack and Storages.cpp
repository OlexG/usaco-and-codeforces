#include <fstream>
#include <string>
#include <iostream>
#include <math.h>
#include <algorithm>
#include<bits/stdc++.h>
#include <vector>
using namespace std;

int n;

int main(){
    cin >> n;
    multiset<int> fr;
    int arr[100000];
    for (int x = 0; x < 100000; x++){
        arr[x] = 0;
    }
    int temp;
    for (int x = 0; x < n; x++){
        cin >> temp;
        arr[temp - 1] += 1;
    }
    int q;
    cin >> q;
    for (int x = 0; x < 100000; x++){
        fr.insert(arr[x]);
    }
    for (int x = 0; x < q; x++){
        char one;
        cin >> one;
        int two;
        cin >> two;
        fr.erase(fr.find(arr[two - 1]));
        if (one == '+'){
            arr[two - 1] += 1;
        }
        else{
            arr[two - 1] -= 1;
        }
        fr.insert(arr[two - 1]);
        int n1 = 0;
        int n2 = 0;
        int n3 = 0;
        if (fr.size() >= 1){
            n1 = *prev(fr.end(), 1);
        }
        if (fr.size() >= 2){
            n2 = *prev(fr.end(), 2);
        }
        if (fr.size() >= 3){
            n3 = *prev(fr.end(), 3);
        }
        bool works = false;
        if (n1 >= 4){
            n1 -= 4;
            if (n1 >= 4){
                works = true;
            }
            if (n1 >= 2){
                if (n2 >= 2){
                    works = true;
                }
            }
            if (n2 >= 4){
                works = true;
            }
            if (n2 >= 2 && n3 >= 2){
                works = true;
            }
        }
        if (works){
            cout << "YES\n";
        }
        else{
            cout << "NO\n";
        }

    }
}
