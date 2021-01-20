#include <fstream>
#include <string>
#include <iostream>
#include <math.h>
#include <algorithm>
#include <vector>
#include <stdlib.h>
#include <bitset>
using namespace std;
pair<int, int> arr[70000];
int counter = 0;
string answer;
void decToBinaryMod(int n)
{
    // array to store binary number
    int binaryNum[32];

    // counter for binary array
    int i = 0;
    while (n > 0) {

        // storing remainder in binary array
        binaryNum[i] = n % 2;
        n = n / 2;
        i++;
    }

    // printing binary array in reverse order
    for (int j = i - 1; j >= 0; j--)
        counter++;
}
void decToBinary(int n)
{
    // array to store binary number
    int binaryNum[32];

    // counter for binary array
    int i = 0;
    while (n > 0) {

        // storing remainder in binary array
        binaryNum[i] = n % 2;
        n = n / 2;
        i++;
    }

    // printing binary array in reverse order
    for (int j = i - 1; j >= 0; j--)
        cout << binaryNum[j] << "\n";
}
int n;
long long b;
int stateneeded = 0;
int main(){
    cin >> n >> b;
    for (int x = 0; x < 70000; x++){
        arr[x] = make_pair(0,0);
    }
    string cur = "";
    string ne = "";
    char temp;
    for (int x = 0; x < n; x++){
        cin >> temp;
        cur += temp;
        ne += temp;
    }
    bool repeat = true;
    int curn = 0;
    while (repeat && curn < b){
        for (int x = 0; x < n; x++){
            if (x == n - 1){
                if (cur[n - 1] == '1'){
                    if (ne[0] == '0'){
                        ne[0] = '1';
                    }
                    else{
                        ne[0] = '0';
                    }
                }
            }
            else{
                if (cur[x] == '1'){
                    if (ne[x + 1] == '1'){
                        ne[x + 1] = '0';
                    }
                    else{
                        ne[x + 1] = '1';
                    }
                }
            }
        }
        for (int x = 0; x < n; x++){
            cur[x] = ne[x];
        }
        curn++;
        int value = std::bitset<64>(cur).to_ullong();
        if (arr[value].first == 1){
            repeat = false;
            stateneeded = arr[value].second + (b - arr[value].second)%(curn - arr[value].second);
        }
        else{
            arr[value].first = 1;
            arr[value].second = curn;
        }
    }
    if (repeat){
        for (int x = 0; x < n; x++){
            cout << cur[x] << "\n";
        }
    }
    else{
        for (int x = 0; x < 70000; x++){
            if (arr[x].second == stateneeded){
                decToBinaryMod(x);
                for (int y = 0; y < n - counter; y++){
                    cout << "0" << "\n";
                }
                decToBinary(x);
            }
        }
    }




}
