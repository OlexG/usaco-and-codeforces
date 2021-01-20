#include <iostream>
#include <math.h>
using namespace std;
void solve()
{
    int arr[20];
    int n, h, total;
    total = 100000;
    cin >> n >> h;
    int power = 1;
    for (int x = 0; x < n; x++){
        cin >> arr[x];
        power *= 2;
    }

    for (int x = 0; x < power; x++){
        int an = 0;
        for (int y = 0; y < n; y++){
            if ((x &(1<<y)) > 0){
                an += arr[y];
            }
        }
        if (an >= h){
            total = min(total, an);
        }
    }
    cout << total - h;

}

int main()
{
    solve();
}
