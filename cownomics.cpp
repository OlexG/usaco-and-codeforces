#include <fstream>
#include <string>
#include <iostream>
#include <math.h>
#include <algorithm>
#include <map>;
#include <vector>
using namespace std;
int n, m;
/*
3 8
AATCCCAT
GATTGCAA
GGTCGCAA
ACTCCCAG
ACTCGCAT
ACTTCCAT
*/
int main(){
    ifstream in("cownomics.in");
    ofstream out("cownomics.out");

    //g.insert(pair<string, int> ("abc", 1));
    //cout << g.count("abc");
    in >> n >> m;
    string arr[2*n];
    string em;
    for (int x = 0; x < 2 *n; x++){
        in >> em;
        arr[x] = em;
    }
    int answer = 0;
    bool add = true;
    map<string, int> g;
    for (int x = 0; x < m - 2; x ++){
        for (int y = x + 1; y < m -1; y++){
            for (int z = y + 1; z < m; z++){
                add = true;
                g.clear();
                for (int c = 0; c < n; c++){
                    em = "";
                    em += arr[c][x];
                    em += arr[c][y];
                    em += arr[c][z];

                    g.insert(pair<string, int> (em, 1));
                }
                for (int c = n; c < 2 * n; c++){
                    em = "";
                    em += arr[c][x];
                    em += arr[c][y];
                    em += arr[c][z];
                    if (g.count(em)){
                        add = false;
                        break;
                    }
                }
                if (add){
                    answer++;
                }
            }
        }
    }
    out << answer << "\n";
}
