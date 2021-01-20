#include <fstream>
#include <string>
#include <iostream>
#include <math.h>
using namespace std;
#include <vector>
#include <utility>
int n, k, r;
int grid[100][100];
int used[100][100];
vector<pair<int, int>> cows;
vector<pair<int, int>> arr[10000];
void refill(){
    for(int x = 0; x < n; x++){
        for(int y = 0; y < n; y++){
            used[x][y] = 2;
        }
    }
}
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};
int total = 0;
void rec(int x, int y){
    if (used[x][y] == 2 && grid[x][y] == 1){
        total++;
        used[x][y] = 1;
         int nx, ny;
        for(int z = 0; z < 4; z++){
            nx = x + dx[z];
            ny = y + dy[z];
            bool cando = true;
            for (int c = 0; c < arr[x * 10 + y].size(); c++){
                if (nx == arr[x * 10 + y][c].first && ny == arr[x * 10 + y][c].second){
                    cando = false;
                }
            }
            if (cando && nx >= 0 && nx < n && ny >= 0 && ny < n && used[nx][ny] == 2){
                rec(nx, ny);
            }
        }
    }
    else{
        used[x][y] = 1;
        int nx, ny;
        for(int z = 0; z < 4; z++){
            nx = x + dx[z];
            ny = y + dy[z];
            bool cando = true;
            for (int c = 0; c < arr[x * 10 + y].size(); c++){
                if (nx == arr[x * 10 + y][c].first && ny == arr[x * 10 + y][c].second){
                    cando = false;
                }
            }
            if (cando && nx >= 0 && nx < n && ny >= 0 && ny < n && used[nx][ny] == 2){
                rec(nx, ny);
            }
        }
    }
}
int main() {
    ifstream in("countcross.in");
    ofstream out("countcross.out");
    int one, two, three, four;
    in >> n >> k >> r;
    for(int x = 0; x < n; x++){
        for(int y = 0; y < n; y++){
            grid[x][y] = 2;
        }
    }
    for (int x = 0; x < r; x ++){
        in >> one >> two >> three >> four;
        one--;
        two--;
        three--;
        four--;
        arr[one * 10 + two].push_back(make_pair(three, four));
        arr[three * 10 + four].push_back(make_pair(one, two));
    }
    for (int x = 0; x < k; x ++){
        in >> one >> two;
        one--;
        two--;
        cows.push_back(make_pair(one, two));
        grid[one][two] = 1;
    }
    int answer = 0;

    for (int x = 0; x < k; x++){
        refill();
        total = 0;
        used[cows[x].first][cows[x].second] = 1;
        rec(cows[x].first, cows[x].second);
        answer = answer + (k - total - 1);

    }
    out << answer/2;
}
