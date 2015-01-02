#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<string> permutate_1(string s) {
  vector<string> perm;
  if (s.length() == 0) {
    return perm;
  } else if (s.length() == 1) {
    perm.push_back(s);
    return perm;
  }

  vector<string> perm_short = permutate_1(string(s.begin() + 1, s.end()));
  for (int i = 0; i < s.length(); i++) {
    perm.insert(perm.end(), perm_short.begin(), perm_short.end());
    for (int j = 0; j < perm_short.size(); j++) {
      perm[i * perm_short.size() + j].insert(i, 1, s[0]);
    }
  }

  return perm;
}

void swap(char& a, char& b) {
  char tmp = a;
  a = b;
  b = tmp;
}

void permutate_help(string s, int index, vector<string>& perm) {
  if (index == s.length() - 1) {
    perm.push_back(s);
  }

  for (int i = index; i < s.length(); i++) {
    swap(s[index], s[i]);
    permutate_help(s, index + 1, perm);
    swap(s[index], s[i]);
  }
}

vector<string> permutate_2(string s) {
  vector<string> perm;
  permutate_help(s, 0, perm);

  return perm;
}

int main() {
  string s;
  cin>>s;

  vector<string> v = permutate_2(s);
  for (int i = 0; i < v.size(); i++) {
    cout<<v[i]<<endl;
  }

  return 0;
}
