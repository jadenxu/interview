#include <iostream>
#include <vector>
using namespace std;

int findValue(vector<int>& v, int value) {
  int begin = 0, end = v.size() - 1, mid;
  while (begin <= end) {
    mid = (begin + end) / 2;
    if (v[mid] == value) {
      return mid;
    } 
    if (v[begin] < v[mid]) {
      if (value >= v[begin] && value < v[mid]) {
        end = mid - 1;
      } else {
        begin = mid + 1;
      }
    } else if (v[begin] > v[mid]){
      if (value > v[mid] && value <= v[end]) {
        begin = mid + 1;
      } else {
        end = mid - 1;
      }
    } else {
      if (v[mid] != v[high]) {
        low = mid + 1;
      } else {
        low++;
      }
    }
  }

  return -1;
}

int main() {
  int n;
  cin>>n;
  vector<int> v(n);
  for (int i = 0; i < n; i++) {
    cin>>v[i];
  }
  int value;
  cin>>value;
  cout<<findValue(v, value)<<endl;

  return 0;
}
