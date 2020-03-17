#include <string>
#include <iostream>
using namespace std;
int main(){
    int n;
    cin >> n;
    int left;
    int right;
    int one;
    int answer;
    int two;
    int three;
    int four;
    for (int x = 0; x < n; x ++){
        cin >> one;
        cin >> two;
        cin >> three;
        cin >> four;
        if (two < one){
            one = one + two;
            two = one - two;
            one = one - two;
        }

        if (three >= one && three <= two){
            left = three - four;
            if (left >= one && left <= two){
                left = four;
            }
            else{
                left = three - one;
            }
        }
        else{
            left = three - four;
            if (three < one){
                left = 0;
            }
            else{
                left = two - left;
            }
        }
        if (left < 0){
            left = 0;
        }
        if (three >= one && three <= two){
            right = three + four;
            if (right >= one && right <= two){
                right = four;
            }
            else{
                right = two - three;
            }
        }
        else{
            right = three + four;
            if (three > two){
                right = 0;
            }
            else{
                right = right - one;
            }
        }
        if (right < 0){
            right = 0;
        }

        answer = (two - one) - (left + right);
        if (answer < 0){
            cout << "0\n";

        }
        else{
            cout << answer << "\n";
        }
    }
}
