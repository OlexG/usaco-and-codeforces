#include <fstream>
#include <string>
#include <iostream>
#include <math.h>
#include <algorithm>
#include <vector>
#include <set>
using namespace std;
int t;
int n;
int main(){
    cin >> t;
    for (int m = 0; m < t; m++){
        cin >> n;
        string arr;
        cin >> arr;
        int answers[n];
        multiset<pair<int,int>> mp;

        int totalsets = 0;
        int zeroes = 0;
        int ones = 0;
        //mp.insert(make_pair(0,0));
        //cout << (*(mp.rbegin())).first;
        for (int x = 0; x < n; x++){
            if (arr[x] == '0'){
                if (mp.size() > 0){
                    if ((*(mp.rbegin())).first == 1){
                        mp.insert(make_pair(0, (*(mp.rbegin())).second));
                        answers[x] = (*(mp.rbegin())).second;
                        mp.erase(prev(mp.end()));
                    }
                    else{
                        totalsets++;
                        mp.insert(make_pair(0, totalsets));
                        answers[x] = totalsets;
                    }
                }
                else{
                    totalsets++;
                    mp.insert(make_pair(0, totalsets));
                    answers[x] = totalsets;
                }
            }
            else{
                if (mp.size() > 0){
                    if ((*(mp.begin())).first == 0){
                        mp.insert(make_pair(1, (*(mp.begin())).second));
                        answers[x] = (*(mp.begin())).second;
                        auto it = mp.begin();                                            //    ^
                        mp.erase(it);
                    }
                    else{
                        totalsets++;
                        mp.insert(make_pair(1, totalsets));
                        answers[x] = totalsets;
                    }
                }
                else{
                    totalsets++;
                    mp.insert(make_pair(1, totalsets));
                    answers[x] = totalsets;
                }
            }
            /*for (auto rit = mp.begin(); rit != mp.end(); rit++){
                cout << (*rit).first << " " << (*rit).second << "    ";
            }
            cout << "\n";*/

        }
        cout << mp.size() << "\n";
        for (int x = 0; x < n; x++){
            cout << answers[x] << " ";
        }
        cout << "\n";
    }
}
