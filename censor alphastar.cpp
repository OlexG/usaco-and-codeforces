#include <fstream>
#include <string>
#include <iostream>
#include <math.h>
#include <algorithm>
#include <vector>

using namespace std;
int main(){
    string a;
    string b;
    cin >> a >> b;
    char r[a.size()];
    int cur = 0;
    int len = b.size();
    for (int x = 0; x < a.size(); x++){
        r[cur] = a[x];
        bool fine = false;
        if (cur >= len - 1){
            for (int y = cur - len + 1; y < cur + 1; y++){
                if (r[y] != b[y - cur + len - 1]){
                    fine = true;
                }
            }
        }
        else{
            fine = true;
        }
        cur++;
        if (fine == false){
            cur -= len;
        }
    }
    for (int x = 0; x < cur; x++){
        cout << r[x];
    }
}
