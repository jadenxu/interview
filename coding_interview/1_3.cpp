#include <iostream>
#include <string>
using namespace std;

bool isPermutation(string str1, string str2) {
  if (str1.length() != str2.length()) {
    return false;
  }

  int counter[256] = {0};
  for (int i = 0; i < str1.length(); i++) {
    ++counter[str1[i]];
  }
  for (int i = 0; i < str2.length(); i++) {
    // We do not need to check the whether counters are all zeros
    // in the end, instead we check whether any counter is less than
    // zero in the process, because the two strings have equal length
    if (--counter[str2[i]] < 0) {
      return false;
    }
  }
  
  return true;
}

int main() {
  string str1, str2;
  cin>>str1>>str2;
  cout<<isPermutation(str1, str2)<<endl;
  return 0;
}
