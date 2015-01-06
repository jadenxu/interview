#include <iostream>
#include <vector>
using namespace std;

int longest_increasing_sequence(vector<int> v) {
  vector<int> length(v.size(), 0);
  length[0] = 1;
  for (int i = 1; i < v.size(); i++) {
    for (int j = 0; j < i; j++) {
      if (v[j] < v[i]) {
        length[i] = max(length[i], length[j]);
      }
    }
    length[i]++;
  }

  return length[v.size() - 1];
}

int main () {
  int n;
  cin>>n;
  vector<int> v(n);
  for (int i = 0; i < n; i++) {
    cin>>v[i];
  }
  cout<<longest_increasing_sequence(v)<<endl;

  return 0;
}
