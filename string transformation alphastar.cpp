#include <fstream>
#include <string>
#include <iostream>
#include <math.h>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;
int t, n;
string a, b;

bool works(string a, string b){
    for (int x = 0; x < n; x++){
        if (b[x] < a[x]){
            return false;
        }
    }
    return true;
}
char alphabet[20] = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t'};
int main(){
    cin >> t;
    for (int z = 0; z < t; z++){
        cin >> n;
        cin >> a >> b;
        if (works(a, b)){
            int answer = 0;
            for (int x = 0; x < 20; x++){
                char curletter = alphabet[x];
                char smallestletter = 't';
                bool addanswer = false;
                for (int y = 0; y < n; y++){
                    if (a[y] < b[y] && a[y] == curletter){
                        addanswer = true;
                        if (b[y] < smallestletter){
                            smallestletter = b[y];
                        }
                    }
                }
                for (int y = 0; y < n; y++){
                    if (a[y] < b[y] && a[y] == curletter){
                        a[y] = smallestletter;
                    }
                }
                if (addanswer){
                    answer++;
                }
            }
            cout << answer << "\n";
        }
        else{
            cout << -1 << "\n";
        }
    }
}
