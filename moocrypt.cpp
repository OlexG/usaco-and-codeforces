#include <fstream>
#include <string>
#include <iostream>
#include <math.h>
#include <algorithm>
#include <vector>
using namespace std;
int n, m;
string ciphers;
string alphabet;

char arr[50][50];
char arrc[50][50];
int dx[8] = {-1, 0, 1, 0, 1, 1, -1, -1};
int dy[8] = {0, -1, 0, 1, -1, 1, -1, 1};
int check(int x, int y, char one){
    int answer = 0;
    for (int z = 0; z < 8; z++){
        bool worked = true;
        int cx = x + dx[z];
        int cy = y + dy[z];
        if (cx >= 0 && cx < n && cy >= 0 && cy < m){
            if (arr[cx][cy] != one){
                worked = false;
            }
        }
        else{
            worked = false;
        }
        cx = cx + dx[z];
        cy = cy + dy[z];
        if (cx >= 0 && cx < n && cy >= 0 && cy < m){
            if (arr[cx][cy] != one){
                worked = false;
            }
        }
        else{
            worked = false;
        }
        if (worked){
            answer++;
        }
    }
    return answer;
}
int main(){
    cin >> n >> m;
    ciphers = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    for (int x = 0; x < n; x++){
        for (int y = 0; y < m; y++){
            cin >> arr[x][y];
        }
    }
    int answer = 0;
    int tempanswer = 0;
    for (int c = 0; c < 26; c++){
    for (int z = 0; z < 26; z++){
    if (alphabet[c] != alphabet[z] && alphabet[c] != 'M' && alphabet[z] != 'O'){
    tempanswer = 0;
    for (int x = 0; x < n; x++){
        for (int y = 0; y < m; y++){
            if (arr[x][y] == alphabet[c]){
                tempanswer += check(x, y, alphabet[z]);
            }
        }
    }
    answer = max(answer, tempanswer);
    }
    }
    }
    cout << answer;
}

