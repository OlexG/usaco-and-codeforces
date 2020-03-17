#include <fstream>
#include <string>
#include <iostream>
/*
ID: alex.go2
TASK: ride
LANG: C++
*/
using namespace std;
int find(char character, char alphabet[26]) {
    for (int x = 0; x < 26; x ++){
        if (character == alphabet[x]){
            return x + 1;
        }
    }

}
int main() {
    ifstream in("ride.in");
    ofstream out("ride.out");
    string n;
    string b;
    in >> n;
    in >> b;
    char alphabet[26] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};
    int modn = 1;
    int modb = 1;
    for (int x = 0; x < n.size(); x ++){
        modn = modn * find(n[x], alphabet);
    }

    modn = modn % 47;
    for (int x = 0; x < b.size(); x ++){
        modb = modb * find(b[x], alphabet);
    }
    modb = modb % 47;
    if (modb == modn){
        out << "GO\n";
    }
    else{
        out << "STAY\n";
    }

}
