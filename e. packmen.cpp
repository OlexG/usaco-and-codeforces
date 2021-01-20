#include <fstream>
#include <string>
#include <iostream>
#include <math.h>
#include <algorithm>
#include<bits/stdc++.h>
#include <vector>
using namespace std;

int n;
string s;
bool ok(int dist){
    bool hpack = false;
    bool hasteric = false;
    int curpackmen = -1;
    vector<int> asterics;
    for (int x = 0; x < n; x++){
        /*cout << "Current packman position is: " << curpackmen << " and current position is " << x << "\n";
        cout << "Current asteroids being eaten |\n";
        for (int y = 0; y < asterics.size(); y++){
            cout << asterics[y] << " ";
        }
        cout << "\n";*/
        if (s[x] == '*'){
            if (asterics.size() == 0 || curpackmen == -1){
                asterics.push_back(x);
                if (curpackmen != -1){
                    if (asterics[0] - curpackmen > dist){
                        curpackmen = -1;
                    }
                }
            }
            else{
                asterics.push_back(x);
                if (asterics[0] > curpackmen){
                    if (abs(curpackmen - asterics[asterics.size() - 1]) > dist){
                        asterics.clear();
                        asterics.push_back(x);
                        curpackmen = -1;
                    }
                }
                else{
                    if (asterics[asterics.size() - 1] < curpackmen){
                        if (abs(curpackmen - asterics[0]) > dist){
                            return false;
                        }
                    }
                    else{
                        int mindist = 0;
                        if (abs(curpackmen - asterics[0]) <= abs(asterics[asterics.size() - 1] - curpackmen)){
                            mindist = abs(curpackmen - asterics[0]) * 2 + abs(asterics[asterics.size() - 1] - curpackmen);
                        }
                        else{
                            mindist = abs(asterics[asterics.size() - 1] - curpackmen) * 2 + abs(curpackmen - asterics[0]);
                        }
                        if (mindist > dist){
                            if (asterics.size() > 2){
                                asterics.clear();
                                asterics.push_back(x);
                                curpackmen = -1;
                            }
                            else{
                                if (curpackmen - asterics[0] > dist){
                                    return false;
                                }
                                else{
                                    asterics.clear();
                                    asterics.push_back(x);
                                    curpackmen = -1;
                                }
                            }
                        }
                    }
                }
            }
        }
        if (s[x] == 'P'){
            if (curpackmen != -1){
                asterics.clear();
                curpackmen = x;
            }
            else{
                curpackmen = x;
                if (asterics.size() > 0){
                    if (abs(curpackmen - asterics[0]) > dist){
                        return false;
                    }
                }
            }
        }
    }
    if (asterics.size() > 0){
        if (curpackmen == -1){
            return false;
        }
        if (asterics[0] > curpackmen){
            if (abs(curpackmen - asterics[asterics.size() - 1]) > dist){
                return false;
            }
        }
        else{
            if (asterics[asterics.size() - 1] < curpackmen){
                if (abs(curpackmen - asterics[0]) > dist){
                    return false;
                }
            }
            else{
                int mindist = 0;
                if (abs(curpackmen - asterics[0]) <= abs(asterics[asterics.size() - 1] - curpackmen)){
                    mindist = abs(curpackmen - asterics[0]) * 2 + abs(asterics[asterics.size() - 1] - curpackmen);
                }
                else{
                    mindist = abs(asterics[asterics.size() - 1] - curpackmen) * 2 + abs(curpackmen - asterics[0]);
                }
                if (mindist > dist){
                    cout << mindist << "\n";
                    return false;
                }
            }
        }
    }
    return true;
}
int main(){
    cin >> n;
    cin >> s;
    int mi = 0;
    int ma = 1000000;
    //cout << ok(10) << "\n";
    while(mi < ma){
        int cur = (mi + ma)/2;
        //cout << cur << " " << ok(cur) << "\n";
        if (ok(cur)){
            ma = cur;
        }
        else{
            mi = cur + 1;
        }
    }
    cout << ma << "\n";
}
