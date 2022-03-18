/******************
https://projecteuler.net/problem=4
******************/
#include <iostream>
#include <vector>
#include <cmath>
#include<algorithm>//for reverse()
using namespace std;

//returns true if the integer n is a palindrome
bool palindrome(int n) {
  string s,t;
  t = to_string(n);s=t;
  reverse(s.begin(),s.end());
  //cout<<s;cout<<t;
  return t==s;
}


int main() {

vector<int> pals;

for (int i=100;i<1000;i++) {
for (int j=100;j<1000;j++) {
  if(palindrome(i*j)) {pals.push_back(i*j);}
}}

auto it=max_element(pals.begin(),pals.end());

cout<<*it;

return 0;
}
