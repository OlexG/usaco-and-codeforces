#include <fstream>
#include <string>
#include <iostream>
#include <math.h>
#include <algorithm>
#include<bits/stdc++.h>
#include <vector>
using namespace std;

string word;
char arr[5][5];
char arrcopy[5][5];
int total = 0;
bool done = false;
void recurse(string word, int x, int y, int counter, int prevx, int prevy, vector<array<int, 2>> used){
    if (!done){
        if (counter == word.size()){

            total = total + 1;
            done = true;

        }
        else{

            for (int z = -1; z < 2; z ++){
                for (int c = -1; c < 2; c ++){
                    if (x + z != x || y + c !=y ){
                        if (x + z < 5 && x + z >=0 && y + c < 5 && y + c >= 0){
                            if (x + z != x - prevx || y + c != y - prevy){

                                if (word[counter] == arr[x + z][y + c]){

                                    bool add = true;
                                    for (int v = 0; v < used.size(); v ++){
                                        if (used[v][0] == x && used[v][1] == y){
                                            add = false;
                                        }
                                    }
                                    if (add){

                                        array<int , 2> p = {x , y};
                                        used.push_back(p);
                                        recurse(word, x + z , y + c, counter + 1, z, c, used);
                                        used.pop_back();
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
}
int main(){
    for (int x = 0; x < 5; x++){
        for (int y = 0; y < 5; y ++){
            cin >> arr[x][y];
        }
    }
    for (int x = 0; x < 24830; x ++){
        cin >> word;
        done = false;
        vector<array<int , 2>> used;
        for (int x = 0; x < 5; x++){
            for (int y = 0; y < 5; y ++){
                if (arr[x][y] == word[0]){
                    recurse(word, x , y, 1, 0, 0, used);
                }
            }
        }
    }

    cout << total << "\n";

}
