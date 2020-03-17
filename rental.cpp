#include <fstream>
#include <string>
#include <iostream>
#include <math.h>
#include <algorithm>
using namespace std;
#include <vector>
struct shop{
    long long gal;
    long long price;
};
bool compare(shop a, shop b){
    return (a.price > b.price);
}
bool worthit(long long cow, shop shops[], vector<long long> sells, int index, int m){
    int total = 0;
    int gallons = 0;

    while (gallons < cow){
        if (index > m - 1){
            break;
        }
        if (gallons + shops[index].gal > cow){
                total = total + (cow - gallons) * shops[index].price;
                gallons = cow;
        }
        else {
            total = total + shops[index].gal * shops[index].price;
            gallons = gallons + shops[index].gal;
            index = index + 1;
        }

    }
    if (total > sells[sells.size() - 1]){
            return true;

    }
    else {
        return false;
    }

}
int main() {
    ifstream in("rental.in");
    ofstream out("rental.out");
    int n;
    int m;
    int r;
    in >> n;
    in >> m;
    in >> r;
    vector<long long> cows(n);
    shop shops[m];
    vector<long long> sells(r);

    for (int x = 0; x < n; x++){
        in >> cows[x];
    }
    for (int x = 0; x < m; x++){
        in >> shops[x].gal;
        in >> shops[x].price;

    }
    for (int x = 0; x < r; x++){
        in >> sells[x];
    }
    sort(sells.begin(), sells.end());
    sort(cows.rbegin(), cows.rend());

    sort(shops, shops + m, compare);
    long long total = 0;
    int cowindex = 0;
    int index = 0;
    int gallons = 0;
    while (cowindex < cows.size()){

        while(!worthit(cows[cowindex], shops, sells, index, m) && sells.size() != 0 && cows.size() > cowindex){
            total += sells[sells.size() - 1];

            sells.pop_back();
            cows.pop_back();


        }
        gallons = 0;
        if (cowindex <= cows.size() - 1){
            while (gallons < cows[cowindex]){


                if (index > m - 1){
                    break;
                }

                if (gallons + shops[index].gal > cows[cowindex]){
                    total = total + (cows[cowindex] - gallons) * shops[index].price;
                    shops[index].gal =  shops[index].gal - (cows[cowindex] - gallons);
                    gallons = cows[cowindex];



                }
                else {
                    total = total + shops[index].gal * shops[index].price;
                    gallons = gallons + shops[index].gal;
                    index = index + 1;

                }

        }
        }

        cowindex += 1;



    }
    cout << total;
    out << total << "\n";






}

