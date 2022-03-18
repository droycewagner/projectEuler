/**********
https://projecteuler.net/problem=7
**********/


#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

bool checkprimes(int n, vector<int> primes) {
  for (int p:primes) {if (n%p==0) return false;}
  return true;
}

int nextprime(vector<int>primes){
  int j=primes.back()+1;
  while(true) {if (checkprimes(j,primes)) return j; else j++;}
  return 100;
}

int main() {

vector<int> primes;
primes.push_back(2);
int count=1;

while (count<10001) {
  primes.push_back(nextprime(primes));
  count++;
}

cout<<primes.back();

return 0;
}
