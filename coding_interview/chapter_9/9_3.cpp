#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>
using namespace std;

int findIndex_1(vector<int> v) {
  int begin = 0, end = v.size() - 1;
  while (begin <= end) {
    int mid = (begin + end) / 2;
    if (v[mid] == mid) {
      return mid;
    } else if (v[mid] < mid) {
      begin = mid + 1;
    } else {
      end = mid - 1;
    }
  }
  return -1;
}

int findIndex_help(vector<int> v, int begin, int end) {
  if (begin > end || begin < 0 || end >= v.size()) {
    return -1;
  }

  int mid = (begin + end) / 2;
  if (v[mid] == mid) {
    return mid;
  }

  int leftIndex = min(mid - 1, v[mid]);
  int left = findIndex_help(v, begin, leftIndex);
  if (left != -1) {
    return left;
  }

  int rightIndex = max(mid + 1, v[mid]);
  int right = findIndex_help(v, rightIndex, end);
  if (right != -1) {
    return right;
  }

  return -1;
}

int findIndex_2(vector<int> v) {
  return findIndex_help(v, 0, v.size() - 1); 
}

int main() {
  int n;
  cin>>n;
  vector<int> v(n);
  for (int i = 0; i < n; i++) {
    cin>>v[i];
  }
  cout<<findIndex_2(v)<<endl;
}
