#include <iostream>
#include <string>
using namespace std;

bool isUniqueChars(string str) {
  // Here we could use bit operation to save some storage
  bool check[256] = {false};
  for (int i = 0; i < str.length(); i++) {
    if(check[str[i]]) {
      return false;
    }
    
    check[str[i]] = true;
  }

  return true;
}

int main() {
  string input;
  cin>>input;
  cout<<isUniqueChars(input)<<endl;

  return 0;
}
