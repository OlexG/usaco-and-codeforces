#include <fstream>
#include <string>
#include <iostream>
#include <algorithm>
#include <math.h>
#include <map>
#include <string>
using namespace std;

long long n, a, b, c, d , e, f, g , h, m;
vector<pair <long long, long long>> arr;
bool comparison(pair<long long,long long> a,pair<long long,long long> b)
{
       if (a.second == b.second){
            return a.first < b.first;
       }
       else{
            return a.second > b.second;
       }
}
long long power(long long x, long long y, long long m){
    long long answer = 1;
    for (long long c = 0; c < y; c++){
        answer = (answer * x) % m;
    }
    return answer;
}
int main(){
    cin >> n >> a >> b >> c >> d >> e >> f >> g >> h >> m;
    for (long long x = 0; x < 3 * n; x++){
        long long one = ((a % d) * power(x, 5, d) + (b % d) * power(x, 2, d) + (c % d)) % d;
        long long two = ((e % h) * power(x, 5, h)+ (f % h) *  power(x, 3, h) + (g % h)) % h;
        arr.push_back(make_pair(one, two));

    }
    sort(arr.begin(), arr.end(), comparison);
    long long answer = 0;
    for (int x = 0; x < n; x++){
        answer = (answer + arr[x].first) % m;
    }
    cout << answer;

}
