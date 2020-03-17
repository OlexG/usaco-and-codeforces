#include <fstream>
#include <string>
#include <iostream>
#include <math.h>
#include <algorithm>
using namespace std;
struct life{
    long long start;
    long long ending;

};
bool compare(life a, life b){
    return (a.start < b.start);
}
int main() {

    ifstream in("lifeguards.in");
    ofstream out("lifeguards.out");
    int n;
    in >> n;
    life arr[n];
    for (int x = 0; x < n; x ++){
        arr[x].start = 0;
        arr[x].ending = 0;
        in >> arr[x].start;
        in >> arr[x].ending;

    }

    sort(arr, arr + n, compare);


    long long currentbest = 0;
    long long totalcovered = 0;
    long long smallestc = 1000000000;
    long long covered = 0;
    int index = 0;
    for (int x = 0; x < n; x ++){
        if (arr[x].start > currentbest){
            totalcovered = totalcovered + arr[x].ending - arr[x].start;
            currentbest = arr[x].ending;
            covered = arr[x].ending - arr[x].start;
            if (x != n - 1){
                if (arr[x].ending < arr[x + 1].ending && arr[x].ending > arr[x+1].start){
                    covered = covered - arr[x].ending + arr[x+1].start;
                }
            }
            if ((arr[x].ending - arr[x].start) < smallestc){
                smallestc = totalcovered;
                index = x;

            }
        }
        else {

                    if (arr[x].ending < currentbest){
                        covered = 0;


                    }
                    else {
                        covered = arr[x].ending - currentbest;
                        currentbest = arr[x].ending;

                    }
                    totalcovered = totalcovered + covered;
                    if (x != n - 1){
                        if (arr[x].ending < arr[x + 1].ending && arr[x].ending > arr[x+1].start){
                            covered = covered - arr[x].ending + arr[x+1].start;
                        }
                    }
                    if (covered < smallestc){
                        smallestc = covered;
                        index = x;

                    }





        }



    }

    currentbest = 0;
    totalcovered = 0;

    covered = 0;
    for (int x = 0; x < n; x ++){
        if (x != index) {
        if (arr[x].start > currentbest){
            totalcovered = totalcovered + arr[x].ending - arr[x].start;
            currentbest = arr[x].ending;

        }
        else {

                if (arr[x].ending < currentbest){
                        covered = 0;
                }
                else {
                    covered = arr[x].ending - currentbest;
                    currentbest = arr[x].ending;

                }

                totalcovered = totalcovered + covered;



        }
        }


    }


    out << totalcovered << "\n";




}
