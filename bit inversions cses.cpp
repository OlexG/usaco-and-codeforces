#include <fstream>
#include <string>
#include <iostream>
#include <math.h>
#include <algorithm>
#include<bits/stdc++.h>
#include <vector>
using namespace std;

string s;
int n;
int main(){
    cin >> s;
    cin >> n;
    set<pair<int, int>> cur;
    multiset<int> best;
    vector<int> operations;
    int temp;
    for (int x = 0; x < n; x++){
        cin >> temp;
        operations.push_back(temp);
    }


    int counter = 0;
    for (int x = 1; x < s.size(); x++){
        if (s[x] != s[x - 1]){
            cur.insert(make_pair(counter, x - counter));
            counter = x;
        }
        if (x == s.size() - 1){
            cur.insert(make_pair(counter, x - counter + 1));
        }
    }
    for (auto i : cur){
        best.insert(i.second);
    }
/*
001011
1
3
*/
    /*for (auto i : cur){
        cout << i.first << " " << i.second << "\n";
    }
    cout << "\n";*/
    for (int x = 0; x < n; x++){
        int query = operations[x] - 1;
        auto which = *(--cur.upper_bound(make_pair(query, 1000000)));
        auto curiter = prev(cur.upper_bound(make_pair(query, 1000000)));
        if (which.second == 1){
            if (curiter == cur.begin()){
                auto after =  next(curiter,1);
                auto afterelem = *after;
                int newsize = afterelem.second + 1;
                best.erase(best.find(afterelem.second));
                best.erase(best.find(1));
                best.insert(newsize);
                cur.erase(curiter, next(after, 1));
                cur.insert(make_pair(0, newsize));
                cout << *--best.end() << " ";
                continue;
            }
            if (curiter == --cur.end()){
                auto before = prev(curiter);
                auto beforeelem = *before;
                int newsize = beforeelem.second + 1;
                int newpos = beforeelem.first;
                best.erase(best.find(beforeelem.second));
                best.erase(best.find(1));
                cur.erase(before, next(curiter, 1));
                cur.insert(make_pair(newpos, newsize));
                best.insert(newsize);
                cout << *--best.end() << " ";
                continue;
            }
            auto this_one = curiter;
            auto before = prev(curiter);
            auto after =  next(curiter,1);


            auto beforeelem = *before;
            auto afterelem = *after;
            int newsize = beforeelem.second + afterelem.second + 1;
            int newpos = beforeelem.first;

            best.erase(best.find(afterelem.second));
            best.erase(best.find(beforeelem.second));
            best.erase(best.find(1));
            best.insert(newsize);
            cur.erase(before, next(after, 1));
            cur.insert(make_pair(newpos, newsize));
        }
        else{
            if (query == which.first){
                if (curiter == cur.begin()){
                    auto this_one = curiter;
                    auto this_element = *this_one;
                    best.erase(best.find(this_element.second));
                    cur.erase(cur.begin());
                    cur.insert(make_pair(0, 1));
                    cur.insert(make_pair(1, this_element.second - 1));
                    best.insert(1);
                    best.insert(this_element.second - 1);
                }
                else{
                    auto before = prev(curiter);
                    auto beforeelem = *before;
                    auto this_one = curiter;
                    auto this_element = *this_one;


                    best.erase(best.find(beforeelem.second));
                    best.erase(best.find(this_element.second));

                    beforeelem.second += 1;
                    this_element.first += 1;
                    this_element.second -= 1;
                    cur.erase(before, next(this_one, 1));

                    cur.insert(beforeelem);
                    cur.insert(this_element);
                    best.insert(beforeelem.second);
                    best.insert(this_element.second);
                }
            }
            else if (query == which.first + which.second - 1){
                if (curiter == --cur.end()){
                    auto this_one = curiter;
                    auto this_element = *this_one;
                    best.erase(best.find(this_element.second));
                    cur.erase(--cur.end());
                    cur.insert(make_pair(query, 1));
                    cur.insert(make_pair(this_element.first, this_element.second - 1));
                    best.insert(1);
                    best.insert(this_element.second - 1);
                }
                else{
                    auto after = next(curiter,1);
                    auto afterelem = *after;
                    auto this_one = curiter;
                    auto this_element = *this_one;

                    best.erase(best.find(afterelem.second));
                    best.erase(best.find(this_element.second));

                    afterelem.second += 1;
                    afterelem.first -= 1;
                    this_element.second -= 1;
                    cur.erase(this_one, next(after, 1));

                    cur.insert(afterelem);
                    cur.insert(this_element);
                    best.insert(afterelem.second);
                    best.insert(this_element.second);
                }
            }
            else{
                auto this_one = curiter;
                auto this_element = *this_one;
                best.erase(best.find(this_element.second));

                auto first_element = make_pair(this_element.first, query - this_element.first);
                auto second_element = make_pair(query, 1);
                auto third_element = make_pair(query + 1, this_element.first + this_element.second - query - 1);
                cur.erase(this_one);
                cur.insert(first_element);
                cur.insert(second_element);
                cur.insert(third_element);

                best.insert(first_element.second);
                best.insert(second_element.second);
                best.insert(third_element.second);

            }
        }
        /*for (auto i : cur){
            cout << i.first << " " << i.second << "\n";
        }
        cout << "\n";*/
     cout << *--best.end() << " ";

    }
    cout << "\n";
}
