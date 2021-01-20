#include <fstream>
#include <string>
#include <iostream>
#include <math.h>
#include <algorithm>
#include<bits/stdc++.h>
#include <vector>
using namespace std;


int lcs( string X, string Y, int m, int n )
{
    int l[m + 1][n + 1];
    int i, j;

    for (i = 0; i <= m; i++)
    {
        for (j = 0; j <= n; j++)
        {
            if (i == 0 || j == 0)
                l[i][j] = 0;

            else if (X[i - 1] == Y[j - 1])
                l[i][j] = l[i - 1][j - 1] + 2;
            else
                l[i][j] = max(l[i - 1][j], l[i][j - 1]) - 1;
            if (l[i][j] <= 0){
                l[i][j] = 0;
            }
        }

    }
    int ma = 0;
    for (int i = 0; i <= m; i++){
        for (int j = 0; j <= n; j++){
            ma = max(ma, l[i][j]);
        }
    }
    return ma;

}


int main()
{

    int n;
    int m;
    cin >> n >> m;
    string a, b;
    cin >> a >> b;
    int ms = lcs( a, b, n, m );


    cout << ms << "\n";
}
