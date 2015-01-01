#include <iostream>
using namespace std;

// Remember the priority is ~, << >>, &, ^, |
// If not sure about the priority, use parenthesis
unsigned int swapOddEvenBits(unsigned int a) {
  return ((a & 0xAAAAAAAA) >> 1) | ((a & 0x55555555) << 1);
}

int main() {
  unsigned int a;
  cin>>a;
  cout<<swapOddEvenBits(a)<<endl;

  return 0;
}
