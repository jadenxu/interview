#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <algorithm>
using namespace std;

void merge(vector<int>& A, vector<int>& B) {
  int cur_A = A.size() - 1, cur_B = B.size() - 1;
  int cur = A.size() + B.size() - 1;
  A.resize(A.size() + B.size());
  while (cur_B >= 0) {
    if (A[cur_A] > B[cur_B]) {
      A[cur--] = A[cur_A--];
    } else {
      A[cur--] = B[cur_B--];
    }
  }
}

void print_vector(vector<int>& v) {
  for (int i = 0; i < v.size(); i++) {
    cout<<v[i]<<" ";
  }
  cout<<endl;
} 

int main () {
  int size_A = 15, size_B = 10;
  vector<int> A(size_A), B(size_B);
  for (int i = 0; i < size_A; i++) {
    A[i] = rand() % 100;
  }
  for (int i = 0; i < size_B; i++) {
    B[i] = rand() % 100;
  }
  sort(A.begin(), A.end());
  print_vector(A);
  sort(B.begin(), B.end());
  print_vector(B);

  merge(A, B);
  print_vector(A);

  return 0;
}
