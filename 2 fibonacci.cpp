/******************
https://projecteuler.net/problem=2
******************/
#include <iostream>
#include <vector>
using namespace std;

int main() {

vector<int> fibo;
fibo.push_back(1);
fibo.push_back(2);
fibo.resize(1000);
int len=1;
int total=0;

while (fibo[len]<4000001) {
  if (fibo[len]%2==0) total+=fibo[len];
  len++;
  fibo[len]=fibo[len-1]+fibo[len-2];
}
cout<<total<<endl;

return 0;
}
