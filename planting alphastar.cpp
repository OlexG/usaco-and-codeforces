#include <fstream>
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;
int n;
struct point{
    int x1;
    int y1;
    int x2;
    int y2;
};
bool sorting(point a, point b){
    if (a.x1 == b.x1){
        return a.y2 <= b.y2;
    }
    else{
        return a.x1 < b.x1;
    }
}
bool sortingv(pair<int, int> a, pair<int, int> b){
    return a.first <= b.first;
}
int main(){
    cin >> n;
    point arr[n];
    int one, two, three, four;
    for (int x = 0; x < n; x++){
        cin >> one >> two >> three >> four;
        arr[x].x1 = one;
        arr[x].y1 = two;
        arr[x].x2 = three;
        arr[x].y2 = four;
    }
    sort(arr, arr + n, sorting);
    int answer = 0;
    vector<pair<int, int>> cury;
    int maxx = -10000;
    for (int x = 0; x < n; x++){
        if (arr[x].x2 > maxx){
            maxx = arr[x].x2;
        }
    }
    for (int i = arr[0].x1; i < maxx; i++){
        int curadd = 0;
        int prevtopy = -10001;
        cury.clear();
        for (int x = 0; x < n; x++){
            if (i >= arr[x].x1 && i < arr[x].x2){
                cury.push_back(make_pair(arr[x].y2, arr[x].y1));
            }
        }
        sort(cury.begin(), cury.end(), sortingv);
        for (int x = 0; x < cury.size(); x++){
            if (cury[x].second > prevtopy){
                if (cury[x].first < prevtopy){
                    curadd = curadd + cury[x].second - prevtopy;
                }
                else{
                    curadd = curadd + cury[x].second - cury[x].first;
                }
                prevtopy = cury[x].second;
            }
        }
        answer += curadd;
    }
    cout << answer;
}
