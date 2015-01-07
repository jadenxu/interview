#include <iostream>
#include <vector>
using namespace std;

string convertBits(int v) {
  string s;
  for (int i = 0; i < 32; i++) {
    if (s & 1 << i == 1) {
      s = "1" + s;
    } else {
      s = "0" + s;
    }
  }
}

int main () {
  int n, miss;
  cin>>n>>miss;
  vector<string> v;
  for (int i = 0; i < n; i++) {
    if (i == miss) {
      continue;
    }
    v.push_back(convertBits(i));
  }
  
  cout<<findMiss(v)<<endl;

  return 0;
}
