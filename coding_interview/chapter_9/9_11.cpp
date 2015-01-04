#include <iostream>
#include <vector>
using namespace std;

int count(string s, bool value, int begin, int end, vector<vector<vector<int> > >& num) {
  // Dynamic cases
  if (num[value][begin][end] != -1) {
    return num[value][begin][end];
  }
  
  // Base cases
  if (begin == end) {
    if (s[begin] == '1' && value) {
      return 1;
    } else if (s[begin] == '0' && !value) {
      return 1;
    }
    return 0;
  }

  // Normal cases
  int counter = 0;
  if (value) {
    for (int i = begin + 1; i <= end; i += 2) {
      if (s[i] == '&') {
        counter += count(s, true, begin, i - 1, num) * count(s, true, i + 1, end, num);
      } else if (s[i] == '^') {
        counter += count(s, true, begin, i - 1, num) * count(s, false, i + 1, end, num);
        counter += count(s, false, begin, i - 1, num) * count(s, true, i + 1, end, num);
      } else {
        counter += count(s, true, begin, i - 1, num) * count(s, true, i + 1, end, num);
        counter += count(s, true, begin, i - 1, num) * count(s, false, i + 1, end, num);
        counter += count(s, false, begin, i - 1, num) * count(s, true, i + 1, end, num);
      }
    }
  } else {
    for (int i = begin + 1; i <= end; i += 2) {
      if (s[i] == '&') {
        counter += count(s, false, begin, i - 1, num) * count(s, false, i + 1, end, num);
        counter += count(s, true, begin, i - 1, num) * count(s, false, i + 1, end, num);
        counter += count(s, false, begin, i - 1, num) * count(s, true, i + 1, end, num);
      } else if (s[i] == '^') {
        counter += count(s, true, begin, i - 1, num) * count(s, true, i + 1, end, num);
        counter += count(s, false, begin, i - 1, num) * count(s, false, i + 1, end, num);
      } else {
        counter += count(s, false, begin, i - 1, num) * count(s, false, i + 1, end, num);
      }
    }
  }

  num[value][begin][end] = counter;
  return counter;
}

int count(string s, bool value) {
  vector<vector<vector<int> > > 
    num(2, vector<vector<int> >(s.length(), vector<int>(s.length(), -1)));
  return count(s, value, 0, s.length() - 1, num);
}

int main() {
  string s;
  cin>>s;
  bool value;
  cin>>value;
  cout<<count(s, value)<<endl;

  return 0;
}
