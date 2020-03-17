#include <fstream>
#include <string>
#include <iostream>
#include <math.h>
#include <algorithm>
#include <vector>
using namespace std;
int n;
int m;
long long k;

int main(){
    ifstream in("swap.in");
    ofstream out("swap.out");
    in >> n;
    in >> m;
    in >> k;
    int arr[m][2];
    for (int x = 0; x < m; x ++){
        in >> arr[x][0];
        in >> arr[x][1];
    }

    int r[n];
    int cc[n];
    int pos[n];

    vector<int> sets[n];
    int index;
    for (int x = 1; x < n + 1; x ++ ){
        cc[x-1] = 0;
        index = x;
        for (int y = 0; y < m; y ++){
            if (index >= arr[y][0] && index <= arr[y][1]){
                index = arr[y][0] + arr[y][1]- index;
            }

        }
        r[index - 1] = x;

    }



    int counter = 0;

    for (int x = 1; x < n + 1; x ++ ){

        if (cc[x - 1] == 0){
            cc[x - 1] = x - 1;
            pos[x - 1] = 0;
            int j = r[x - 1];
            sets[x-1].push_back(x);
            if (j != x){
                sets[x-1].push_back(j);
                cc[j - 1] = x - 1;
                pos[j - 1] = 1;
            }
            counter = 1;

            while (j != x ){
                j = r[j - 1];
                if (j != x){
                    cc[j - 1] = x - 1;
                    sets[x-1].push_back(j);

                    pos[j - 1] = counter + 1;
                }
                counter = counter + 1;
            }

        }

    }

    for (int x = 0; x < n; x++){
        out << sets[cc[x]][(pos[x] + k ) % sets[cc[x]].size()] << "\n";
    }



}
