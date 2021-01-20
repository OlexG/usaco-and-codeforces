/*
10
1
-1
7 -1
*/
#include <fstream>
#include <string>
#include <iostream>
#include <math.h>
#include <algorithm>
#include <vector>
using namespace std;
int n, c;
vector<int> on;
vector<int> off;
char arr[100];
int used[4] = {1,1,1,1};
vector<string> answers;
void toggleall(){
    for (int x = 0; x < n; x++){
        if (arr[x] == '0'){
            arr[x] = '1';
        }
        else{
            arr[x] = '0';
        }
    }
}
void toggleeven(){
    for (int x = 0; x < n; x++){
        if (x % 2 == 1){
            if (arr[x] == '0'){
                arr[x] = '1';
            }
            else{
                arr[x] = '0';
            }
        }
    }
}
void toggleodd(){
    for (int x = 0; x < n; x++){
        if (x % 2 == 0){
            if (arr[x] == '0'){
                arr[x] = '1';
            }
            else{
                arr[x] = '0';
            }
        }
    }
}
void togglethree(){
    for (int x = 0; x < n; x++){
        if ((x) % 3 == 0){
            if (arr[x] == '0'){
                arr[x] = '1';
            }
            else{
                arr[x] = '0';
            }
        }
    }
}
void rec(int cur){
    if (cur > c){
        return;
    }
    if (cur == c){
        bool answer = true;
        for (int x = 0; x < on.size(); x++){
            if (arr[on[x] - 1] == '0'){
                answer = false;
                break;
            }
        }
        for (int x = 0; x < off.size(); x++){
            if (arr[off[x] - 1] == '1'){
                answer = false;
                break;
            }
        }

        if (answer){
            string temp;
            for (int x = 0; x < n; x++){
                temp += arr[x];
            }
            answers.push_back(temp);
        }
    }
    else{
        if (used[0] == 1){
            used[0] = 2;
            toggleall();
            rec(cur + 1);
            rec(cur + 2);
            toggleall();
            used[0] = 1;
        }
        if (used[1] == 1){
            used[1] = 2;
            toggleeven();
            rec(cur + 1);
            rec(cur + 2);
            toggleeven();
            used[1] = 1;
        }
        if (used[2] == 1){
            used[1] = 2;
            toggleodd();
            rec(cur + 1);
            rec(cur + 2);
            toggleodd();
            used[1] = 1;
        }
        if (used[3] == 1){
            used[3] = 2;
            togglethree();
            rec(cur + 1);
            rec(cur + 2);
            togglethree();
            used[3] = 1;
        }
    }

}
int main(){
    cin >> n >> c;
    int one;
    while (true){
        cin >> one;
        if (one == -1){
            break;
        }
        on.push_back(one);
    }
    while(true){
        cin >> one;
        if (one == -1){
            break;
        }
        off.push_back(one);
    }
    if (c > 4){
        if (c % 2 == 1){
            c = 3;
        }
        else{
            c = 4;
        }
    }

    for (int x = 0; x < 100; x++){
        arr[x] = '1';
    }

    rec(0);

    sort(answers.begin(), answers.end());
    answers.erase( unique( answers.begin(), answers.end() ), answers.end() );
    for (int x = 0; x < answers.size(); x++){
        cout << answers[x] << "\n";
    }
    if (answers.size() == 0){
        cout << "IMPOSSIBLE" << "\n";
    }

}
