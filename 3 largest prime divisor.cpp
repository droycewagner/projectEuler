/******************
https://projecteuler.net/problem=3

Computes successively larger primes until one of these is at least the square root of
600851475143.
******************/
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

vector<int> primes,divis;
primes.push_back(2);
long int n =600851475143;
int sn=floor(sqrt(n));
int i=3;

cout<<sn<<endl;

while (primes.back()<sn+1) {
  if (n%primes.back()==0) divis.push_back(primes.back());
  primes.push_back(nextprime(primes));
}

for (int p:divis) cout<<p<<", ";

return 0;
}
