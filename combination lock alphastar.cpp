#include <fstream>
#include <string>
#include <iostream>
#include <math.h>
#include <algorithm>
#include <vector>
using namespace std;
int n;
int fone, ftwo, fthree;
int mone, mtwo, mthree;
bool checkone(int one, int two, int three, int fone, int ftwo, int fthree){
    int onel = one - 2;
    int oneh = one + 2;
    if (one < 3){
        onel = n + one - 2;
        if (fone < onel && fone > oneh){
            return false;
        }
    }
    else if (one > n - 3){
        oneh = one - n + 2;
        if (fone < onel && fone > oneh){
            return false;
        }
    }
    else if (fone < onel || fone > oneh){
        return false;
    }
    int twol = two - 2;
    int twoh = two + 2;
    if (two < 3){
        twol = n + two - 2;
        if (ftwo < twol && ftwo > twoh){
            return false;
        }
    }
    else if (two > n - 3){
        twoh = two - n + 2;
        if (ftwo < twol && ftwo > twoh){
            return false;
        }
    }
    else if (ftwo < twol || ftwo > twoh){
        return false;
    }
    int threel = three - 2;
    int threeh = three + 2;
    if (three < 3){
        threel = n + three - 2;
        if (fthree < threel && fthree > threeh){
            return false;
        }
    }
    else if (three > n - 3){
        threeh = three - n + 2;
        if (fthree < threel && fthree > threeh){
            return false;
        }
    }
    else if (fthree < threel || fthree > threeh){
        return false;
    }
    return true;
}
int main(){
    cin >> n;
    cin >> fone >> ftwo >> fthree >> mone >> mtwo >> mthree;
    int answer = 0;
    for (int x = 0; x < n; x++){
        for (int y = 0; y < n; y++){
            for (int z = 0; z < n; z++){
                if (checkone(x, y, z, fone, ftwo, fthree)){
                    answer++;
                }
                else if (checkone(x,y, z, mone, mtwo, mthree)){
                    answer++;
                }

            }
        }
    }
    cout << answer;
}
