#include <iostream>
using namespace std;

void zeros(int** matrix, int rows, int cols) {
  bool first_row_zero = false;
  for (int i = 0; i < cols; i++) {
    if (matrix[0][i] == 0) {
      first_row_zero = true;
      break;
    }
  }

  bool first_col_zero = false;
  for (int i = 0; i < rows; i++) {
    if (matrix[i][0] == 0) {
      first_col_zero = true;
      break;
    }
  }

  for (int i = 1; i < rows; i++) {
    for (int j = 1; j < cols ; j++) {
      if (matrix[i][j] == 0) {
        matrix[i][0] = 0;
        matrix[0][j] = 0;
      }
    }
  }

  for (int i = 0; i < rows; i++) {
    if (matrix[i][0] == 0) {
      for (int j = 1; j < cols; j++) {
        matrix[i][j] = 0;
      }
    }
  }

  for (int j = 0; j < cols; j++) {
    if (matrix[0][j] == 0) {
      for (int i = 1; i < rows; i++) {
        matrix[i][j] = 0;
      }
    }
  }

  if (first_row_zero) {
    for (int i = 0; i < cols; i++) {
      matrix[0][i] = 0;
    }
  }

  if (first_col_zero) {
    for (int i = 0; i < rows; i++) {
      matrix[i][0] = 0;
    }
  }
}

int main() {
  int rows, cols;
  cin>>rows>>cols;
  int** matrix = new int*[rows];
  for (int i = 0; i < rows; i++) {
    matrix[i] = new int[cols];
  }

  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      cin>>matrix[i][j];
    }
  }

  zeros(matrix, rows, cols);

  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      cout<<matrix[i][j]<<" ";
    }
    cout<<endl;
  }
}
