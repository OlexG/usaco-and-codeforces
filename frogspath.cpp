#include <fstream>
#include <string>
#include <iostream>
#include <math.h>
#include <algorithm>
#include <string>
using namespace std;
string road;
int total = 0;
void recurse(string left, string answer){
    if (left.length() == 0){
        total = total + 1;

    }
    else{
        if (left.length() == 1){
            recurse("", "");
        }
        else{
            if (left[0] == '#' && left[1] == '#'){
                total = -10000;
            }
            if (left[0] == '#'){
                left.erase(0, 1);
                left.erase(0, 1);

                recurse(left, answer);
            }
            else if (left[1] == '#'){
                left.erase(0, 1);
                recurse(left, answer);
            }
            else{
                string newstring = left;
                newstring.erase(0, 1);
                newstring.erase(0, 1);
                recurse(newstring, answer);
                left.erase(0, 1);
                recurse(left, "");

            }
        }
    }

}
int main(){
    cin >> road;
    road.erase(0, 1);
    recurse(road, "");
    if (total > 0){
        cout << total << "\n";
    }
    else{
        cout << 0 <<"\n";
    }
}
