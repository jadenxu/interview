#include <iostream>
using namespace std;

string convertBits(double a) {
  if (a >= 1 || a <= 0) {
    return "ERROR";
  }

  string result = ".";
  while (a > 0) {
    /*if (result.length() > 32) {
      return "ERROR";
    }*/

    a *= 2.0;
    if (a >= 1) {
      result += "1";
      a -= 1.0;
    } else {
      result += "0";
    }
  }

  return result;
}

int main() {
  double a;
  cin>>a;
  cout<<convertBits(a)<<endl;

  return 0;
}
