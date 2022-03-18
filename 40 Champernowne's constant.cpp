/******************
https://projecteuler.net/problem=40

BASIC STRATEGY: This is completely straightforward; create a string representing
the decimal expansion of Champerowne's constant and sum the appropriate digis.
******************/
#include <iostream>
#include <vector>
#include <cmath>
#include <string>
using namespace std;


int chartoint(char c) {return (int)c - 48;}

int main()
{

string s;

int count=1;
int sum=0;

while (count<1000000) {
  s+=to_string(count);
  count++;
}

for (int i=0;i<7;i++){
  cout<<s[pow(10,i)]<<endl;
  sum+=chartoint(s[pow(10,i)]);
}

cout<<endl<<sum<<endl;

return 0;
}
