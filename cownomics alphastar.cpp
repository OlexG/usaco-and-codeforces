#include <fstream>
#include <string>
#include <iostream>
#include <math.h>
#include <algorithm>
#include <vector>
using namespace std;
int n, m;
int convert(char one){
    if (one == 'A'){
        return 1;
    }
    if (one == 'C'){
        return 2;
    }
    if (one == 'G'){
        return 3;
    }
    else{
        return 4;
    }
}
int main(){
    cin >> n >> m;
    int spoted[n][m];
    int plain[n][m];
    char one;
    for (int x = 0; x < n; x++){
        for (int y = 0; y < m; y++){
            cin >> one;
            spoted[x][y] = convert(one);
        }
    }
    for (int x = 0; x < n; x++){
        for (int y = 0; y < m; y++){
            cin >> one;
            plain[x][y] = convert(one);
        }
    }
    int used[128];
    int total = 0;
    for (int i = 0; i < m - 2; i++){
        for (int j = i + 1; j < m - 1; j++){
            for (int k = j + 1; k < m; k++){
                for (int x = 0; x < 128; x++){
                    used[x] = 0;
                }
                for (int x = 0; x < n; x++){
                    used[spoted[x][i] * 16 + spoted[x][j] * 4 + spoted[x][k]] = 1;
                }
                bool answer = true;
                for (int x = 0; x < n; x++){
                    if (used[plain[x][i] * 16 + plain[x][j] * 4 + plain[x][k]] == 1){
                        answer = false;
                    }
                }
                if (answer){
                    total++;
                }
            }
        }
    }
    cout << total;
}
