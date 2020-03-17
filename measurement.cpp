#include <fstream>
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;
struct change{
    long long day;
    long long id;
    long long amount;
};
bool compare(change a, change b){
    return (a.day < b.day);
}
int main() {
    ifstream in("measurement.in");
    ofstream out("measurement.out");
    int n;
    long long g;
    in >> n;
    in >> g;
    long long leaderboard[3] = {g, 0, n};
    long long standings[n];
    fill(standings, standings + n, g);
    change changes[n];
    for (int x = 0; x < n; x ++){
        in >> changes[x].day;

        in >> changes[x].id;
        in >> changes[x].amount;
    }
    sort(changes, changes + n, compare);
    int maximum = 0;
    int enc = 0;
    int answer = 0;
    for (int x = 0; x < n; x ++){
        if (standings[changes[x].id - 1] == leaderboard[0] && changes[x].amount < 0){
            standings[changes[x].id - 1] += changes[x].amount;
            maximum = 0;
            for (int y = 0; y < n; y ++){
                if (standings[y] > maximum){
                    maximum = standings[y];
                }
            }
            enc = 0;
            if (maximum == standings[changes[x].id - 1]){
                for (int y = 0; y < n; y ++){
                    if (standings[y] == maximum){
                        enc += 1;
                    }
                }
                if (enc > 1){
                    answer = answer + 1;
                    leaderboard[2] = enc;
                    leaderboard[0] = maximum;
                }
                else {
                    leaderboard[0] = maximum;
                }
            }
            else {
                for (int y = 0; y < n; y ++){
                    if (standings[y] == maximum){
                        enc += 1;
                        leaderboard[1] = y + 1;
                    }
                }
                answer = answer + 1;
                leaderboard[2] = enc;
                leaderboard[0] = maximum;
            }

        }
        else {

        standings[changes[x].id - 1] += changes[x].amount;
        if (standings[changes[x].id - 1] > leaderboard[0]){
            if (leaderboard[3] > 1 || leaderboard[1] != changes[x].id){
            leaderboard[0] = standings[changes[x].id - 1];
            leaderboard[1] = changes[x].id;
            leaderboard[2] = 1;
            answer = answer + 1;

            }
            else {
                leaderboard[0] = standings[changes[x].id - 1];
            }
        }
        else if(standings[changes[x].id - 1] == leaderboard[0]){
                leaderboard[2] += 1;
                answer = answer + 1;
        }
        }

    }
    out << answer << "\n";


}
