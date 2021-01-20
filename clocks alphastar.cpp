#include <fstream>
#include <string>
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
vector<vector<int>> arr {
{0, 1, 3, 4},
{0, 1, 2},
{1, 2, 4, 5},
{0, 3, 6},
{1, 3, 4, 5, 7},
{2, 5, 8},
{3, 4, 6, 7},
{6, 7, 8},
{4, 5, 7, 8}
};
int used[4][4][4][4][4][4][4][4][4];
queue<vector<int>> moves;
queue<vector<int>> clocks;
int main(){
    int temp;
    vector<int> tempclocks;
    for (int x = 0; x < 9; x++){
        cin >> temp;
        temp = temp/3;
        tempclocks.push_back(temp);
    }
    vector<int> tempvec;
    moves.push(tempvec);
    clocks.push(tempclocks);
    for (int q = 0; q < 4; q++){
        for (int w = 0; w < 4; w++){
            for (int e = 0; e < 4; e++){
                for (int r = 0; r < 4; r++){
                    for (int t = 0; t < 4; t++){
                        for (int y = 0; y < 4; y++){
                            for (int u = 0; u < 4; u++){
                                for (int i = 0; i < 4; i++){
                                    for (int o = 0; o < 4; o++){
                                        used[q][w][e][r][t][y][u][i][o] = 1;
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    while(moves.empty() == false){
        bool done = true;
        for (int x = 0; x < 9; x++){
            if (clocks.front()[x] != 4){
                done = false;
            }
        }
        if (done){
            for (int x = 0; x < moves.front().size(); x++){
                cout << moves.front()[x] << " ";
            }
            break;
        }
        else{
            for (int x = 0; x < 9; x++){
                vector<int> curmoves = moves.front();
                vector<int> curclock = clocks.front();
                curmoves.push_back(x + 1);
                for (int y = 0; y < arr[x].size(); y++){
                    curclock[arr[x][y]] = curclock[arr[x][y]] + 1;
                    if (curclock[arr[x][y]] == 5){
                        curclock[arr[x][y]] = 1;
                    }
                }
                if (used[curclock[0] - 1][curclock[1] - 1][curclock[2] - 1][curclock[3] - 1][curclock[4] - 1][curclock[5] - 1][curclock[6] - 1][curclock[7] - 1][curclock[8] - 1] == 1){
                    moves.push(curmoves);
                    clocks.push(curclock);
                    used[curclock[0] - 1][curclock[1] - 1][curclock[2] - 1][curclock[3] - 1][curclock[4] - 1][curclock[5] - 1][curclock[6] - 1][curclock[7] - 1][curclock[8] - 1] = 2;
                }
            }
        }
        moves.pop();
        clocks.pop();
    }

}
