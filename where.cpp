#include <fstream>
#include <string>
#include <iostream>
#include <math.h>
using namespace std;
#include <vector>
int n;
char arr[20][20];
int used[20][20];
vector< vector<int>> oused;
int total1 = 0;
int total2 = 0;
int total3 = 0;
int total4 = 0;
int answer = 0;
void refill(){
    for (int x = 0; x < n; x++){
        for (int y = 0; y < n; y++){
            used[x][y] = 2;
        }
    }
}
int dx[4] = {0, -1, 0, 1};
int dy[4] = {-1, 0, 1, 0};
void rec(int x1, int x2, int y1, int y2, int curx, int cury, char needed){
    if (used[curx][cury] == 2){
        total1 += 1;
        used[curx][cury] = 1;
        for (int x = 0; x < 4; x ++){
            int dcurx = curx + dx[x];
            int dcury = cury + dy[x];
            if (dcurx >= x1 && dcurx <= x2 && dcury >= y1 && dcury <= y2 && arr[dcurx][dcury] == needed){
                rec(x1, x2, y1, y2, dcurx, dcury, needed);
            }
        }
    }
};
void rec1(int x1, int x2, int y1, int y2, int curx, int cury, char needed){
    if (used[curx][cury] == 2){
        total2 += 1;
        used[curx][cury] = 1;
        for (int x = 0; x < 4; x ++){
            int dcurx = curx + dx[x];
            int dcury = cury + dy[x];
            if (dcurx >= x1 && dcurx <= x2 && dcury >= y1 && dcury <= y2 && arr[dcurx][dcury] == needed){
                rec1(x1, x2, y1, y2, dcurx, dcury, needed);
            }
        }
    }
};
void countup(char fcolor, char scolor, int x1, int x2, int y1, int y2){
    for (int x = x1; x <= x2; x++){
        for (int y = y1; y <= y2; y++){
            if (arr[x][y] == fcolor){
                total3++;
            }
            if (arr[x][y] == scolor){
                total4++;
            }
        }
    }
}
void filloused(int x1, int x2, int y1, int y2, int answer){
    for (int x = x1; x <= x2; x++){
        for (int y = y1; y <= y2; y++){
            oused[x][y] = answer;
        }
    }
}
bool checkused(int x1, int x2, int y1, int y2){
    bool answer = true;
    for (int x = 0; x < oused.size(); x++){
        if (x1 >= oused[x][0] && x2 <= oused[x][1] && y1 >= oused[x][2] && y2 <= oused[x][3]){
            answer = false;
        }
    }
    return answer;
}
int main(){
    ifstream in("where.in");
    ofstream out("where.out");
    in >> n;
    string em;
    for (int x = 0; x < n; x ++){
        in >> em;
        for (int y = 0; y < n; y++){
            arr[x][y] = em[y];
        }
    }
    refill();
    for (int x1 = 0; x1 < n; x1++){
        for (int y1 = 0; y1 < n; y1++){
            for (int x2 = n - 1; x2 >= x1; x2--){
                for (int y2 = n-1; y2 >=y1; y2--){
                    bool possible = true;
                    char fcolor = '1';
                    char scolor = '1';
                    for (int b = x1; b <= x2; b++){
                        for (int m = y1; m <= y2; m++){
                            if (fcolor == '1' && scolor == '1'){
                                fcolor = arr[b][m];
                            }
                            else if (scolor == '1' && arr[b][m] != fcolor){
                                scolor = arr[b][m];
                            }
                            else if (arr[b][m] != scolor && arr[b][m] != fcolor){
                                possible = false;
                            }
                        }
                    }
                    if (fcolor == '1' || scolor == '1'){
                        possible = false;
                    }
                    if (possible && checkused(x1, x2, y1, y2)){
                        bool isanswer = false;
                        total1 = 0;
                        total2 = 0;
                        total3 = 0;
                        total4 = 0;
                        refill();
                        bool done = false;
                        for (int b = x1; b <= x2; b++){
                            for (int m = y1; m <= y2; m++){
                                if (arr[b][m] == fcolor){
                                    rec(x1, x2, y1, y2, b , m, fcolor);
                                    done = true;
                                    break;
                                }
                            }
                            if (done){
                                break;
                            }
                        }
                        refill();
                        done = false;
                        for (int b = x1; b <= x2; b++){
                            for (int m = y1; m <= y2; m++){
                                if (arr[b][m] == scolor){
                                    rec1(x1, x2, y1, y2, b , m, scolor);
                                    done = true;
                                    break;
                                }
                            }
                            if (done){
                                break;
                            }
                        }
                        countup(fcolor, scolor, x1, x2, y1, y2);
                        if (total1 + total2 < total3 + total4){
                            if (total1 == total3 || total2 == total4){
                                isanswer = true;
                            }
                        }
                        if (isanswer){
                            cout << total2 << " ";
                            cout << x1 << " " << x2 << " " << y1 << " " << y2 << "\n";
                            answer += 1;
                            vector<int> em;
                            em.push_back(x1);
                            em.push_back(x2);
                            em.push_back(y1);
                            em.push_back(y2);
                            oused.push_back(em);
                        }
                    }
                }
            }
        }
    }
    out << answer << "\n";


}
