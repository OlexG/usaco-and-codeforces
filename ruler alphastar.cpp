#include <fstream>
#include <string>
#include <iostream>
#include <math.h>
using namespace std;
#include <vector>

void rec(int n){
    if (n == 1){
        cout << '*';
    }
    else {
        rec(n - 1);
        cout << "\n";
        for(int x = 0; x < n; x ++){
        cout << '*';
        }
        cout << "\n";
        rec(n - 1);



    }
}
int main() {
    int n;
    cin >> n;
    for(int x = 0; x < n; x ++){
        cout << '*';
    }
    cout << "\n";
    rec(n - 1);
    cout << "\n";
    for(int x = 0; x < n; x ++){
        cout << '*';
    }
    cout << "\n";

}
