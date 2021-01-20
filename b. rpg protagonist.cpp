#include <fstream>
#include <string>
#include <iostream>
#include <math.h>
#include <algorithm>
#include <bits/stdc++.h>
#include <vector>
#include <math.h>
using namespace std;

int t;

long long n1, n2, count_s, count_a, sword_w, axe_w;

int main(){
    cin >> t;
    for (int v = 0; v < t; v++){
        cin >> n1 >> n2 >> count_s >> count_a >> sword_w >> axe_w;
        long long nn1, nn2, ncount_s, ncount_a;
        bool smaller = true;
        if (sword_w > axe_w){
            smaller = false;
        }
        //simulate taking a diff number of swords
        int answer = 0;
        for (int x = 0; x <= count_s; x++){
            int nanswer = 0;
            nn1 = n1;
            nn2 = n2;
            ncount_s = count_s;
            ncount_a = count_a;

            long long sword_number = x * sword_w;
            if (sword_number <= nn1){
                nanswer += x;
                ncount_s -= x;
                nn1 -= sword_number;
                //now that we got rid of fixed num of swords, delete as many axes as we can

                long long num_axes_taken = floor(nn1/axe_w);
                num_axes_taken = min(num_axes_taken, ncount_a);


                ncount_a -= num_axes_taken;
                nanswer += num_axes_taken;
                nn1 -= (num_axes_taken * axe_w);
                //now fill the follower with as much as possible
                if (smaller){
                    //give him as many swords as we can
                    long long num_swords_taken = floor(nn2/sword_w);
                    num_swords_taken = min(ncount_s, num_swords_taken);
                    ncount_s -= num_swords_taken;
                    nanswer += num_swords_taken;
                    nn2 -= (num_swords_taken * sword_w);
                    //give him as many axes as we can
                    num_axes_taken = floor(nn2/axe_w);
                    num_axes_taken = min(ncount_a, num_axes_taken);
                    ncount_a -= num_axes_taken;
                    nanswer += num_axes_taken;
                    nn2 -= (num_axes_taken * axe_w);

                }
                else{
                    //give him as many axes as we can
                    num_axes_taken = floor(nn2/axe_w);
                    num_axes_taken = min(ncount_a, num_axes_taken);
                    ncount_a -= num_axes_taken;
                    nanswer += num_axes_taken;
                    nn2 -= (num_axes_taken * axe_w);
                    //give him as many swords as we can
                    long long num_swords_taken = floor(nn2/sword_w);
                    num_swords_taken = min(ncount_s, num_swords_taken);
                    ncount_s -= num_swords_taken;
                    nanswer += num_swords_taken;
                    nn2 -= (num_swords_taken * sword_w);
                }
                answer = max(answer, nanswer);
            }

        }
        cout << answer << endl;
    }
}
