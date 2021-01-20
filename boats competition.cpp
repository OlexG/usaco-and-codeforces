#include <fstream>
#include <string>
#include <iostream>
#include <math.h>
#include <algorithm>
#include <vector>
using namespace std;

int t, n;
int avenums[51];
int main(){
    cin >> t;
    for (int m = 0; m < t; m++){
        cin >> n;
        vector<int> arr;
        int temp;
        for (int x = 0; x < 50; x++){
            avenums[x] = 0;
        }
        for (int x = 0; x < n; x++){
            cin >> temp;
            arr.push_back(temp);
            avenums[temp - 1] += 1;
        }
        int used[51];
        int answer = 0;
        for (int x = 0; x < n * 2 + 1; x++){
            int nanswer = 0;
            vector<int> avenumsc;
            for (int y = 0; y < n; y++){
                avenumsc.push_back(avenums[y]);
                used[y] = 1;
            }

            for (int y = 0; y < n; y++){
                if (x - arr[y] - 1 >= 0 && x - arr[y] - 1 <= n - 1){
                    if (arr[y] != x - arr[y]){
                        if (avenumsc[arr[y] - 1] > 0 && avenumsc[x - arr[y] - 1] > 0){
                            nanswer++;
                            avenumsc[arr[y] - 1] -= 1;
                            avenumsc[x - arr[y]  - 1 ] -= 1;
                        }
                    }
                    else{
                        if (avenumsc[arr[y] - 1] > 1){
                            nanswer++;
                            avenumsc[arr[y] - 1] -= 1;
                            avenumsc[x - arr[y]  - 1 ] -= 1;
                        }
                    }
                }
            }
            answer = max(answer, nanswer);
        }
        cout << answer << "\n";
    }
}
