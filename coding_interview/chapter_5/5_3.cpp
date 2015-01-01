#include <iostream>
using namespace std;

void printNum(unsigned int a) {
  int count = 0;
  for (int i = 0; i < 32; i++) {
    if (a & 1 << i) {
      count++;
    }
  }

  unsigned int a_min = (1 << count) - 1;
  unsigned int a_max = ((~0) << (32 - count));
  cout<<a_min<<" "<<a_max<<endl;
}

int main() {
  unsigned int a;
  cin>>a;
  printNum(a);
}
