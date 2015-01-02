#include <iostream>
#include <vector>
using namespace std;

int numPaths(int x, int y) {
  vector<vector<int> > paths(x, vector<int>(y, 0));
  for (int i = 0; i < y; i++) {
    paths[0][i] = 1;
  } 
  for (int i = 0; i < x; i++) {
    paths[i][0] = 1;
  }
  for (int i = 1; i < x; i++) {
    for (int j = 1; j < y; j++) {
      paths[i][j] = paths[i - 1][j] + paths[i][j - 1];
    }
  }

  return paths[x - 1][y - 1];
}

int numPaths(vector<vector<int> > grid) {
  if (grid[0][0]) {
    return 0;
  }

  int x = grid.size(), y = grid[0].size(); 
  vector<vector<int> > paths(x, vector<int>(y, 0));
  paths[0][0] = 1;
  for (int i = 1; i < y; i++) {
    if (grid[0][i] == 0) {
      paths[0][i] = paths[0][i - 1];
    }
  }
  for (int i = 1; i < x; i++) {
    if (grid[i][0] == 0) {
      paths[i][0] = paths[i - 1][0];
    }
  }
  for (int i = 1; i < x; i++) {
    for (int j = 1; j < y; j++) {
      if (grid[i][j] == 0) {
        paths[i][j] = paths[i - 1][j] + paths[i][j - 1];
      }
    }
  }

  return paths[x - 1][y - 1];
}

int main() {
  int x, y;
  cin>>x>>y;
  cout<<numPaths(x, y)<<endl;

  return 0;
}
