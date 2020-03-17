#include <fstream>
#include <string>
#include <iostream>
#include <sstream>

using namespace std;
void recurse (int arr[], int m, int n, string str){
    if (m == 0){
        cout <<str<< "\n";
    }
    else {
        for (int x = 0; x < n; x ++){
            string temp = to_string(arr[x]);
            string str1 = str + temp;

            recurse(arr, m - 1, n, str1);
        }
    }
}

int main() {
 int n;
 cin >> n;
 int arr[n];
 for (int x = 0; x < n; x ++){
    cin >> arr[x];
 }
 int m;
 cin >> m;
 recurse(arr, m, n, "");
}
