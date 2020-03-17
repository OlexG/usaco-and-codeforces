#include <iostream>
#include <string>
using namespace std;
void P(int n, int k)
{
  if (n == 1) return;
  if (n % k) P(n, k+1);
  else
  {
    cout << k << " ";
    P(n/k, k);
  }
}
int main(){

    P(12 , 3);
}
