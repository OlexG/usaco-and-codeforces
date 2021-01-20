#include <fstream>
#include <string>
#include <iostream>
#include <algorithm>
#include <math.h>
using namespace std;
#include <vector>
int n, m;
long long arr[100000];
pair<long long, long long> q[100000];
bool compare(const pair<int, int>&i, const pair<int, int>&j)
{
    if (i.first == j.first){
        return i.second < j.second;
    }
    else{
        return i.first < j.first;
    }
}
int blowsearch(long long x, int low, int high){
    int index = (low + high)/2;
    if (x > arr[n - 1]){
        return n - 1;
    }
    if (x == arr[n - 1]){
        return n - 1;
    }
    if (x == arr[0]){
        return 0;
    }
    if (x < arr[0]){
        return 0;
    }
    if (index >= n - 1 || index == 0){
        return index;
    }
    if (arr[index] >= x && arr[index - 1] < x){
        return index;
    }
    else if (arr[index] < x){
        return blowsearch(x, index + 1, high);
    }
    else{

        return blowsearch(x, low, index);
    }
}
int bupsearch(long long x, int low, int high){
    int index = (low + high)/2;

    if (x > arr[n - 1]){
        return n ;
    }
    if (x == arr[n - 1]){
        return n ;
    }
    if (x == arr[0]){
        return 0;
    }
    if (x < arr[0]){
        return 0;
    }
    if (index >= n - 1 || index == 0){
        return index;
    }
    if (arr[index - 1] <= x && arr[index] > x){

        return index;
    }
    else if (arr[index] <= x){
        return bupsearch(x, index + 1, high);
    }
    else{
        return bupsearch(x, low, index);
    }
}
int main() {
    ifstream in("haybales.in");
    ofstream out("haybales.out");
    in >> n >> m;
    for (int x = 0; x < n; x++){
        in >> arr[x];

    }
    int one, two;
    for (int x = 0; x < m; x++){
        in >> one >> two;
        q[x] = make_pair(one, two);
    }
    sort(arr, arr + n);
    int curs = 0;
    int cure = 0;
    for (int x = 0; x < m; x++){
        if (q[x].first < arr[0] && q[x].second < arr[0]){
            out << 0 << "\n";
        }
        else if (q[x].first > arr[n - 1] && q[x].second > arr[n - 1]){
            out << 0 << "\n";
        }
        else if (q[x].first <= arr[0] && q[x].second >= arr[n - 1]){
            out << n << "\n";
        }
        else{
            out << bupsearch(q[x].second, 0, n) - blowsearch(q[x].first, 0, n)<< "\n";
        }
    }

}
