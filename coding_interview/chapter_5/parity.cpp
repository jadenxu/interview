#include <iostream>
using namespace std;

bool parity_1(unsigned int a) {
  int count = 0;
  
  for (int i = a; i > 0; i = i & (i - 1)) {
    count++;
  }

  return count % 2;
}

bool parity_2(unsigned int a) {
  for (int i = 4; i >= 0; i--) {
    int step = 1 << i;
    int mask = (1 << step) - 1;
    a = (a & mask) ^ (a >> step);
  }
  /*
  a = (a & 0x0000FFFF) ^ (a >> 16);
  a = (a & 0x000000FF) ^ (a >> 8);
  a = (a & 0x000000F) ^ (a >> 4);
  a = (a & 0x0000003) ^ (a >> 2);
  a = (a & 0x0000001) ^ (a >> 1);
*/
  return a;
}

int main() {
  unsigned int a;
  cin>>a;
  cout<<parity_1(a)<<" "<<parity_2(a)<<endl;
}
