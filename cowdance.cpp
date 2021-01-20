#include <fstream>
#include <string>
#include <iostream>
#include <math.h>
#include <algorithm>
#include <vector>
using namespace std;
int n, t;
int arr[10000];
long long ok(int x){
    int index = 0;
    int mi = 100001;
    int ma = 0;
    int miindex;

    long long total = 0;
    vector<int> cur;
    while(index < x){
        cur.push_back(arr[index]);
        mi = min(arr[index], mi);
        index++;
    }
    total = total + mi;
    int y = x;
    while(cur.size() > 0){
        int num = 0;
        for (int z = cur.size() - 1; z >= 0; z--){
            if (cur[z] == mi){
                num++;
                cur.erase(cur.begin() + z);
            }
        }
        for (int z = 0; z < cur.size(); z++){
            cur[z] -=mi;
        }
        for (int z = 0; z < num; z++){
            if (y < n){
                cur.push_back(arr[y]);
            }
            y += 1;
        }

        mi = 100001;
        for (int z = 0; z < cur.size(); z++){
            mi = min(cur[z], mi);
        }
        /*for (int z = 0; z < cur.size(); z++){
            cout << cur[z];
        }
        cout << "\n";*/
        if (mi != 100001){
            total += mi;
        }
    }
    return total;

}
int main(){
    ifstream in("cowdance.in");
    ofstream out("cowdance.out");
    in >> n >> t;
    for (int x = 0; x < n; x++){
        in >> arr[x];
    }
    long long low = 1;
    long long high = n;
    long long x;

    while(low < high){
        x = (low + high)/2;
        if (ok(x) <= t){
            high = x;
        }
        else{
            low = x + 1;
        }

    }
    out << high << "\n";


}
