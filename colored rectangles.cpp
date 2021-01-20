#include <fstream>
#include <string>
#include <iostream>
#include <math.h>
#include <algorithm>
#include <vector>
using namespace std;

int x, y, z;
int answer = 0;
int dp[201][201][201];
vector<int> a, b, c;
/*int rec(int one, int two, int three){
    //cout << one << " " << two << " " << three << "\n";
    answer = max(answer, dp[one][two][three]);
    if (one <= x - 1 && two <= y - 1){
        dp[one + 1][two + 1][three] = a[one] * b[two] + dp[one][two][three];
        rec(one + 1, two + 1, three);
    }
    if (one <= x - 1 && three <= z - 1){
        dp[one + 1][two][three + 1] = a[one] * c[three] + dp[one][two][three];
        rec(one + 1, two, three + 1);
    }
    if (two <= y - 1 && three <= z - 1){
        dp[one][two + 1][three + 1] = b[two] * c[three] + dp[one][two][three];
        rec(one , two + 1, three + 1);
    }
}*/
int main(){
    cin >> x >> y >> z;
    int temp;
    for (int q = 0; q < x; q++){
        cin >> temp;
        a.push_back(temp);
    }
    for (int q = 0; q < y; q++){
        cin >> temp;
        b.push_back(temp);
    }
    for (int q = 0; q < z; q++){
        cin >> temp;
        c.push_back(temp);
    }
    sort(a.rbegin(), a.rend());
    sort(b.rbegin(), b.rend());
    sort(c.rbegin(), c.rend());
    for (int q = 0; q < x + 1; q++){
        for (int w = 0; w < y + 1; w++){
            for (int e = 0; e < z + 1; e++){
                dp[q][w][e] = 0;
            }
        }
    }
    for (int q = 0; q < x + 1; q++){
        for (int w = 0; w < y + 1; w++){
            for (int e = 0; e < z + 1; e++){
                if (q <= x - 1 && w <= y - 1){
                    dp[q + 1][w + 1][e] = max(dp[q + 1][w + 1][e], a[q] * b[w] + dp[q][w][e]);
                }
                if (q <= x - 1 && e <= z - 1){
                    dp[q + 1][w][e + 1] = max(dp[q + 1][w][e + 1], a[q] * c[e] + dp[q][w][e]);
                }
                if (w <= y - 1 && e <= z - 1){
                    dp[q][w + 1][e + 1] = max(dp[q][w + 1][e + 1], b[w] * c[e] + dp[q][w][e]);
                }
                answer = max(answer, dp[q][w][e]);
            }
        }
    }
    cout << answer << "\n";
}
