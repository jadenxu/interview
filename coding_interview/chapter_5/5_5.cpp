#include <iostream>
using namespace std;

int bitSwap(int a, int b) {
  int count = 0;
  for (int i = a ^ b; i > 0; i = i & (i - 1)) {
    count++;
  }
  return count;
}

int main() {
  int a, b;
  cin>>a>>b;
  cout<<bitSwap(a, b)<<endl;

  return 0;
}
