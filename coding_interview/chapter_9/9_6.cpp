#include <iostream>
#include <string>
#include <vector>
using namespace std;

void parenthesis_help(int left, int right, string s, vector<string>& result) {
  if (left == 0 && right == 0) {
    result.push_back(s);
    return;
  }

  if (left > 0) {
    parenthesis_help(left - 1, right, s + "(", result);
  } 

  if (right > left) {
    parenthesis_help(left, right - 1, s + ")", result);
  }
}

vector<string> parenthesis(int n) {
  vector<string> result;
  string s;
  parenthesis_help(n, n, s, result);

  return result;
}

int main() {
  int n;
  cin>>n;
  vector<string> v = parenthesis(n);
  for (int i = 0; i < v.size(); i++) {
    cout<<v[i]<<endl;
  }
  return 0;
}
