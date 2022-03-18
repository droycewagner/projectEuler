/***************
160 factorial trailing digits
https://projecteuler.net/problem=160
runs in about 2 sec
gives 09376

BASIC STRATEGY: the first for loop in main computes the trailing digits for 100000!.
Then we take powers of this to get to one trillion. 
*****************/

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

long last5(const long n) {
  long*sp=new long(n);
  while (*sp%10==0) {
  *sp=*sp/10;
  }
  return *sp%100000;
}

int main() {

long ans=1;

//long maxi=1000000000000;
//maxi=20;



for (int i=1;i<=100000;++i) {
ans=last5(ans*last5(i));
}

long finalans=1;

cout<<"first loop done\n";

for (int i=1;i<=10000000;i++) {
finalans=last5(finalans*ans);
}

cout<<finalans<<"\n";

return 0;
}
