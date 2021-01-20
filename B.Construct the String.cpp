#include <fstream>
#include <string>
#include <iostream>
#include <math.h>
#include <algorithm>
#include <vector>
using namespace std;
int n, t, a, b;
char al[26] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
int main(){
    cin >> t;
    for (int y = 0; y < t; y++){
        string s = "";
        cin >> n >> a >> b;
        for (int x = 0; x < b; x++){
            s += al[x];
        }
        for (int x = b; x < a; x++ ){
            s += 'a';
        }
        for (int x = 1; x < n - a + 1; x++){
            s = s + s[x - 1];
        }
        cout << s << "\n";
    }

}
