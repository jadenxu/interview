#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>
using namespace std;

#define Point pair<int, int>

Point find_1(vector<vector<int> >& grid, int value) {
  int row = 0, col = grid[0].size() - 1;
  while (row < grid.size() && col >= 0) {
    if (grid[row][col] == value) {
      return Point(row, col);
    } else if (grid[row][col] < value) {
      row++;
    } else {
      col--;
    }
  }

  return Point(-1, -1);
}

Point find_help(vector<vector<int> >& grid, int value, Point origin, Point dest) {
  if (origin.first < 0 || origin.first >= grid.size() || 
      origin.second < 0 || origin.second >= grid[0].size()) {
    return Point(-1, -1);
  }
  if (dest.first < 0 || dest.first >= grid.size() || 
      dest.second < 0 || dest.second >= grid[0].size()) {
    return Point(-1, -1);
  } 
  if (origin.first > dest.first || origin.second > dest.second) {
    return Point(-1, -1);
  }
  
  Point begin = origin;
  int dist = min(dest.first - begin.first, dest.second - begin.second);
  Point end(begin.first + dist, begin.second + dist);
  while (begin.first <= end.first && begin.second <= end.second) {
    Point mid((begin.first + end.first) / 2, (begin.second + end.second) / 2);
    if (grid[mid.first][mid.second] == value) {
      return mid;
    } else if (value < grid[mid.first][mid.second]) {
      end.first = mid.first - 1;
      end.second = mid.second - 1;
    } else {
      begin.first = mid.first + 1;
      begin.second = mid.second + 1;
    }
  }
  
  Point left_pos = find_help(
    grid, value, 
    Point(begin.first, origin.second), Point(dest.first, begin.second - 1));
  if (left_pos != Point(-1, -1)) {
    return left_pos;
  }
  
  Point right_pos = find_help(
    grid, value, 
    Point(origin.first, begin.second), Point(begin.first - 1, dest.second));
  return right_pos;
}

Point find_2(vector<vector<int> >& grid, int value) { 
  return find_help(grid, value, Point(0, 0), Point(grid.size() - 1, grid[0].size() - 1));
}

int main() {
  int row, col;
  cin>>row>>col;
  vector<vector<int> > grid(row, vector<int>(col, 0));
  
  srand(time(0));
  for (int i = 1; i < row; i++) {
    grid[i][0] = grid[i - 1][0] + rand() % 10 + 1;
  }
  for (int i = 1; i < col; i++) {
    grid[0][i] = grid[0][i - 1] + rand() % 10 + 1;
  }
  for (int i = 1; i < row; i++) {
    for (int j = 1; j < col; j++) {
      grid[i][j] = max(grid[i][j - 1], grid[i - 1][j]) + rand() % 10 + 1;     
    }
  }

  for (int i = 0; i < row; i++) {
    for (int j = 0; j < col; j++) {
      cout<<grid[i][j]<<" ";
    }
    cout<<endl;
  }

  int value;
  cin>>value;
  Point pos_1 = find_1(grid, value);
  Point pos_2 = find_2(grid, value);
  cout<<pos_1.first<<" "<<pos_1.second<<endl;
  cout<<pos_2.first<<" "<<pos_2.second<<endl;

  return 0;
}
