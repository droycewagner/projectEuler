/***************
48 self powers
https://projecteuler.net/problem=48
runs in about 1 sec
gives 9110846700

BASIC STRATEGY: This is completely straightforward. Compute the sum one step at a time,
constantly taking the result modulo 1e10 to avoid blowing up past the capacity of a long. 
*****************/

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

const long tendigs=10000000000;

long selfpow(const int n) {
  long*sp=new long(1);
  for (int i=1;i<=n;i++) {
  *sp=(*sp*n % tendigs);
  }
  return *sp;
}

int main() {

long sum=0;

for (int i=1;i<1000;++i) {
sum=(sum+selfpow(i)) % tendigs;
}

cout<<sum<<"\n";

return 0;
}
