#include <fstream>
#include <string>
#include <iostream>
#include <math.h>
#include <algorithm>
using namespace std;
int n;
char dirnums[15][15];
int total = 0;
void recurse(int sum, string curr, int n){
    if (sum == n){

         total = total + 1;
    }
    else {

        char possible[3] = {'H', 'J', 'G'};
        for (int x = 0; x < sum; x ++){
            if (dirnums[sum][x] == 'S'){
                if (possible[0] == curr[x] || possible[1] == curr[x] || possible[2] == curr[x]){
                for (int y = 0; y < 3; y ++){
                    possible[y] = 'N';
                }

                possible[0] = curr[x];
                }
                else {
                    for (int y = 0; y < 3; y ++){
                    possible[y] = 'N';
                }
                }
            }
            if (dirnums[sum][x] == 'D'){
                for (int y = 0; y < 3; y ++){
                    if (possible[y] == curr[x]){
                        possible[y] = 'N';
                    }
                }
            }
        }

        for (int y = 0; y < 3; y ++){
            if (possible[y] != 'N'){
                string ok = curr + possible[y];
                recurse(sum + 1, ok, n);
            }

        }

    }
}
int main(){
    int n;
    int m;
    cin >> n;
    cin >> m;
    char one;
    int two;
    int three;

    for (int x = 0; x < m; x ++){
        cin >> one;
        cin >> two;
        cin >> three;
        dirnums[two - 1][three - 1] = one;
        dirnums[three - 1][two - 1] = one;
    }
    recurse(0, "", n);
    cout << total << "\n";


}
