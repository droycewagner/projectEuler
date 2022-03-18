/******************
https://projecteuler.net/problem=49

BASIC STRATEGY: In this case, the brute force approach works quickly.
Compute a list of primes less than 10000 and check each increasing sequence of integers
until an arithmetic sequence of permuted primes occurs. 
******************/
#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm> //for sort
using namespace std;


int digitsum(int n) {
  int sum=0;
  int m=0;
  while (n>0) {
    m=n%10;
    sum+=m;
    n=(n-m)/10;
  }
  return sum;
}

bool checkprimes(int n, vector<int> primes) {
  for (int p:primes) {if (n%p==0) return false;}
  return true;
}

vector<int> getdigits(int n) {
  vector<int>digits;
  int m=0;
  while (n>0) {
    m=n%10;
    digits.push_back(m);
    n=(n-m)/10;
  }
  sort(digits.begin(),digits.end());
  return digits;
}

bool isperm(int i, int j){
  return getdigits(i)==getdigits(j);
}

bool isperm(int i,int j, int k) {return (isperm(i,j)&&isperm(j,k));}

int nextprime(vector<int>primes){
  int j=primes.back()+1;
  while(true) {if (checkprimes(j,primes)) return j; else j++;}
  return 100;
}

//returns a vector of primes <=n
vector<int> getprimes(int n) {
  vector<int> primes;
  primes.push_back(2);
  while (primes.back()<n+1) {
    primes.push_back(nextprime(primes));
  }
  if (primes.back()>n)primes.pop_back();
  return primes;
}

//returns a vector of primes betweeen n and m, inclusive
vector<int> getprimes(int n, int m){
  vector<int> primes=getprimes(m);
  while (primes[0]<n)primes.erase(primes.begin());
return primes;
}





int main() {

vector<int> primes, ans;

primes=getprimes(1000,10000);

cout<<primes[0]<<endl;
cout<<primes.back()<<endl;

for(int i=0;i<primes.size();i++){
for(int j=0;j<i;j++){
for(int k=0;k<j;k++){
  if (primes[i]-primes[j]==primes[j]-primes[k] && isperm(primes[i],primes[j],primes[k]))
   cout<<primes[i]<<","<<primes[j]<<","<<primes[k]<<endl;
}}}

return 0;
}
