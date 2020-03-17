#include <string>
#include <iostream>
using namespace std;
int main(){
    int n;
    int one;
    int two;
    cin >> n;
    for (int x = 0; x < n; x++){
        cin >> one;
        cin >> two;
        cout << 1440 - one*60 - two;
        cout << "\n";
    }
}
