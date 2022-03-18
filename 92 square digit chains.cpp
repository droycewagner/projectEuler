/************************
92 square digit chains
https://projecteuler.net/problem=92
runs in about 10 sec
final answer: 8581146

BASIC STRATEGY:
Use of vector<bool> instead of an array of bool, etc. is key and uses 1/16th the memory.
The vector<bool> object ischecked keeps track of whether an integer has been checked;
"goesto89" keeps track of whether the square digit sum terminates with a loop containing 89.
Integers are pushed back to tempv until an integer that has already been checked is reached.

*************************/

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

//computes the sum of the square of each digit
int sqdigitsum(const int nn) {
  int n=nn;
  int* sum = new int(0);
  int m=0;
  while (n>0) {
    m=n%10;
    *sum+=pow(m,2);
    n=(n-m)/10;
  }
  return *sum;
}



int main() {

vector<bool> ischecked;
vector<bool> goesto89;

int largest=10000000;
ischecked.resize(largest);
goesto89.resize(largest);

for (int i = 0; i < ischecked.size(); i++)
        ischecked[i] = false;
int temp;
vector<int> tempv;
bool is89;
ischecked[1]=1;
ischecked[89]=1;
goesto89[1]=0;
goesto89[89]=1;


for (int i=1;i<largest;i++) {
  temp=i;
  while (true) {
    tempv.push_back(temp);
    if (ischecked[temp]) break;
    temp=sqdigitsum(temp);
  }
  is89=(goesto89[tempv.back()])?1:0;
  for (auto j:tempv) {ischecked[j]=1;goesto89[j]=is89;}
  tempv.clear();
}

int total=0;
for (auto i:goesto89) total+=i;

cout<<"total going to 89 is "<<total<<"\n";


return 0;
}
