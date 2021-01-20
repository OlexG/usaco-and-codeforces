#include <fstream>
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;

int n, m;
vector<int> arr[3001];
int used[3001];
int stillin[3001];
void clearofnum(int num){
    for (int x = 0; x < m; x++){
        for (int y = 0; y < arr[x].size(); y++){
            if (arr[x][y] == num){
                arr[x].erase(arr[x].begin() + y);
                break;
            }
        }
    }
}
void checkdfs(int cur){
    used[cur] = 2;
    for (int x = 0; x < arr[cur].size(); x++){
        if (used[arr[cur][x]] == 1 && stillin[arr[cur][x]] == 1){
            checkdfs(arr[cur][x]);
        }
    }
}
string isanswer(int len){
    int counter = 0;
    for (int x = 0; x < n; x++){
        if (used[x] == 2){
            counter++;
        }
    }
    if (counter == len){
        return "YES\n";
    }
    else{
        return "NO\n";
    }
}
void resetused(){
    for (int x = 0; x < n; x++){
        used[x] = 1;
    }
}
int main(){
    ifstream in("closing.in");
    ofstream out("closing.out");
    in >> n >> m;
    for (int x = 0; x < 3001; x++){
        used[x] = 1;
    }
    for (int x = 0; x < n; x++){
        stillin[x] = 1;
    }
    int one, two;
    for (int x = 0; x < m; x++){
        in >> one >> two;
        arr[one - 1].push_back(two - 1);
        arr[two - 1].push_back(one - 1);
    }
    int temp;
    for (int x = 0; x < n; x++){
        in >> temp;
        for (int y = 0; y < n; y++){
            if (stillin[y] == 1){
                checkdfs(y);
                out << isanswer(n - x);
                resetused();
                break;
            }
        }
        stillin[temp - 1] = 2;
        //clearofnum(temp - 1);
    }

}
