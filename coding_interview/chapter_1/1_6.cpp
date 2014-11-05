#include <iostream>
using namespace std;

void rotate90(int** matrix, int n) {
  for (int layer = 0; layer < n / 2; layer++) {
    int first = layer;
    int last = n - 1 - layer;
    // CAUTION: here is i < last, not <=
    // <= will cause the corner rotate twice
    for (int i = first; i < last; i++) {
      int offset = i - first;
      // record the top
      int tmp = matrix[first][i];

      // left to top
      matrix[first][i] = matrix[last - offset][first];

      // bottom to left
      matrix[last - offset][first] = matrix[last][last - offset];

      // right to bottom
      matrix[last][last - offset] = matrix[i][last];

      // left to right
      matrix[i][last] = tmp;
    }
  }
}

int main() {
  int n;
  cin>>n;
  
  int** matrix = new int*[n];
  for (int i = 0; i < n; i++) {
    matrix[i] = new int[n];
  }

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cin>>matrix[i][j];
    }
  }
  cout<<endl;

  rotate90(matrix, n);
  
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cout<<matrix[i][j]<<" ";
    }
    cout<<endl;
  }

  return 0;
}
