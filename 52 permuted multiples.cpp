/******************
https://projecteuler.net/problem=52

BASIC STRATEGY: This is completely straightforward; for each integer, compute multiples,
convert to string and sort; check to see if the result is the same. 
******************/
#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm> //for sort
using namespace std;

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



int main() {

int i=100;
vector<int> ans;

while(true){
  if (isperm(i,2*i,3*i)&&isperm(3*i,4*i,5*i)&&isperm(i,6*i)) {
    for (int j=1;j<7;j++) {ans.push_back(j*i);}
    ;break;
  }
  i++;
}

for (int p:ans) cout<<p<<", ";

cout<<"\n";

return 0;
}
