#include <string>
#include <iostream>
#include<cmath>
using namespace std;
string lengthen(string z, int y){
    int num = z[y] - '0';
    string substring;
    substring = z.substr(y + 1, z.length());
    z = z.substr(0, y + 1);
    for (int x = 0; x < num; x ++){
        z += substring;
    }
    return z;
}
int main(){

    long long mod = 1000000000  + 7;

    unsigned long long lengthof;
    unsigned long long n;
    unsigned long long x;
    unsigned long long pos;
    int num;
    string str;
    /*pos = 0;
    str = lengthen(str, pos); */
    cin >> n;
    bool keepc = true;
    for (int b = 0; b < n; b++){
        cin >> x;
        cin >> str;
        keepc = true;
        lengthof = str.length();
        for (long long y = 0; y < x; y ++){
            if (str.size() < x){
                pos = y;
                num = str[y] - '0';
                if (num == 2){
                    str += str.substr(y + 1, str.length());
                }
                if (num == 3){
                    str += (str.substr(y + 1, str.length()) + str.substr(y + 1, str.length()));

                }
            }

            pos = str[y] - '0';

            lengthof = ((y + 1)) % mod + ((lengthof - (y + 1)) * pos) % mod;


        }
        cout << lengthof % mod << "\n";
    }
}

