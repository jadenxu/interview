#include <iostream>
using namespace std;

unsigned int nextNum_bf(unsigned int a) { 
  if (a + 1 < a) {
    return -1;
  }

  int count = 0; 
  for (int i = a; i > 0; i = i & (i - 1)) {
    count++;
  }

  int num;
  for (num = a + 1; ; num++) {
    int tmp = 0;
    for (int i = num; i > 0; i = i & (i - 1)) {
      tmp++;
    }
    if (tmp == count) {
      break;
    }
  }

  return num;
}

unsigned int prevNum_bf(unsigned int a) {
  if (((a + 1) & a) == 0) {
    return -1;
  }

  int count = 0; 
  for (int i = a; i > 0; i &= i - 1) {
    count++;
  }

  int num;
  for (num = a - 1; ; num--) {
    int tmp = 0;
    for (int i = num; i > 0; i &= i - 1) {
      tmp++;
    }
    if (tmp == count) {
      break;
    }
  }

  return num;
}

unsigned int nextNum(unsigned int a) {
  int tmp = a;
  int num_0 = 0, num_1 = 0;
  while ((tmp & 1) == 0 && tmp > 0) {
    num_0++;
    tmp >>= 1;
  }
  while ((tmp & 1) == 1 && tmp > 0) {
    num_1++;
    tmp >>= 1;
  }

  // maximum 4-bits 1100, no next num with same bit number
  if (num_0 + num_1 == 31) {
    return -1;
  }
  
  return a + (1 << num_0) + (1 << (num_1 - 1)) - 1;
}

unsigned int prevNum(unsigned int a) {
  int tmp = a;
  int num_0, num_1 = 0;
  while ((tmp & 1) == 1 && tmp > 0) {
    num_1++;
    tmp >>= 1;
  }

  // 0011, no previous num with same bit number
  if (tmp == 0) {
    return -1;
  }

  while ((tmp & 1) == 0 && tmp > 0) {
    num_0++;
    tmp >>= 1;
  }

  return a - (1 << num_1) - (1 << (num_0 - 1)) + 1; 
}

int main() {
  unsigned int a;
  cin>>a;
  cout<<nextNum(a)<<" "<<nextNum_bf(a)<<endl;
  cout<<prevNum(a)<<" "<<prevNum_bf(a)<<endl;

  return 0;
}
