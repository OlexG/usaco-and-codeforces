#include <fstream>
#include <string>
#include <iostream>
#include <math.h>
#include <algorithm>
#include <cstdlib>
using namespace std;
#include <vector>
struct point{
    int x;
    int y;
    double dist;
};
int w, r;
vector<point> all;
bool compare(point a, point b){
    if (a.dist == b.dist){
        if (a.x == b.x){
            return a.y < b.y;
        }
        else{
            return a.x > b.x;
        }
    }
    else{
        return a.dist < b.dist;
    }
}
int main(){
    cin >> w >> r;
    for (int x = r; x >= 1; x--){
        for (int y = 1; y < w + 1; y++){
            point temp;
            temp.x = x;
            temp.y = y;
            temp.dist = sqrt(pow((x - r), 2)  + pow((y - (w+1)/2), 2));
            all.push_back(temp);
        }
    }
    int arr[r][w];
    sort(all.begin(), all.end(), compare);
    for (int x = 1; x < all.size() + 1; x++){
          arr[all[x - 1].x - 1][all[x - 1].y - 1] = x;
    }
    for (int x = 0; x < r; x++){
        for (int y = 0; y < w; y++){
            cout << arr[x][y] << " ";
        }
        cout << "\n";
    }

}
