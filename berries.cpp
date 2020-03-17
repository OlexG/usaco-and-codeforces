#include <fstream>
#include <string>
#include <iostream>
#include <math.h>
#include <algorithm>
#include <bits/stdc++.h>
using namespace std;



vector<int> trees;
int n;
int k;

int calc(int b, vector<int> trees){
    int counter = 0;
    int total = 0;
    bool normal = true;
    int x = 0;
    if (normal){
        while(x < k ){

                if (trees[counter] >= b){
                    trees[counter] -= b;
                    if (x >= k/2){
                        total = total + b;

                    }
                    x =x + 1;
                }
                else{
                    if (counter + 1 == n){

                        if (x >= k/2){
                            total = total + trees[counter];
                        }
                        normal = false;
                        trees[counter] = 0;
                        x = x + 1;
                        break;
                    }
                    else{
                        if (trees[counter + 1] >= b){
                            counter = counter + 1;
                        }
                        else{
                            normal = false;
                            break;
                        }
                    }
                }
            }
    }
    if (!normal) {

        sort(trees.begin(), trees.end(), greater <int>());
        counter = 0;
        while(x < k && counter < n){
            if (x >= k/2){
            total = total + trees[counter];
            }
            x += 1;
            counter += 1;

        }

    }
    return total;
}
int main(){
    ifstream in("berries.in");
    ofstream out("berries.out");

    in >> n;
    in >> k;
    int tree;
    for (int x = 0; x < n; x ++){
        in >> tree;
        trees.push_back(tree);

    }

    int answer = 0;
    int total = 0;
    sort(trees.begin(), trees.end(), greater <int>());
    for (int x = trees[0]; x >= 1; x--){
        total = calc(x, trees);

        if (total > answer){
            answer = total;

        }
    }
    out << answer << "\n";


}
