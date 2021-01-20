#include <fstream>
#include <string>
#include <iostream>
#include <math.h>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>
using namespace std;
int n, k;
map<int, int> pairs;
vector<int> arr;
vector<int> cur;
int main(){
    cin >> n >> k;
    int one, two;
    for (int x = 0; x < k; x++){
        cin >> one >> two;
        pairs.insert(pair<int, int>(one, two));
        pairs.insert(pair<int, int> (two, one));
        arr.push_back(one);
        arr.push_back(two);
    }
    int answer = 1;
    sort(arr.begin(), arr.end());
    for (int x = 0; x < 2 * k; x++){
        for (int y = 0; y < cur.size(); y++){
            if (pairs[cur[y]] == arr[x]){
                answer++;
                cur.clear();
                break;
            }
        }
        cur.push_back(arr[x]);

    }
    cout << answer;
}
