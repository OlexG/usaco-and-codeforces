#include <iostream>
#include <math.h>
#include <algorithm>
using namespace std;
void solve()
{
    pair<int, int> arr[20];
    int n, h;
    h = 0;
    cin >> n;
    int power = 1;
    int one , two;
    for (int x = 0; x < n; x++){
        cin >> one >> two;
        arr[x] = make_pair(one, two);
        power *= 2;
    }
    sort(arr, arr+ n);
    for (int x = 0; x < power; x++){
        int an = 0;
        int prevx = 0;
        int prevy = 0;
        for (int y = 0; y < n; y++){
            if ((x &(1<<y)) > 0){
                if (arr[y].first >= prevx && arr[y].second >= prevy){
                    an++;
                    prevx = arr[y].first;
                    prevy = arr[y].second;
                }
            }
        }
        h = max(h, an);

    }
    cout << h;

}

int main()
{
    solve();
}
