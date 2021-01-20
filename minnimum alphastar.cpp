#include <fstream>
#include <string>
#include <iostream>
#include <math.h>
#include <algorithm>
#include <vector>
using namespace std;
string pass;
vector<string> nums;
int n, m;
bool answer = true;
int rec(string cur){
    if (cur.size() == pass.size() && answer){
        cout << cur << "\n";
        answer = false;
        return 0;
    }
    else if (answer){
        for (int x = 0; x < m; x++){
            if (cur.size() + nums[x].size() <= pass.size()){
                bool worked = true;
                for (int y = cur.size(); y < nums[x].size() + cur.size(); y++){
                    if (pass[y] != '?' && pass[y] != nums[x][y - cur.size()]){
                        worked = false;
                    }
                }
                if (worked){
                    rec(cur + nums[x]);
                }
            }
        }
    }
}
int main(){
    cin >> n >> m;
    cin >> pass;
    string temp;
    for (int x = 0; x < m; x++){
        cin >> temp;
        nums.push_back(temp);
    }
    sort(nums.begin(), nums.end());
    rec("");
    if (answer){
        cout << "NO SOLUTION";
    }
}
