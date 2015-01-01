#include <iostream>
using namespace std;

unsigned int insertBits(unsigned int a, unsigned int b, int i, int j) {
  unsigned int b_mask = b << i;
  cout<<b_mask<<endl;
  unsigned int a_mask = ((1 << i) - 1) ^ ((1 << (j + 1)) - 1);
  a_mask = ~a_mask;
  a_mask = a_mask & a;

  return a_mask | b_mask;
}

int main() {
  unsigned int a, b, i, j;
  cin>>a>>b>>i>>j;

  cout<<insertBits(a, b, i, j)<<endl;
}
