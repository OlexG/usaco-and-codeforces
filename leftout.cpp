#include <fstream>
#include <string>
#include <iostream>
using namespace std;
int main() {
    ifstream in("leftout.in");
    ofstream out("leftout.out");
    int n;
    int total = n * n;

    in >> n;
    char arr[1000][1000];
    for (int i = 0; i < n; i ++){
        for (int z = 0; z < n; z ++){
            in >> arr[i][z];
        }
    }
    for (int x = 0; x < n-1; x ++){

        if (arr[x][n - 1] != arr[n - 1][n-1]) {
            for (int y =0; y < n; y++){
                    if (arr[x][y] == 'R'){
                        arr[x][y] = 'L';
                    }
                    else {
                        arr[x][y] = 'R';
                    }
            }
        }
    }

    for (int x = 0; x < n-1; x ++){
        if (arr[n - 1][x] != arr[n - 1][n - 1]){
            for (int y =0; y < n; y++){
                if (arr[y][x] == 'R'){
                        arr[y][x] = 'L';
                    }
                    else {
                        arr[y][x] = 'R';
                    }
            }
        }
    }
    bool br = true;
    int none = 0;
    int one = 0;
    int two = 0;
    for (int x = 0; x < n; x ++){
            for (int y = 0; y < n; y ++){
                if (arr[x][y] != arr[n - 1][n - 1]){
                    if (br){
                    one = x + 1;
                    two = y + 1;

                    }

                    br = false;
                    none += 1;
                }
            }
    }
    if (none == 1){
       out << one << " " << two << "\n";
    }
    else {
        out << "-1\n" ;
    }
}

