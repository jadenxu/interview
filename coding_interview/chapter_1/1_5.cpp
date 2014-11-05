#include <iostream>
#include <string>
using namespace std;

string compressStr(string str) {
  string new_str = "";
  char last = str[0];
  int count = 1;
  for (int i = 1; i < str.length(); i++) {
    if (str[i] == last) {
      count++;
    } else {
      new_str += last;
      new_str += to_string(count);
      last = str[i];
      count = 1;
    }
  }
  new_str += last;
  new_str += to_string(count);

  return new_str.length() > str.length() ? str : new_str;
}

int main() {
  string str;
  cin>>str;
  cout<<compressStr(str)<<endl;
  return 0;
}
