#include <fstream>
#include <string>
#include <iostream>
#include <math.h>
using namespace std;
bool cmpf(float A, float B, float epsilon = 0.000005f)
{
    return (fabs(A - B) < epsilon);
}
int main() {

    ifstream in("homework.in");
    ofstream out("homework.out");
    int n;
    in >> n;
    int arr[n];
    for (int x = 0; x < n; x ++){
        in >> arr[x];
    }

    float currentbest = 0.0;
    int k;
    int answers[100000];
    int index = 0;
    long long sum = 0;
    int smallest = 100000;
    for (int x = n - 1; x > 0; x --){
        if (arr[x] < smallest){
            smallest = arr[x];
        }
        sum = sum + arr[x];

        if ((float)(sum - smallest)/(float)(n - x - 1) > currentbest){
            currentbest = (float)(sum - smallest)/(float)(n-x - 1);

            k = x ;

        }

    }

    sum = 0;
    smallest = 100000;

    for (int x = n - 1; x > 0; x --){
        if (arr[x] < smallest){
            smallest = arr[x];
        }
        sum = sum + arr[x];

        if (cmpf((float)(sum - smallest)/(float)(n - x - 1),currentbest)){

            k = x;
            answers[index] = k;
            index = index + 1;


        }

    }

    for (int x = index - 1; x > - 1; x --){

        out << answers[x] << "\n";
    }


}
