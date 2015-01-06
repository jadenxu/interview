#include <iostream>
#include <string>
#include <vector>
using namespace std;

int find(vector<string> v, string s) {
  int begin = 0, end = v.size() - 1, mid;
  while (begin <= end) {
    mid = (begin + end) / 2;
    
    // Deal with the empty string cases
    if (v[mid] == "") {
      int left = mid - 1, right = mid + 1;
      while (true) {
        if (left < begin && right > end) {
          return -1;
        }
        if (left >= begin && v[left] != "") {
          mid = left;
          break;
        }
        if (right <= end && v[right] != "") {
          mid = right;
          break;
        }
        left--; right++;
      }
    }
    
    if (s == v[mid]) {
      return mid;
    } else if (s < v[mid]) {
      end = mid - 1;
    } else {
      begin = mid + 1;
    }
  }

  return -1;
}

int main() {
  string v_array[11] = {"at", "", "", "", "ball", "", "", "", "cat", "", "yell"};
  vector<string> v(v_array, v_array + 11);
  for (int i = 0; i < v.size(); i++) {
    cout<<i<<" "<<v[i]<<endl;
  }
  string s;
  cin>>s;
  cout<<find(v, s)<<endl;

  return 0;
}
