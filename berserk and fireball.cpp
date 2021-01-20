#include <fstream>
#include <string>
#include <iostream>
#include <algorithm>
#include <vector>
#include <math.h>
using namespace std;


long long n, m;
long long fireprice, firerange,  bprice;
vector<long long> a;
vector<long long> bcheck;
vector<long long> b;
bool impossible = false;
long long answer = 0;
long long solve(long long startindex, long long endindex, long long most){
    long long countofbignums = 0;
    long long totalnums = endindex - startindex + 1;
    for (long long x = startindex; x <= endindex; x++){
        if (a[x] > most){
            countofbignums++;
        }
    }

    if (bprice > fireprice/firerange){
        long long neededfireshots = (long long)ceil((float)countofbignums/firerange);
        if (neededfireshots * firerange > totalnums){
            impossible = true;
            return 0;
        }
        else{
            answer += neededfireshots * fireprice;
            long long newtotalnums = totalnums - (neededfireshots * firerange);
            answer += (long long)floor((float)newtotalnums/firerange) * fireprice;
            answer += (newtotalnums % firerange) * bprice;
        }
    }
    else{
        long long neededfireshots = (countofbignums > 0) ? 1 : 0;
        if (neededfireshots * firerange > totalnums){
            impossible = true;
            return 0;
        }
        else{
            answer += neededfireshots * fireprice;
            long long newtotalnums = totalnums - (neededfireshots * firerange);
            answer += newtotalnums * bprice;
        }
    }
    return 0;

}
int main(){
    cin >> n >> m >> fireprice >> firerange >> bprice;
    long long temp;
    for (long long x = 0; x < n; x++){
        cin >> temp;
        a.push_back(temp);
    }
    for (long long x = 0; x < m; x++){
        cin >> temp;
        b.push_back(temp);
        bcheck.push_back(-1);
    }
    long long counter = 0;
    for (long long x = 0; x < n; x++){
        if (counter < m){
            if (a[x] == b[counter]){
                bcheck[counter] = x;
                long long startindex, endindex, most;
                if (counter == 0){
                    startindex = 0;
                    endindex = x - 1;
                    most = a[x];
                }
                else{
                    endindex = x - 1;
                    startindex = bcheck[counter - 1] + 1;
                    most = max(a[x], a[bcheck[counter - 1]]);
                }
                if (startindex <= endindex){
                    //cout << startindex << endindex << most;
                    solve(startindex, endindex, most);
                }
                if (counter == m - 1){
                    startindex = x + 1;
                    endindex = n - 1;
                    most = a[x];
                    if (startindex <= endindex){
                        //cout << startindex << endindex << most;
                        solve(startindex, endindex, most);
                    }
                }
                counter++;
            }
        }
    }
    if (counter < m){
        impossible = true;
    }
    if (impossible){
        cout << "-1\n";
    }
    else{
        cout << answer << "\n";
    }





}
