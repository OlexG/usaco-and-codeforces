#include <fstream>
#include <string>
#include <iostream>
#include <math.h>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>
using namespace std;
int n, m;
queue<pair<int, int>> b;
queue<pair<int ,int>> o;
int main(){
   cin >> n >> m;
   int one, two;
   int ttime = 0;
   for (int x = 0; x < n; x++){
        cin >> one >> two;
        ttime += two;
        b.push(make_pair(one, two));
   }
   for (int x = 0; x < m; x++){
        cin >> one >> two;
        o.push(make_pair(one, two));
   }
   int bd = 0;
   int od = 0;
   bool bwin = false;;
   if (b.front().first > o.front().first){
        bwin = true;
   }
   int answer = 0;
   while(ttime > 0){
        od += o.front().first;
        bd += b.front().first;
        o.front().second--;
        b.front().second--;
        if (o.front().second == 0){
            o.pop();
        }
        if (b.front().second == 0){
            b.pop();
        }
        if (od > bd && bwin){
            bwin = false;
            answer++;
        }
        else if (bd > od && bwin == false){
            answer++;
            bwin = true;
        }
        ttime--;
   }
   cout << answer;

}
