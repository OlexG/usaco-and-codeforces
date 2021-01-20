#include <fstream>
#include <string>
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;
int n;
vector<pair<long long , long long>> xy;
pair<long long, long long> mapy[20001];
long long prevy[20001];

long long offset = 10000;
bool csort(pair<long long , long long> a, pair<long long , long long> b){
    if (a.second == b.second){
        return a.first < b.first;
    }
    else{
        return a.second > b.second;
    }
}
int main(){
    ifstream in("triangles.in");
    ofstream out("triangles.out");
    in >> n;
    long long one, two;
    for (int x = 0; x < n; x++){
        in >> one;
        in >> two;
        xy.push_back(make_pair(one + offset, two + offset));
    }
    sort(xy.begin(), xy.end(), csort);
    /*for (int x = 0; x < n; x++){
        cout << xy[x].first << " " << xy[x].second << "\n";
    }*/
    for (int x = 0; x < 20001; x++){
        mapy[x] = make_pair(0,-1);
        prevy[x] = -1;
    }
    long long lasty = -1;
    long long answer = 0;
    for (int x = 0; x < n; x++){
        if (xy[x].second != lasty){

            vector<long long> fmapx;
            int counter = x;

            while(counter < n){
                counter++;
                if (xy[counter].second != xy[x].second){
                    break;
                }
            }
            for (int y = x; y < counter; y++){
                mapy[xy[y].first].second += 1;
                if (prevy[xy[y].first] == -1){
                    prevy[xy[y].first] = xy[y].second;
                }
                else{
                    mapy[xy[y].first].first += (mapy[xy[y].first].second * (prevy[xy[y].first] - xy[y].second));
                    mapy[xy[y].first].first %= 1000000007;
                    prevy[xy[y].first] = xy[y].second;
                }
            }


            fmapx.push_back(0);
            for (int y = x + 1; y < counter; y++){
                fmapx.push_back(((xy[y].first - xy[y - 1].first) * (y - x)  + fmapx[fmapx.size() - 1]));
                fmapx[fmapx.size() - 1] %= 1000000007;
            }
            long long bmapx[fmapx.size()];
            bmapx[fmapx.size() - 1] = 0;
            for (int y = counter - 2; y >= x; y--){
                bmapx[y - x] = (bmapx[y + 1 - x] + (xy[y + 1].first - xy[y].first) * (counter - y - 1));
                bmapx[y - x] %= 1000000007;
            }
            /*for (int x = 0; x < fmapx.size(); x++){
                cout << bmapx[x] << " ";
            }
            cout << "\n";*/
            if (counter - 1 > x){
                for (int y = x; y < counter; y++){
                    answer = answer + ((bmapx[y - x] + fmapx[y - x]) * mapy[xy[y].first].first) % 1000000007;
                    //cout << answer << " ";
                    answer = answer % 1000000007;
                }
            }

            lasty = xy[x].second;
        }
    }
    for (int x = 0; x < 20001; x++){
        mapy[x] = make_pair(0,-1);
        prevy[x] = -1;
    }
    lasty = -1;
    for (int x = 0; x < n; x++){
        xy[x].second = 10000 + (10000 - xy[x].second);
    }
    sort(xy.begin(), xy.end(), csort);
    for (int x = 0; x < n; x++){
        if (xy[x].second != lasty){

            vector<long long> fmapx;
            int counter = x;

            while(counter < n){
                counter++;
                if (xy[counter].second != xy[x].second){
                    break;
                }
            }
            for (int y = x; y < counter; y++){
                mapy[xy[y].first].second += 1;
                if (prevy[xy[y].first] == -1){
                    prevy[xy[y].first] = xy[y].second;
                }
                else{
                    mapy[xy[y].first].first += (mapy[xy[y].first].second * (prevy[xy[y].first] - xy[y].second));
                    mapy[xy[y].first].first %= 1000000007;
                    prevy[xy[y].first] = xy[y].second;
                }
            }


            fmapx.push_back(0);
            for (int y = x + 1; y < counter; y++){
                fmapx.push_back(((xy[y].first - xy[y - 1].first) * (y - x)  + fmapx[fmapx.size() - 1]));
                fmapx[fmapx.size() - 1] %= 1000000007;
            }
            long long bmapx[fmapx.size()];
            bmapx[fmapx.size() - 1] = 0;
            for (int y = counter - 2; y >= x; y--){
                bmapx[y - x] = (bmapx[y + 1 - x] + (xy[y + 1].first - xy[y].first) * (counter - y - 1));
                bmapx[y - x] %= 1000000007;
            }
            /*for (int x = 0; x < fmapx.size(); x++){
                cout << bmapx[x] << " ";
            }
            cout << "\n";*/
            if (counter - 1 > x){
                for (int y = x; y < counter; y++){
                    answer = answer + ((bmapx[y - x] + fmapx[y - x]) * mapy[xy[y].first].first) % 1000000007;
                    //cout << answer << " ";
                    answer = answer % 1000000007;
                }
            }

            lasty = xy[x].second;
        }
    }
    out << answer % 1000000007 << "\n";

}
