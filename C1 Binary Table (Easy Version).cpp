#include <fstream>
#include <string>
#include <iostream>
#include <math.h>
#include <algorithm>
#include<bits/stdc++.h>
#include <vector>
using namespace std;
int t;
int n, m;
char arr[102][102];
int main(){
    cin >> t;
    for (int z = 0; z < t; z++){
        cin >> n >> m;

        for (int x = 0; x < n; x++){
            string s;
            cin >> s;
            for (int y = 0; y < m; y++){
                arr[x][y] = s[y];
            }
        }
        vector<pair<int, int>> op1;
        vector<pair<int, int>> op2;
        vector<pair<int, int>> op3;
        for (int x = 0; x < n - 1; x++){
            for (int y = 0; y < m - 1; y++){
                if (y != m - 2 || x != n - 2){
                    if (y != m - 2){
                        if (arr[x][y] == '1' && arr[x + 1][y] == '1'){
                            arr[x][y] = '0';
                            arr[x + 1][y] = '0';
                            arr[x][y + 1] = (arr[x][y + 1] == '0'?'1':'0');
                            op1.push_back(make_pair(x + 1, y + 1));
                            op2.push_back(make_pair(x + 2, y + 1));
                            op3.push_back(make_pair(x + 1, y + 2));
                        }
                        else if (arr[x][y] == '1' && arr[x + 1][y] == '0'){
                            arr[x][y] = '0';
                            arr[x][y + 1] = (arr[x][y + 1] == '0'?'1':'0');
                            arr[x + 1][y + 1] = (arr[x + 1][y + 1] == '0'?'1':'0');
                            op1.push_back(make_pair(x + 1, y + 1));
                            op2.push_back(make_pair(x + 1, y + 2));
                            op3.push_back(make_pair(x + 2, y + 2));
                        }
                        else if (arr[x][y] == '0' && arr[x + 1][y] == '1'){
                            arr[x + 1][y] = '0';
                            arr[x][y + 1] = (arr[x][y + 1] == '0'?'1':'0');
                            arr[x + 1][y + 1] = (arr[x + 1][y + 1] == '0'?'1':'0');
                            op1.push_back(make_pair(x + 2, y + 1));
                            op2.push_back(make_pair(x + 1, y + 2));
                            op3.push_back(make_pair(x + 2, y + 2));
                        }
                    }
                    else{
                        if (arr[x][y] == '1' && arr[x][y + 1] == '1'){
                            arr[x][y] = '0';
                            arr[x][y + 1] = '0';
                            arr[x + 1][y + 1] = (arr[x + 1][y + 1] == '0'?'1':'0');
                            op1.push_back(make_pair(x + 1, y + 1));
                            op2.push_back(make_pair(x + 1, y + 2));
                            op3.push_back(make_pair(x + 2, y + 2));
                        }
                        else if (arr[x][y] == '0' && arr[x][y + 1] == '1'){
                            arr[x][y + 1] = '0';
                            arr[x + 1][y + 1] = (arr[x + 1][y + 1] == '0'?'1':'0');
                            arr[x + 1][y] = (arr[x + 1][y] == '0'?'1':'0');
                            op1.push_back(make_pair(x + 1, y + 2));
                            op2.push_back(make_pair(x + 2, y + 2));
                            op3.push_back(make_pair(x + 2, y + 1));
                        }
                        else if (arr[x][y] == '1' && arr[x][y + 1] == '0'){
                            arr[x][y] = '0';
                            arr[x + 1][y + 1] = (arr[x + 1][y + 1] == '0'?'1':'0');
                            arr[x + 1][y] = (arr[x + 1][y] == '0'?'1':'0');
                            op1.push_back(make_pair(x + 1, y + 1));
                            op2.push_back(make_pair(x + 2, y + 2));
                            op3.push_back(make_pair(x + 2, y + 1));
                        }
                    }
                }
                else if (y == m - 2 && x == n - 2){
                    int numo = 0;
                    vector<pair<int, int>> ones;
                    vector<pair<int, int>> zero;
                    for (int c = x; c <= x + 1; c++){
                        for (int b = y; b <= y + 1; b++){
                            if (arr[c][b] == '1'){
                                numo++;
                                ones.push_back(make_pair(c + 1, b + 1));
                            }
                            else{
                                zero.push_back(make_pair(c + 1, b + 1));
                            }
                        }
                    }
                    if (numo == 1){
                        op1.push_back(ones[0]);
                        op2.push_back(zero[0]);
                        op3.push_back(zero[1]);

                        op1.push_back(zero[0]);
                        op2.push_back(ones[0]);
                        op3.push_back(zero[2]);

                        op1.push_back(zero[1]);
                        op2.push_back(ones[0]);
                        op3.push_back(zero[2]);
                    }
                    if (numo == 2){
                        op1.push_back(ones[1]);
                        op2.push_back(zero[0]);
                        op3.push_back(zero[1]);

                        op1.push_back(ones[0]);
                        op2.push_back(zero[0]);
                        op3.push_back(zero[1]);
                    }
                    if (numo == 3){
                        op1.push_back(ones[0]);
                        op2.push_back(ones[1]);
                        op3.push_back(ones[2]);
                    }
                    if (numo == 4){
                        op1.push_back(ones[0]);
                        op2.push_back(ones[1]);
                        op3.push_back(ones[2]);

                        op1.push_back(ones[3]);
                        op2.push_back(ones[0]);
                        op3.push_back(ones[1]);

                        op1.push_back(ones[0]);
                        op2.push_back(ones[2]);
                        op3.push_back(ones[3]);

                        op1.push_back(ones[1]);
                        op2.push_back(ones[2]);
                        op3.push_back(ones[3]);

                    }
                }
            }

        }
        cout << op1.size() << "\n";
        for (int x = 0; x < op1.size(); x++){
            cout << op1[x].first << " " << op1[x].second << " " << op2[x].first << " " << op2[x].second << " " << op3[x].first << " " << op3[x].second << "\n";
        }

    }
}

