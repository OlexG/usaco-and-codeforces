#include <fstream>
#include <string>
#include <iostream>
#include <math.h>
#include <algorithm>
#include <vector>
using namespace std;
vector<int> coins;
vector<int> used;
int n, m;
int answer = 0;
void rec(int cur, vector<int> used){

    if (cur == n){
        answer += 1;
    }
    else{
        for (int x = 0; x < m; x++){
            if (cur + coins[x] <= n && used[x] == 1){
                rec(cur + coins[x], used);
                used[x] = 0;
            }
        }
    }
}
int main(){
    cin >> n >> m;
    int one;
    for (int x = 0; x < m; x++){
        cin >> one;
        coins.push_back(one);
        used.push_back(1);
    }
    rec(0, used);
    cout << answer;


}
