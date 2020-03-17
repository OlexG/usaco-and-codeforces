#include <fstream>
#include <string>
#include <iostream>
#include <math.h>
#include <algorithm>
#include <vector>
#include <queue>
#include <deque>
using namespace std;

vector<vector<int>> arr;
vector<char> letters;
int groups[100001] = {0};
void recurse(int num, int x, char letter){
    if (groups[x]){
        return;
    }

    groups[x] = num;
    for (int z = 0; z < arr[x].size(); z ++){

        if (letters[arr[x][z]] == letter){

            recurse(num, arr[x][z], letter);
        }
    }
}
int m;
string h;
int n;
int main(){
    ifstream in("milkvisits.in");
    ofstream out("milkvisits.out");


    in >> n;
    in >> m;
    in >> h;





    arr.resize(n);



    for (int x = 0; x < n - 1; x ++){
        letters.push_back(h[x]);
        int one;
        int two;
        in >> one;
        in >> two;

        arr[one - 1].push_back(two - 1);
        arr[two - 1].push_back(one - 1);

    }
    letters.push_back(h[n - 1]);

    int num = 1;

    for (int x = 0; x < n; x ++){

        if (groups[x] == 0){

            recurse(num, x, letters[x]);
            num += 1;
        }
    }

    int start = 0;
    int ending = 0;
    char letterc;
    for (int x = 0; x < m; x ++){
        in >> start;
        in >> ending;
        in >> letterc;

        if (groups[start - 1] != groups[ending - 1]){
            out << 1;

        }
        else{
            if(letterc == letters[start - 1]){
                out << 1;
            }
            else {

                out << 0;
            }

        }

    }





}






