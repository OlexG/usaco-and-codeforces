#include <fstream>
#include <string>
#include <iostream>
#include <math.h>
#include <algorithm>
#include <vector>
using namespace std;

int t;
int n;
int m;
pair<long long, long long> arr[100000];
int upperbound(int x){
    int l = 0;
    int t = m;
    while (l < t){
        int mid = (l + t)/2;
        if (x >= arr[mid].first){
            l = mid + 1;
        }
        else{
            t = mid;
        }
    }
    return l;
}
int main(){
    cin >> t;
    for (int i = 0; i < t; i++){
        cin >> n >> m;
        long long one, two;
        for (int x = 0; x < m; x++){
            cin >> one >> two;
            arr[x] = make_pair(one, two);
        }
        long long prefix[m];
        sort(arr, arr + m);
        prefix[m - 1] = arr[m - 1].first;
        for (int x = m - 2; x >= 0; x--){
            prefix[x] = arr[x].first + prefix[x + 1];
        }
        long long answer = 0;
        int newn = n;
        for (int x = 0; x < m; x++){
            newn = n;
            int index = upperbound(arr[x].second);
            if (m - index > n){
                answer = max(answer, prefix[m - n]);
            }
            else{
                long long curanswer;
                if (index == m){
                    curanswer  = 0;
                }
                else{
                    curanswer = prefix[index];
                }

                newn = newn - (m - index);

                if (newn > 0){
                    if (arr[x].first > arr[x].second){
                        curanswer = curanswer + newn * arr[x].second;
                    }
                    else{
                        curanswer += arr[x].first;
                        newn--;
                        curanswer = curanswer + newn * arr[x].second;
                    }

                }
                answer = max(answer, curanswer);
            }
        }
        cout << answer << "\n";
    }
}
